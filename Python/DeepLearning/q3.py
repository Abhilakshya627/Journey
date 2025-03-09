# Build a Deep Neural Network by implementing back propogation and test same using appropriate linearly seperable dataset.Use atleast 4 hidden layers taking 70% of the data for testing and 30% for training with around 100 epochs and relu activation function and sgd optimizer.

# Importing the required libraries
from sklearn.model_selection import train_test_split
from sklearn.datasets import make_blobs
from keras.models import Sequential
from keras.layers import Dense
from keras.optimizers import SGD
import matplotlib.pyplot as plt

# Generating the dataset
x, y = make_blobs(n_samples=1000, centers=2, n_features=4, random_state=42)

# Splitting the dataset into training and testing data
x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.7, random_state=42)

# Creating the neural network model
model = Sequential()
model.add(Dense(64, activation='relu', input_shape=(4,)))
model.add(Dense(32, activation='relu'))
model.add(Dense(16, activation='relu'))
model.add(Dense(8, activation='relu'))
model.add(Dense(1, activation='sigmoid'))

# Compiling the model
model.compile(optimizer=SGD(learning_rate=0.01), loss='binary_crossentropy', metrics=['accuracy'])

# Training the model
model.fit(x_train, y_train, epochs=100)

# Predicting the output
y_pred = model.predict(x_test)

# Calculating the accuracy of the model
accuracy = model.evaluate(x_test, y_test)
print("Accuracy of the model:", accuracy)

# Output
plt.scatter(x[:,0], x[:,1], c=y)
plt.xlabel('Feature 1')
plt.ylabel('Feature 2')
plt.title('Linearly Separable Dataset')
plt.show()