# Write a python program that reads two number values (major radius of ellipse(a), and minor radius of ellipse(b)) 
# from the user, calculates the area of the ellipse, and prints it. Use try and except to print an error message if the user enters any string value.
# Equation: Area of ellipse = Pi * a * b (where Pi is a constant, import it from the math module.)
# Note: Use try and except to print an error message if the user enters any string value.

#Import math
import math

# Get two numbers from the user
try:
    major, minor = input("Enter the major radius and the minor radius of the ellipse: ").split()
    major = int(major)
    minor = int(minor)
    
    # Get area and use it.
    result = math.pi * major * minor
    print(f"The area of the ellipse is: {result}")

# Make sure its a number
except ValueError:
    print("Must be two numbers separated by a space!")

