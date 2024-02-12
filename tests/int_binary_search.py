import rng
import sys

def binary_search(arr: list, lower: int, upper: int, target: int):
    if upper - lower >= 0:
        mid = (upper+lower)//2
        if arr[mid] > target:
            return binary_search(arr, lower, mid-1, target)
        elif arr[mid] < target:
            return binary_search(arr, mid+1, upper, target)
        else:
            return mid
    return -1
    

def main():
    if len(sys.argv) != 4:
        exit(f"Script usage: {sys.argv[0]} <min> <max> <size>")
    
    try:
        min, max, size = map(int, sys.argv[1:4])
    except ValueError as e:
        print(f"Error: {e}")
        print("All arguments must be integers.")
        exit(1)
    
    if 0 < max-min:
        arr = rng.generate_sorted_random_int_list(size, min, max, 1)
        print(arr)
    else:
        exit(f"max should be bigger than min.")
    
    try:
        target = int(input("Enter target value: "))
    except ValueError as e:
        print(f"Error: {e}")
        print("All arguments must be integers.")
        exit(1)
    
    print(f"Index: {binary_search(arr, 0, size-1, target)}")

if __name__ == '__main__':
    main()