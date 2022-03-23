# Get Input and Validate it
parsed = False
try:
    balance = float(input("Enter your Current Balance: "))
    parsed = True
except ValueError:
    print("Must Be a Number.")

# Get Rate based on input
rate = 0.04 if balance > 20000 else 0.03

# Calculate new balance after 5 years
for i in range(5):
    oldbalance = balance
    balance += (balance * rate)
    print(f"Balance in Year {i + 1} Before: {oldbalance}")
    print(f"Balance in Year {i + 1} After: {balance}\n\n")
