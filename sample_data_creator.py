import pandas as pd
import numpy as np

# Generate synthetic data
np.random.seed(42)  # For reproducibility

# Example features: age, income, education
num_samples = 1000
age = np.random.randint(20, 60, size=num_samples)
income = np.random.normal(50000, 10000, size=num_samples)
education_levels = ['High School', 'Bachelor', 'Master', 'PhD']
education = np.random.choice(education_levels, size=num_samples)

# Example target variable: 0 for low income, 1 for high income
target = np.where(income > np.median(income), 1, 0)

# Create a DataFrame
data = pd.DataFrame({'age': age, 'income': income, 'education': education, 'target': target})

# Save DataFrame to CSV
data.to_csv('data.csv', index=False)
