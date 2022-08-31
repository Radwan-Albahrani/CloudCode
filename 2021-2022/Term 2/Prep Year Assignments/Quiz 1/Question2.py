# Check value
parsed = False

# Loop until user enters a number that passes the check
while not parsed:
    try:
        mark = float(input("Enter Your Mark in English: "))
        if mark < 0:
            print("Mark must be Positive!")
            continue
        parsed = True
    except ValueError:
        print("Mark must be a number!")

# Validate mark and print proper level (note, only works in python 3.10 and above)
match(mark):
    case mark if mark >= 90:
        print("Your level is Advanced!")
    case mark if mark >= 75:
        print("Your level is Intermediate!")
    case mark if mark < 75:
        print("Your level is Beginner!")
