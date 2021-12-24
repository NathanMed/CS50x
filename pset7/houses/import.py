import csv
from cs50 import SQL
from sys import argv, exit

# Declares the database we'll be working in
db = SQL("sqlite:///students.db")

# Checks to make sure the user only input 1 command argument
if len(argv) > 2:
    print("Usage: python import.py csvfile.csv")
    # Exits the program if the input more than one command line argument
    exit(1)
# Uses the first command line argument as the file directory
with open(argv[1], "r") as f:
    reader = csv.DictReader(f)
    for row in reader:
        # Splits the name into it's seperate substrings (aka first, middle, and last name)
        l = row["name"].split()
        # Checks to see if the name has a middle name
        if len(row["name"].split()) > 2:
            # If it does, it will put it into the database
            db.execute("insert into students (first, middle, last, house, birth) values(?, ?, ?, ?, ?)",
                       l[0], l[1], l[2], row["house"], row["birth"])
        else:
            # If it doesn't, it will put in None instead
            db.execute("insert into students (first, middle, last, house, birth) values(?, ?, ?, ?, ?)",
                       l[0], None, l[1], row["house"], row["birth"])