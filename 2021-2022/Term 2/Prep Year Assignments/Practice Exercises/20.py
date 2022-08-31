# Write a python program that repeatedly reads even numbers until the user enters 0. Once 0 is entered, 
# print out the sum of the even numbers. If the user enters any odd number, your program should ignore it.
# For example:
# Enter an int value: 4
# Enter an int value: 8
# Enter an int value: 11
# Enter an int value: 0
# The sum is 12


# Prep Variables
number = 1
sum = 0

# Loop Until 0. Every Even number add it to sum
while number == 0:
    number = int(input("Enter an Int Value: "))
    if number % 2 == 0:
        sum += number

# Print sum
print(f"Sum of all Even numbers entered is: {sum}")