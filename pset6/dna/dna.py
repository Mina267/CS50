import sys
import csv
import pandas as pd


def main():
    if len(sys.argv) != 3:
        sys.exit("ERROR")
    
    # https://youtu.be/skGwKh1dAdk
    df = pd.read_csv(sys.argv[1])
    
    # used create table of list
    table = []   
    with open(sys.argv[1], "r") as file:
        reader = csv.DictReader(file)
        
        # read the header of table eg. AGATC
        STR = reader.fieldnames[1:]
        # create table of list to save csv file on it as in lab6
        for i in range(len(STR)):
            for row in reader:
                row[STR[i + 1]] = int(row[STR[i + 1]])
                table.append(row)
                
    # read sequnces file
    with open(sys.argv[2], 'r') as file:
        sequence = file.read()
        
    # check if dna match any name in the table
    for i in range(len(table)):
        match = 0
        for j in range(len(STR)):
            x = int(table[i][STR[j]])
            y = repeat(sequence, STR[j])

            if x == y:
                match += 1
        
        # See if all number in cell match number of sequence repeated STR in sequnce txt file
        if match == len(STR):
            print(table[i]['name'])
            # Exit program if find name so NO match will not print
            sys.exit(0)
            
    print("No match")


def repeat(sequence, dna):
    i = 0
    j = len(dna)
    max = 0
    for x in range(len(sequence)):
        if sequence[i:j] == dna:
            temp = 0
            while sequence[i:j] == dna:
                temp += 1
                i += len(dna)
                j += len(dna)
                if(temp > max):
                    max = temp
        else:
            i += 1
            j += 1
    return max
    
    
if __name__ == "__main__":
    main()
