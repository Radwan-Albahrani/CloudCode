# Main Function, This will start the program
def main():
    # Welcome the user and get the string
    print("Welcome to the String Analyzer")
    userString = input("Enter a string: ")
    mainMenu(userString)

# Main Menu after getting the string


def mainMenu(userString: str):
    # Either getting the String length or calculating the letters and digits
    print("Select from the following options:")
    print("1. Check String Length")
    print("2. Calculate digits and letters i string")

    # Getting choice and applying the functions
    userChoice = input("Enter your choice: ")

    if userChoice == "1":
        print(checkLength(userString))
    elif userChoice == "2":
        print(calculateDigitsAndLetters(userString))
    else:
        print("Invalid Choice")

# Function to ensure length is between 8 and 16


def checkLength(givenString: str) -> str:
    if len(givenString) > 8 and len(givenString) < 16:
        return "String Length is OK"
    else:
        return "Invalid String Length"

# Function to return a dictionary containing letters and digits


def calculateDigitsAndLetters(givenString: str) -> dict:
    digits = 0
    letters = 0
    for i in givenString:
        if i.isdigit():
            digits += 1
        elif i.isalpha():
            letters += 1
    return {"digits": digits, "letters": letters}


if __name__ == "__main__":
    main()
