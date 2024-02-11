from typing import List, Tuple
import sys

SIZE: int = 100
MAX: float = 1000
MIN: float = 2
RECURSION_LIMIT: int = 2000

def binary_search(arr: list, lower: int, upper: int, target: float)->Tuple[float, int]:
    """binary search algorithm (recursion)

    Args:
        arr (list): list to search in 
        lower (int): lower bound of array
        upper (int): upper bound of array
        target (float): target value that we are looking for or loking to insert

    Returns:
        Tuple[float, int]: Value, Index if found and -1, -1
    """
    if upper-lower >= 0:
        mid = (upper+lower)//2
        
        if arr[mid] > target:
            return binary_search(arr, lower, mid-1, target) #mid -1 so that the middle element is not taken 
        
        elif arr[mid] < target:
            return binary_search(arr, mid+1, upper, target)
        
        else:
            return arr[mid], mid
    return -1.0, -1


def fill_array()->List[float]:
    arr = []
    for i in range(SIZE):
        arr.append((i**3)/1.3)
    return arr

def main()->None:
    arr = fill_array()
    print(f"Unsorted array: {arr}")
    
    sys.setrecursionlimit(RECURSION_LIMIT)
    
    target = float(input("Enter value to search for: "))
    res = binary_search(arr, 0, SIZE-1, target)
    print(res)
    
if __name__ == '__main__':
    main()