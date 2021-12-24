import csv
from sys import argv
data = {}

# Counts the max numbers of strs, given the sequence and a string
def maximum_number_of_strs(s, subs):
    ans = [0] * len(s)
    for i in range(len(s) - len(subs), -1, -1):
        if s[i: i + len(subs)] == subs:
            if i + len(subs) > len(s) - 1:
                ans[i] = 1
            else:
                ans[i] = 1 + ans[i + len(subs)]
    return max(ans)

# Compares


def match(compare):
    for key in data:
        if data[key] == compare:
            return key
    return "No match"
    

def main():
    with open(argv[2], "r") as f:
        while True:
            s = f.readline()
            break
# Loads in the data from the database and puts it in a dictionary, where the name is key and the value is an array, containing the number of STRs
    with open(argv[1], "r") as csvfile:
        reader = csv.reader(csvfile)
        for row in reader:
            data[row[0]] = []
            # Reads each line from the csv into the data dictionary, using the first word as a key
            for i in range(len(row)):
                data[row[0]].append(row[i])
            # Gets rid of the row's name from it's array
            data[row[0]].pop(0)
    # If I don't remove the 'name' row, I will get an error later on
    test = data['name']
    data.pop('name')
    # We take the values in each array in data[key] and turn them into ints
    for key in data:
        for i in range(len(data[key])):
            data[key][i] = int(data[key][i])
    compare = []
    for i in range(len(test)):
        compare.append(maximum_number_of_strs(s, test[i]))
    print(match(compare))
    
    
main() 
