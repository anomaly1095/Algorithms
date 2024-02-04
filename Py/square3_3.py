from typing import List, Tuple, Dict
                                    #  3*3 Magic square

l: List[Tuple] = []


# finding 3 distinct 1 digit numbers 
for x in range(1, 8):
    for y in range(x+1, 9):
        for t in range(y+1, 10):
            if x + y + t == 15: # checking which ones have a sum of 15
                l.append((x, y, t))

d_rep: Dict[int, int] = {}

# checking each number's repetition
for i in range(1, 10):
    repetition = 0
    for item in l:
        if i in item:
            repetition += 1
    d_rep[i] = repetition  # dict[number: repetition]  ----> exp: 9: 2


square: List[List[int]] = [
    [0, 0, 0],
    [0, 0, 0],
    [0, 0, 0]
]

# iterating over the dictionary if number has 2 as a repetition it is not in the diagonal so it is being repeated only in the column and row
square[0][1] = 9
for i in range(1, 10):
    if 
