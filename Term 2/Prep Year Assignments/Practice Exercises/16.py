# Write a python program that calculates and prints the square root of the even numbers in 
# the list 4,9,12,16,64,72,63,81 using for loop. Use an appropriate built-in function for calculating the square root.
# Write a python program that calculates and prints the square root of the odd numbers in the 
# list 4,9,12,16,64,72,63,81 using for loop. Use an appropriate built-in function for calculating the square root. 

# Import math
import math
# Put number list
numberList = [4,9,12,16,64,72,63,81]

# Get square root of even numbers
for i in numberList:
    if i % 2 == 0:
        print(f"Square root of Even number {i} is {math.sqrt(i)}")

# Get square root of odd numbers
for i in numberList:
    if i % 2 != 0:
        print(f"Square root of Odd number {i} is: {math.sqrt(i)}")
