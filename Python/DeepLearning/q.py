import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split, cross_val_score
from sklearn.preprocessing import StandardScaler
from sklearn.tree import DecisionTreeClassifier
from sklearn.metrics import accuracy_score, classification_report, confusion_matrix

def load_data():
    """Load the Iris dataset."""
    iris = load_iris()
    X = iris.data
    y = iris.target
    return X, y

def preprocess_data(X):
    """Normalize the features."""
    scaler = StandardScaler()
    return scaler.fit_transform(X)

def split_data(X, y, test_size=0.2, random_state=42):
    """Split the data into training and testing sets."""
    return train_test_split(X, y, test_size=test_size, random_state=random_state)

def train_model(X_train, y_train):
    """Train the Decision Tree Classifier."""
    model = DecisionTreeClassifier(random_state=42)
    model.fit(X_train, y_train)
    return model

def evaluate_model(model, X_test, y_test):
    """Evaluate the model and print metrics."""
    y_pred = model.predict(X_test)
    accuracy = accuracy_score(y_test, y_pred)
    print(f'Test Accuracy: {accuracy:.4f}')
    print("Classification Report:")
    print(classification_report(y_test, y_pred))
    return y_test, y_pred

def plot_confusion_matrix(y_test, y_pred):
    """Plot the confusion matrix."""
    cm = confusion_matrix(y_test, y_pred)
    plt.figure(figsize=(8, 6))
    sns.heatmap(cm, annot=True, fmt='d', cmap='Blues', xticklabels=np.unique(y_test), yticklabels=np.unique(y_test))
    plt.xlabel('Predicted')
    plt.ylabel('True')
    plt.title('Confusion Matrix')
    plt.show()

def main():
    # Load and preprocess data
    X, y = load_data()
    X = preprocess_data(X)

    # Split the data
    X_train, X_test, y_train, y_test = split_data(X, y)

    # Train the model
    model = train_model(X_train, y_train)

    # Evaluate the model
    y_test, y_pred = evaluate_model(model, X_test, y_test)

    # Plot confusion matrix
    plot_confusion_matrix(y_test, y_pred)

    # Cross-validation
    cv_scores = cross_val_score(model, X, y, cv=5)
    print(f'Cross-Validation Accuracy: {np.mean(cv_scores):.4f} ± {np.std(cv_scores):.4f}')

if __name__ == "__main__":
    main()