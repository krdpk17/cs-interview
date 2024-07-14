''''
Pre-requisite
1. pip install mlflow
2. mlflow server -> For viewing mlflow UI..
    Load http://localhost:5000/

'''
import mlflow
import mlflow.sklearn
from sklearn.ensemble import RandomForestClassifier
from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split

# Load data
iris = load_iris()
X = iris.data
y = iris.target

# Split data
X_train, X_test, y_train, y_test = train_test_split(X, y)

# Start MLflow run
with mlflow.start_run():

    # Train model
    model = RandomForestClassifier()
    model.fit(X_train, y_train)

    # Log parameters and metrics
    mlflow.log_params({'n_estimators': model.n_estimators})
    mlflow.log_metric('accuracy', model.score(X_test, y_test))

    # Save model
    mlflow.sklearn.log_model(model, 'random_forest_model')
