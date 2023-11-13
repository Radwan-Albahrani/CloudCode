import tkinter as tk
from tkinter import ttk

""" Write a program that has main menu: calculator , in calculator the  sub menu:
•	ADD: will show button “add “ to add the two numbers.
•	SUB: will show button “sub “ to subtract the two numbers.
•	MUL: will show button “mul “ to multiply the two numbers.
•	DIV: will show button “div “ to divide the two numbers.
"""

# Functions


def checkIfEmpty():
    if firstNumber.get() == "" or secondNumber.get() == "":
        answer.configure(text="Please enter two numbers")
        return False
    else:
        return True


def add():
    if not checkIfEmpty():
        return
    answer.configure(text=int(firstNumber.get()) + int(secondNumber.get()))


def sub():
    if not checkIfEmpty():
        return
    answer.configure(text=int(firstNumber.get()) - int(secondNumber.get()))


def mul():
    if not checkIfEmpty():
        return
    answer.configure(text=int(firstNumber.get()) * int(secondNumber.get()))


def div():
    if not checkIfEmpty():
        return
    if int(secondNumber.get()) == 0:
        answer.configure(text="Cannot divide by zero")
    else:
        answer.configure(text=int(firstNumber.get()) / int(secondNumber.get()))


window = tk.Tk()

# Menu
menu = tk.Menu(window, tearoff=0)
window.config(menu=menu)

# # Sub Menu
submenu = tk.Menu(menu, tearoff=0)
menu.add_cascade(label="Calculator", menu=submenu)
submenu.add_command(label="ADD", command=add)
submenu.add_command(label="SUB", command=sub)
submenu.add_command(label="MUL", command=mul)
submenu.add_command(label="DIV", command=div)

# Label
prompt = ttk.Label(window, text="Enter two numbers: ")
prompt.grid(row=0, column=0)

# Numbers
firstNumber = ttk.Entry(window)
firstNumber.grid(row=0, column=1)

secondNumber = ttk.Entry(window)
secondNumber.grid(row=0, column=2)

# Buttons
addButton = ttk.Button(window, text="ADD", command=add)
addButton.grid(row=1, column=0)

subButton = ttk.Button(window, text="SUB", command=sub)
subButton.grid(row=1, column=1)

mulButton = ttk.Button(window, text="MUL", command=mul)
mulButton.grid(row=1, column=2)

divButton = ttk.Button(window, text="DIV", command=div)
divButton.grid(row=1, column=3)

# Label
answer = ttk.Label(window, text="")
answer.grid(row=2, column=1)


if __name__ == "__main__":
    window.mainloop()
