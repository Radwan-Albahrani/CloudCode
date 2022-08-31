# Write a python code to enter a string, then print all the string’s letters except ‘a’ and ‘e’.

# Get string
string = input("Enter a String: ")

# Prep new string
stringNew = ""

# Remove all A and E in string
for i in string:
    if i.lower() == 'a' or i.lower() == 'e':
        pass
    else:
        stringNew += i

# Print new string without A or E
print(stringNew)