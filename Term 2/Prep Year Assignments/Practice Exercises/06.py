# Write a python program that asks the user to enter the color of the traffic light 
# (red, yellow, green), and then print stop, slowdown, or go based on the user input.
# Note: If a user enters any other color for the traffic light, print an error message.

# Get light color from the user
lightColor = input("Enter the color of the traffic light (Red, Yellow, Green): ")

# Print correct output based on color
if lightColor.lower() == "red":
    print("Stop")
elif lightColor.lower() == "yellow":
    print("Slow down")
elif lightColor.lower() == "green":
    print("Go")
else:
    print("Error. Not a traffic light color.")