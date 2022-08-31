# Write a Python program to reverse a string

# Function to reverse string
def ReverseString(string):
    # Prepare new string
    newString = ""
    # loop through string
    for i in range(len(string)):
        # Get last letter by letter and add it to new string
        newString += string[len(string) - i - 1]
    # Return new string
    return newString

# Get string from user and reverse it
string = input("Enter String you want to reverse: ")
string = ReverseString(string)

# Print results
print(f"Reversed String: {string}")
