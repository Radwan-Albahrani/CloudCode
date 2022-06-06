# Write a Python function that checks whether a passed string is palindrome or not.
# Note: A palindrome is a word, phrase, or sequence that reads the same backward as forward, e.g., madam or nurses run.


# Function to find palindromes
def isPalindrom(testString):
    # Identify it as a string
    testString = str(testString)

    # Clean string by lowering, removing spaces, removing punctuations
    testString = testString.lower()
    testString = testString.replace(" ", "")

    # Loop through from beginning and end simultaneously and start comparing
    for i in range(len(testString)):
        if testString[i] == testString[len(testString) - i - 1]:
            pass
        elif i == len(testString) - i - 1 or i > len(testString) - i - 1:
            break
        else:
            print("String not a palindrom")
            return
    print("String is a palindrom")


isPalindrom("nurses run")