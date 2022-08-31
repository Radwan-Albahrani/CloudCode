# Write a python program that reads three numbers (integer or float) from the user, finds the smallest number between the three numbers, and prints it.
# Note: Use try and except to print an error message if the user enters any string value.


# Make sure number is correct
parsed = False

# Loop
while not parsed:
    # Get numbers from user
    try:
        numbers = []
        stringNumbers = input("Enter Three Numbers, separated by a space: ").split()
        for number in stringNumbers:
            numbers.append(int(number))
        parsed = True
    # Make sure Age is integer
    except ValueError:
        print("Must be a number.")

# Set min to a high number
min = 99999999999

# Compare all given numbers to min
for number in numbers:
    if number < min:
        min = number

# Print min
print(f"Smallest Number is: {min}")