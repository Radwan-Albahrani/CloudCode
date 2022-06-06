# Write a Python program to get a new string from a given string where 
# "Is" has been added to the front. If the given string already begins with "Is" then return the string unchanged

# Get string
string = input("Enter a string: ")

# Check if ls exists at the beginning of string. if not, add it
if string[0:2].lower() != "ls":
    string = "ls" + string

# Print new string
print(string)