# Write a python program that takes the total sales of the product as input and prints the classification according to the following table:
# Total_Sales	classification
# >=100000	    High sales
# >=75000	    Medium sales
# <75000	    Low sales
 
# Note:  Use try and except to print an error message if the user enters any string value.
# Make sure number is correct
parsed = False

# Loop
while not parsed:
    # Get sales from user
    try:
        sales = int(input("Enter your total Sales: "))

        # Make sure sales is in appropriate parameters
        if sales < 0:
            print("Must be bigger than 0")
            continue
        parsed = True
    # Make sure sales is integer
    except ValueError:
        print("Must be a number.")

# Print appropriate level
if sales >= 100000:
    print("High Sales")
elif sales >= 75000:
    print("Medium Sales")
else:
    print("Low Sales")