from random import randint

"""count sorting is algo ideal for specific data exp: smaller range of values
"""

MIN = -5
MAX = 40
SIZE = 1000

def count_sort(arr: list)->dict:
    d = {key: 0 for key in range(MIN, MAX+1)} #initialize d with keyfrom MIN TO MAX and values: zeros
    for i in range(SIZE):
        d[arr[i]] += 1
    arr.clear()
    for i in range(MIN, MAX+1):
        for j in range(d[i]):
            arr.append(i)
    return arr


def fill_list()->list:
    l = []
    for i in range(SIZE):
        l.append(randint(a=MIN, b=MAX))
    return l

def main():
    
    arr = fill_list()
    print(f"Unsorted list: {arr}")
    arr = count_sort(arr)
    print(f"Sorted list: {arr}")
    

if __name__ == '__main__':
    main()
