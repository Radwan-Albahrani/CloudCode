# Getting correct input value
parsed = False
while not parsed:
    try:
        Grade = float(input("Enter your Score: "))
        parsed = True
    except ValueError:
        print("Must be a Number.")

# Rounding Grade
Grade = round(Grade)

# Getting Proper Score
match Grade:
    case Grade if Grade >= 95:
        Score = "A+"
    case Grade if Grade >= 90 and Grade < 95:
        Score = "A"
    case Grade if Grade >= 85 and Grade < 90:
        Score = "B+"
    case Grade if Grade >= 80 and Grade < 85:
        Score = "B"
    case Grade if Grade >= 75 and Grade < 80:
        Score = "C+"
    case Grade if Grade >= 65 and Grade < 70:
        Score = "C"
    case Grade if Grade >= 65 and Grade < 70:
        Score = "D+"
    case Grade if Grade >= 60 and Grade < 65:
        Score = "D"
    case Grade if Grade < 60:
        Score = "F"

# Printing Answer
print(f"Your Grade is: {Score}")