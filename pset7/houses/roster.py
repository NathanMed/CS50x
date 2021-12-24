from cs50 import SQL
from sys import argv, exit

# Makes sure the user only inputs 1 command line argument
if len(argv) > 2:
    "Usage: python roster.py house"
    # exits the program if they input more than one
    exit(1)
    
# Declares the database we'll be taking info from
db = SQL("sqlite:///students.db")

# Says that the house is equal to the second command line argument
house = argv[1]
# SQL query
l = db.execute("select first, middle, last, birth from students where house = ? order by last", house)
for i in range(len(l)):
    f = l[i]["first"]
    k = l[i]["last"]
    m = l[i]["middle"]
    b = l[i]["birth"]
    if m == None:
        # Prints out the first and last name, and the birth year
        print(f"{f} {k}, born: {b}")
    else:
        # If there is a middle name, it prints that too
        print(f"{f} {m} {k}, born: {b}")
