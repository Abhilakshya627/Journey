'''Design and implement a single unit preceptron of a linearly separable dataset using Preceptron() from sklearn'''
from sklearn.datasets import load_iris
from sklearn.linear_model import Perceptron
from sklearn.preprocessing import StandardScaler
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score,confusion_matrix,classification_report

# Load the Iris dataset
iris = load_iris()
X = iris.data[:, :2]  # We take only the first two features for 2D visualization
y = (iris.target != 0).astype(int)  # Binary classification: Setosa (0) vs. others (1)

# Standardize the features for better performance
scaler = StandardScaler()
X = scaler.fit_transform(X)

#Splitting the data
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2,random_state=40)

# Initialize and fit the Perceptron model
perceptron = Perceptron(max_iter=1000, eta0=0.01, random_state=42)
perceptron.fit(X_train, y_train)
pred_test=perceptron.predict(X_test)

cm=confusion_matrix(y_test,pred_test)
print(cm)
cr=classification_report(y_test,pred_test)
print(cr)

# Evaluate model accuracy
accuracy = perceptron.score(X, y)
print(f"Model Accuracy: {accuracy * 100:.2f}%")