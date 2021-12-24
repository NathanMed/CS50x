from cs50 import SQL

db = SQL("sqlite:///students.db")

db.execute("create table test (person int)")