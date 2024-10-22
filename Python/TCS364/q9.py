# Define the range
start = 108
end = 508

# Use a for loop to iterate over the range
for num in range(start, end + 1):
    # Check if the number is a multiple of 5
    if num % 5 == 0:
        print(num)