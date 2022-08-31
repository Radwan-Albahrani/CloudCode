# Write a python program that takes two numbers from the user (low and high) and 
# calculates a random integer between the low and high numbers using an appropriate built-in function. 
# Print three different random numbers generated as above.
# Note: Use try and except to print an error message if the user enters any string value.
import random

# Make sure we get correct input
Parsed = False

# Loop
while not Parsed:
    # Ensure you get two numbers that are integers and low is lower than high
    try:
        low, high = input("Enter Low boundary and High Boundary Separated by a space: ").split()
        low = int(low)
        high = int(high)
        if low > high:
            print("First number MUST BE Smaller than the second number!")
            continue
        Parsed = True
    # Error if string
    except ValueError:
        print("Must be Numbers separated by a space!")

# Print three random numbers
print(f"Three generated numbers from {low} to {high} are: {random.randint(low, high)} {random.randint(low, high)} {random.randint(low, high)}")