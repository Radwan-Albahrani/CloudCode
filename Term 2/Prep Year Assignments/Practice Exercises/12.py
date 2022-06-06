# Write a python program that takes two numbers from the user (low and high) and 
# calculates the sum of all even numbers between the low and high numbers, and prints both the sum and count of these even numbers using loop.

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

# Prepare sum and count
sum = 0
count = 0

# Get sum and count
for i in range(low, high + 1):
    if i % 2 == 0:
        sum += i
        count += 1
# Print sum and count
print(f"Sum of all even numbers between {low} and {high} is: {sum}")
print(f"Number of even numbers between {low} and {high} is: {count}")