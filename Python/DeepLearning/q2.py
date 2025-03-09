# Design and implement an artificial neural network using back propogation algorithm on a lineraly seperable dataset. Use various activation functions and compare the results of this neural network.

# Importing the required libraries
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler, OneHotEncoder
from sklearn.datasets import load_iris
from sklearn.metrics import accuracy_score
from keras.models import Sequential
from keras.layers import Dense, Input
from keras.optimizers import Adam
import numpy as np
import matplotlib.pyplot as plt

def Load_data():
    # Loading the iris dataset
    iris = load_iris()
    x = iris.data
    y = iris.target

    # Scaling the data and one hot encoding the target variable
    scaler = StandardScaler()
    x = scaler.fit_transform(x)
    encoder = OneHotEncoder(sparse_output=False)  # Use sparse_output=False to get a dense array
    y = encoder.fit_transform(y.reshape(-1, 1))

    # Splitting the dataset into training and testing data
    x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.2, random_state=48)
    return x_train, x_test, y_train, y_test

def create_Model(activation_function):
    # Creating the neural network model
    model = Sequential()
    model.add(Input(shape=(4,)))  # Use Input layer for the input shape
    model.add(Dense(10, activation=activation_function))
    model.add(Dense(3, activation='softmax'))  # Use softmax for multi-class classification
    # Compiling the model
    model.compile(optimizer=Adam(learning_rate=0.01), loss='categorical_crossentropy', metrics=['accuracy'])
    return model

def train_Model(activation_function, name):
    print(f'Training model with {name} activation function')
    # Loading the dataset
    x_train, x_test, y_train, y_test = Load_data()
    # Creating the neural network model
    model = create_Model(activation_function)
    # Training the model
    model.fit(x_train, y_train, epochs=100, batch_size=8, verbose=0)  # Set verbose=0 to suppress output
    # Predicting the output
    y_pred = model.predict(x_test)
    y_pred_classes = np.argmax(y_pred, axis=1)  # Get the predicted class
    y_test_classes = np.argmax(y_test, axis=1)  # Get the true class
    # Calculating the accuracy of the model
    accuracy = accuracy_score(y_test_classes, y_pred_classes)
    print("Accuracy of the model with ", name, " activation function: ", accuracy)
    return accuracy

accuracy = {}
for activation in ['relu', 'tanh', 'sigmoid']:
    accuracy[activation] = train_Model(activation, activation)

# Output
plt.bar(accuracy.keys(), accuracy.values())
plt.xlabel('Activation Function')
plt.ylabel('Accuracy')
plt.title('Comparison of Activation Functions')
plt.ylim(0, 1)  # Set y-axis limits for better visualization
plt.show()