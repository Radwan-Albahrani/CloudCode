# Write a python program that asks the user to enter their name, 
# find and print the largest character in the name, and the total length of the name using appropriate built-in functions.
# Note: Use try and except to print an error message if the user enters any numeric value.


# Try to get string. If its an int, tell the user
try:
    name = input("Enter your name: ")
    name = int(name)
    if type(name) == int:
        print("Must be a String")
except ValueError:
    print("Name accepted.")

# Find the max and length of the string
print(f"Biggest character in the name: {max(name)}")
print(f"Length of the name: {len(name)}")