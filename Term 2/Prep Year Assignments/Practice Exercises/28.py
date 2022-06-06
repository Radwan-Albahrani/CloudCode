# Write a Python function that takes a list and returns a new list with unique elements of the first list.

# Function
def Unique(elements):
    # Start a unique list
    uniqueList = []
    # Loop through given list
    for i in elements:
        # if new element, add it to unique list
        if i not in uniqueList:
            uniqueList.append(i)
    # Return unique list
    return uniqueList

# Get list of stuff from user
oldList = input("Enter a bunch of elements separates by a space: ").split()

# Make it unique
oldList = Unique(oldList)

# Print it
print(f"elements after cleaning repeated items: {oldList}")