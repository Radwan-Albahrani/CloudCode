# Write a python program that repeatedly reads odd numbers until the user enters 0. Once 0 is entered, 
# print out the sum of the odd numbers. If the user enters any even number, your program should ignore it.
# For example:
# Enter an int value: 5
# Enter an int value: 7
# Enter an int value: 10
# Enter an int value: 0
# The sum is 12

# Prep Variables
number = 1
sum = 0

# Loop Until 0. Every odd number add it to sum
while number != 0:
    number = int(input("Enter an Int Value: "))
    if number % 2 != 0:
        sum += number

# Print sum
print(f"Sum of all odd numbers entered is: {sum}")