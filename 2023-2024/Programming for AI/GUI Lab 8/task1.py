import tkinter as tk
from tkinter import ttk
import random
"""Write a program that randomly generates an integer between 0 and 10.
    The program prompts the user to enter a number. When the user click the button a message should show:
    you win  if random number=input
•	too high if random number<input
•	you low if random number>input
"""

randomNumber = random.randint(0, 10)


def checkGuess():
    if int(entry.get()) == randomNumber:
        label2.configure(text="You Win")
    elif int(entry.get()) > randomNumber:
        label2.configure(text="Too High")
    else:
        label2.configure(text="Too Low")


window = tk.Tk()
window.title("Random Number")

# Label
label = ttk.Label(window, text="Enter a number between 0 and 10: ")
label.grid(row=0, column=0)

# Entry
entry = ttk.Entry(window)
entry.grid(row=0, column=1)

# Button
button = ttk.Button(window, text="Click Me", command=checkGuess)
button.grid(row=1, columnspan=2)

# Label
label2 = ttk.Label(window, text="")
label2.grid(row=2, columnspan=2)

if __name__ == "__main__":
    window.mainloop()
