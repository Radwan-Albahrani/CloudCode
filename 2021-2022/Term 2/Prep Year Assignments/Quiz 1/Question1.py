# Check value
parsed = False

# Loop until user enters a number that passes the check
while not parsed:
    try:
        age = float(input("Enter Your age: "))
        if age < 0:
            print("Age must be Positive!")
            continue
        parsed = True
    except ValueError:
        print("Age must be a number!")

# Multiply age by days in a year
age_in_days = age * 365

# Print age in days
print("Your age is: ", age_in_days, "in Days")