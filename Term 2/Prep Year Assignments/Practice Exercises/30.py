# Write a Python program to guess a number between 1 to 9.
# Note: User is prompted to enter a guess. If the user guesses wrong then the prompt appears again until the guess 
# is correct, on successful guess, user will get a "Well guessed!" message, and the program will exit.

# Import Random
import random

# Function to validate guess
def ValidateGuess(random, guess):
    if random == guess:
        return True
    else:
        return False

# Flag variable
Correct = False

# Random number to guess
number = random.randint(1, 9+1)

# Get user to input numbers until it is correct
while not Correct:
    try:
        guess = int(input("Enter a guess between 1 to 9: "))
    except:
        print("Must be a Number!")
    Correct = ValidateGuess(number, guess)

# When correct, tell user
print("Well Guessed!")