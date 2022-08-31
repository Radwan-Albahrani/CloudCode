# Write a python code to get the maximum number between 5 numbers.

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

# Set max to a high number
max = -99999999999

# Compare all given numbers to max
for number in numbers:
    if number > max:
        max = number

# Print max
print(f"Largest Number is: {max}")