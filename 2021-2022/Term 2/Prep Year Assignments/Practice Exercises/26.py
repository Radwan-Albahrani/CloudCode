# Write a python code to get the sum of all numbers divided by 4 between 10 and 50.

# Prepare sum
sum = 0

# Loop 10 to 50 and find sum of all numbers divided by 4
for i in range(10, 50 + 1):
    if i % 4 == 0:
        sum += i

# Print it
print(f"The sum of all numbers between 10 and 50 divisible by 4 is: {sum}")


