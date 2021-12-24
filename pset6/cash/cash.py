from cs50 import get_float

# The equivalent of a do() while loop
while True:
    cents = get_float("Change owed: ")
    if cents > 0:
        break
change = 0
# Takes the float value and turns it into an int as it's easier to work with
x = round(cents * 100)
# Quarters
while x >= 25:
    change += 1
    x -= 25
# Dimes
while x >= 10:
    change += 1
    x -= 10
# Nickels
while x >= 5:
    change += 1
    x -= 5
# Pennies
while x >= 1:
    change += 1
    x -= 1
print(change)