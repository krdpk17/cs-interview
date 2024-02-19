'''
Pre-requisite
    pip install h2o

'''
import mlflow
import mlflow.sklearn
import pandas as pd
from sklearn.model_selection import train_test_split
import h2o
from h2o.automl import H2OAutoML

# Load data
data = pd.read_csv("data.csv")

# Split data into train and test sets
train, test = train_test_split(data, test_size=0.2)

# Initialize MLflow
mlflow.set_tracking_uri("http://localhost:5000")
mlflow.set_experiment("auto_ml_experiment")

# Start MLflow run
with mlflow.start_run():
    # Log parameters
    mlflow.log_param("dataset", "data.csv")
    
    # Initialize H2O
    h2o.init()
    
    # Convert pandas DataFrame to H2OFrame
    train_h2o = h2o.H2OFrame(train)
    test_h2o = h2o.H2OFrame(test)
    
    # Define input and target variables
    x = train_h2o.columns
    y = "target"
    
    # Run AutoML
    automl = H2OAutoML(max_models=10, seed=42)
    automl.train(x=x, y=y, training_frame=train_h2o)
    
    # Get best model
    best_model = automl.leader
    
    # Evaluate model on test set
    predictions = best_model.predict(test_h2o)
    accuracy = 0
    try:
        accuracy = (predictions["predict"] == test_h2o[y]).mean()
    except ValueError:
        print("Accuracy value is not numeric:", accuracy)
    
    # Log metrics
    mlflow.log_metric("accuracy", accuracy[0])
    
    # Log model
    mlflow.sklearn.log_model(best_model, "auto_ml_model")
    
    # Save the AutoML leaderboard
    leaderboard = automl.leaderboard.as_data_frame()
    leaderboard.to_csv("auto_ml_leaderboard.csv", index=False)
    mlflow.log_artifact("auto_ml_leaderboard.csv")

# End MLflow run
mlflow.end_run()
