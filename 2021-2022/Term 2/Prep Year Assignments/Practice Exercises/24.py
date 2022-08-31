# Write a Python program that accepts an integer (n) between 1 and 9 then computes the value of n+nn+nnn.

# Get number and make sure its a number within parameters
parsed = False
while not parsed:
    try:
        number = int(input("Enter a number between 1 and 9: "))
        if number < 1 or number > 9:
            print("Number must be between 1 and 9")
            continue
        parsed = True
    except:
        print("Must be a number")

# Print result
print(f"{number} + ({number} x {number}) + ({number} x {number} x {number}) = {number + (number * number) + (number * number * number)}")