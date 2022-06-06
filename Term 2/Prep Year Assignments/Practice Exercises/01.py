# Write a python program that asks the user to enter two positive numbers (n1, n2) and calculate and display the following using appropriate built-in functions:
# 1. square root for (n1)
# 2. (n1) power of (n2)
# Note: Use try and except to print an error message if the user enters any negative value. 

# Import Math
import math

# Variable for making sure input is correct
parsed = False

# Loop
while not parsed:
    # Try to get two numbers from the user
    try:
        n1, n2 = input("Enter two Numbers: ").split()
        n1 = int(n1)
        n2 = int(n2)

        # Make sure the numbers are not negatice
        if n1 < 0 or n2 < 0:
            print("Numbers Cannot be Negative.")
            continue
        parsed = True
    # Make sure the numbers are numbers not strings
    except ValueError:
        print("Must be only TWO numbers separated by a space.")
# Print the square root of the first number
print(f"Square root of {n1} = {math.sqrt(n1)}")

# Print the first number to the power of the second number
print(f"{n1} raised to the power of {n2} = {math.pow(n1, n2)}")