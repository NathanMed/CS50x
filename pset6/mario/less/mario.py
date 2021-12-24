from cs50 import get_int

# The equivalent to a do while loops
while True:
    x = get_int("Height: ")
    if x > 0 and x <= 8:
        break
# Prints a pyrmaid of a given height
for i in range(x):
    for j in range(x):
        if (j + i) < (x - 1):
            print(" ", end='')
        else:
            print("#", end='')
    print()
    