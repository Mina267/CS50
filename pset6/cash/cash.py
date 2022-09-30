from cs50 import get_float


dollars = get_float("Enter postive number: ")

# to round cents 
cents = round(dollars * 100)

# intial value for counters
count = 0
quarters = 0
dimes = 0
nickels = 0 
pennies = 0 

# loop to count cions
while cents != 0:
    if cents >= 25:
        cents -= 25
        count += 1
        quarters += 1
        
    elif cents >= 10:
        cents -= 10
        count += 1
        dimes += 1
        
    elif cents >= 5:
        cents -= 5
        count += 1
        nickels += 1
        
    elif cents >= 1:
        cents -= 1
        count += 1
        pennies += 1
        
# show no. of cions and add new lines for classification of cions
print(f"no. of cions= {count}")

# add new lines for each classification of cions
print(f"quarters = {quarters}, dimes = {dimes}, nickels = {nickels}, pennies = {pennies}")