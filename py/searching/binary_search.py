
def binary_search(arr: list, lower: int, upper: int, target: int):
    if upper-lower >= 0:
        mid = (upper+lower)//2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            return binary_search(arr, mid+1, upper, target)
        elif arr[mid] > target:
            return binary_search(arr, lower, mid-1, target)
    return -1





def main():
    size: int = int(input())
    arr: list = list(map(int, input().split(' ')))
    assert size == len(arr)
    print(binary_search(arr, 0, size-1, arr[4]), end= ' ')


if __name__ == '__main__':
    main()