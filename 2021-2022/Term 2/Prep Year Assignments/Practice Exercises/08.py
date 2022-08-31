# Write a python program that takes the total marks in English as input and prints the level in English according to the following table:
# Total_marks	Level
# >=90	        Advanced
# >=75	        Intermediate
# <75	        Beginner
 
# Note:  Use try and except to print an error message if the user enters any string value.

# Make sure number is correct
parsed = False

# Loop
while not parsed:
    # Get grade from user
    try:
        grade = int(input("Enter your total marks in english: "))

        # Make sure grade is in appropriate parameters
        if grade < 0 or grade > 100:
            print("Must be between 0 and 100")
            continue
        parsed = True
    # Make sure grade is integer
    except ValueError:
        print("Must be a number.")

# Print appropriate level
if grade >= 90:
    print("Advanced")
elif grade >= 75:
    print("Intermediate")
else:
    print("Beginner")