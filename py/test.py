def merge(arr: list, lower: int, upper: int, mid: int):
    arr1 = arr[lower: mid + 1]
    arr2 = arr[mid + 1: upper + 1]

    i = j = k = 0

    while i < len(arr1) and j < len(arr2):
        if arr1[i] <= arr2[j]:
            arr[lower + k] = arr1[i]
            i += 1
        else:
            arr[lower + k] = arr2[j]
            j += 1
        k += 1

    while i < len(arr1):
        arr[lower + k] = arr1[i]
        i += 1
        k += 1

    while j < len(arr2):
        arr[lower + k] = arr2[j]
        j += 1
        k += 1

def merge_sort(arr: list, lower: int, upper: int):
    if lower < upper:
        mid = (lower + upper) // 2
        merge_sort(arr, lower, mid)
        merge_sort(arr, mid + 1, upper)
        merge(arr, lower, upper, mid)

if __name__ == '__main__':
    arr = [9, 6, 1, 4, 0, 6, 1]
    print("Original array:", arr)
    merge_sort(arr, 0, len(arr) - 1)
    print("Sorted array:", arr)
