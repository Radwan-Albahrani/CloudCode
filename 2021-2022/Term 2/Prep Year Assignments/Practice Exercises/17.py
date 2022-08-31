# Write a python program that calculates and prints the square of the even numbers in 
# the list 4,9,12,16,64,72,63,81 using for loop. Use an appropriate built-in function to calculate the square.

# Import math
import math

# Put number list
numberList = [4,9,12,16,64,72,63,81]

# Get square of even numbers
for i in numberList:
    if i % 2 == 0:
        print(f"Square root of Even number {i} is {math.pow(i, 2)}")

