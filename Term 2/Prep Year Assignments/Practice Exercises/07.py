# Write a python program to ask the user to enter a number from 1 to 3 and display the name of the month respectively. For example, if the user enters 1 
# the month displayed should be January, and so on. If the user enters any other number than 1 to 3, display an error message.

# Get Month number from the user
Month = input("Enter the Number of the month (1, 2 ,3): ")

# Print correct output based on month number
if Month == "1":
    print("January")
elif Month == "2":
    print("February")
elif Month == "3":
    print("March")
else:
    print("Error. Number not in appropriate range.")