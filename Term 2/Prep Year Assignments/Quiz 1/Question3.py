# Check value
parsed = False

# Loop until user enters a number that passes the check
while not parsed:
    try:
        lowerBound = int(input("Enter Lower Bound: "))
        parsed = True
    except ValueError:
        print("Lower Bound must be a number!")

# Check second value
parsed = False

# Loop until user enters proper second value
while not parsed:
    try:
        UpperBound = int(input("Enter Upper Bound: "))
        if UpperBound < lowerBound:
            print("Upper bound must be higher than lower bound!")
            continue
        parsed = True
    except ValueError:
        print("Upper Bound must be a number!")

# Prepare sum and count for average
sum = 0
count = 0.0

# Use loop to get all even numbers, including upper bound
for i in range(lowerBound, UpperBound + 1):
    if i % 2 == 0:
        sum += i
        count += 1

# Print results
print(f"The sum of all even numbers between {lowerBound} and {UpperBound} is {sum}")
print(f"The Average of these numbers is {sum/count}")