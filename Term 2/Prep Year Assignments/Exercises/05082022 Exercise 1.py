import string

# Function to find palindromes
def isPalindrom(testString):
    # Identify it as a string
    testString = str(testString)

    # Clean string by lowering, removing spaces, removing punctuations
    testString = testString.lower()
    testString = testString.replace(" ", "")
    testString = testString.translate(str.maketrans('', '', string.punctuation))

    # Get start and end of string
    start = range(len(testString))
    end = reversed(start)

    # Loop through from beginning and end simultaneously and start comparing
    for i, j in zip(start, end):
        if testString[i] == testString[j]:
            pass
        elif i == j or i > j:
            break
        else:
            print("String not a palindrom")
            return
    print("String is a palindrom")


isPalindrom("Amore, Roma")