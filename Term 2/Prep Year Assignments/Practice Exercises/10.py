# Write a python program that takes the user age as 
# input and prints the classification according to the following table:
# Age	classification
# >=18	Eligible to donate blood
# >65	Too old to donate blood
# <18	Too young to donate blood
 
# Note: Use try and except to print an error message if the user enters any negative value.

# Make sure number is correct
parsed = False

# Loop
while not parsed:
    # Get Age from user
    try:
        Age = int(input("Enter your Age: "))

        # Make sure Age is in appropriate parameters
        if Age < 0:
            print("Must be bigger than 0")
            continue
        parsed = True
    # Make sure Age is integer
    except ValueError:
        print("Must be a number.")

# Print appropriate Eligibility
if Age > 65:
    print("Too old to donate blood")
elif Age >= 18:
    print("Eligible to donate blood")
else:
    print("Too young to donate blood")