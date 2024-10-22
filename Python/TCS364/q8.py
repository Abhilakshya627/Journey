# Initialize variables
total = 0
count = 0

# Use a while loop to get 6 numbers from the user
while count < 6:
    num = float(input("Enter a number: "))
    total += num
    count += 1

# Calculate the mean
mean = total / 25  # as per your request, it's 25, but it should be the total count of numbers

# Print the result
print("The mean is: ", mean)