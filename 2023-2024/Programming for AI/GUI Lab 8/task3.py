import tkinter as tk
from tkinter import ttk
"""Write a program for booking a new ticket. Ask the use about :
•	Name
•	Destination
•	Flight Time
•	Drinks
After submission show the ticket information in green color.
"""


def checkEmpty():
    if name.get() == "" or destination.get() == "" or flightTime.get() == "":
        ttk.Label(window, text="Please fill all the fields",
                  foreground="red").grid(row=7, columnspan=4)
        return False
    else:
        return True


def submit():
    if not checkEmpty():
        return
    ttk.Label(window, text="Name: " + name.get(),
              foreground="green").grid(row=7, columnspan=4)
    ttk.Label(window, text="Destination: " + destination.get(),
              foreground="green").grid(row=8, columnspan=4)
    ttk.Label(window, text="Flight Time: " + flightTime.get(),
              foreground="green").grid(row=9, columnspan=4)
    drinks = []
    if tea.get() == 1:
        drinks.append("Tea")
    if coffee.get() == 1:
        drinks.append("Coffee")
    if water.get() == 1:
        drinks.append("Water")

    ttk.Label(window, text="Drinks: " +
              ", ".join(drinks), foreground="green").grid(row=10, columnspan=4)


window = tk.Tk()
window.title("Ticket Booking")
window.geometry("500x500")

# Name Components
nameLabel = ttk.Label(window, text="Name: ")
name = ttk.Entry(window)

# Destination Components
destinationLabel = ttk.Label(window, text="Destination: ")
destination = ttk.Combobox(
    window, values=["London", "Paris", "New York", "Dubai", "Riyadh"])

# Flight Time Components
flightTimeLabel = ttk.Label(window, text="Flight Time: ")
flightTime = ttk.Combobox(
    window, values=["Morning", "Afternoon", "Evening", "Night"])

# Drinks Components
drinksLabel = ttk.Label(window, text="Drinks: ")
tea = tk.IntVar()
teaCheck = ttk.Checkbutton(window, text="Tea", variable=tea)
coffee = tk.IntVar()
coffeeCheck = ttk.Checkbutton(window, text="Coffee", variable=coffee)
water = tk.IntVar()
waterCheck = ttk.Checkbutton(window, text="Water", variable=water)

# submit
submitButton = ttk.Button(window, text="Submit", command=submit)


def pack():
    nameLabel.grid(row=0, column=0)
    name.grid(row=0, column=1)
    destinationLabel.grid(row=1, column=0)
    destination.grid(row=1, column=1)
    flightTimeLabel.grid(row=2, column=0)
    flightTime.grid(row=2, column=1)
    drinksLabel.grid(row=3, column=0)
    teaCheck.grid(row=3, column=1)
    coffeeCheck.grid(row=4, column=1)
    waterCheck.grid(row=5, column=1)
    submitButton.grid(row=6, columnspan=4)


if __name__ == "__main__":
    pack()
    window.mainloop()
