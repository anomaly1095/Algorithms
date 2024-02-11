from random import randint

#  in python we will implement merge sort by creating new arrays/ more efficient algorithms will bein c's merge sort
def merge(arr1: list, arr2: list)->list:
    arr = []
    i = 0
    j = 0
    size = len(arr1) + len(arr2)
    while len(arr) != size:
        if len(arr1) == 0 or len(arr2) == 0:
            arr += arr2
            arr += arr1
            return arr
        if arr2[j] < arr1[i]:
            arr.append(arr2.pop(j))
        elif arr1[i] < arr2[j]:
            arr.append(arr1.pop(i))
        else:
            arr.append(arr1.pop(i))
            arr.append(arr2.pop(j))
    return arr


def merge_sort(arr: list, lower: int, upper: int):
    mid = (lower+upper)//2
    if upper-lower >= 1:
        arr1 = merge_sort(arr[lower:mid+1], lower, mid)
        arr2 = merge_sort(arr[mid+1:upper+1], 0, upper//2)
        return merge(arr1, arr2)
    return arr

def fill_array(size: int)->list:
    arr = []
    i = size
    while i > 10:
        # arr.append(randint(-1000, 2000))
        arr.append(2)
        i -= 1
    while i > 1:
        arr.append(8*i)
        i -= 1
    return arr

def main():
    size= 30
    arr = fill_array(size)
    print(arr)
    print(merge_sort(arr, 0, size-1))
    

if __name__ == '__main__':
    main()