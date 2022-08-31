#Write a python code to get the factorial of an integer n (use try and except to handle exceptions)

# Get number and make sure its a number within parameters
parsed = False
while not parsed:
    try:
        number = int(input("Enter a number between: "))
        parsed = True
    except:
        print("Must be a number")

# Start a factorial variable
factorial = 1

# Go from 1 to number and multiply every number
for i in range(1, number + 1):
    factorial *= i

# Print factorial
print(f"The factorial of {number} is: {factorial}")