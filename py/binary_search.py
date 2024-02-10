from multiprocessing import Process
import sys

def binary_search(arr: list, lower: int, upper: int, target: int) -> int:
    mid = (upper + lower) // 2
    if upper - lower >= 0:
        if arr[mid] > target:
            return binary_search(arr, lower, mid - 1, target)
        elif arr[mid] < target:
            return binary_search(arr, mid + 1, upper, target)
        else:
            return mid
    return -1  # Target not found

    
def fill_array(size: int)->list:
    l = []
    for i in range(size):
        l.append(i)
    return l


def main():
    # Set a new recursion depth limit 
    new_limit = 5000
    sys.setrecursionlimit(new_limit)
    
    size = 2000
    arr = fill_array(size)
    print(arr)
    
    target = 1876
    print(f"\nIndex: {binary_search(arr = arr, lower = 0, upper = size-1, target=target)}")
    
if __name__ == '__main__':
    main()