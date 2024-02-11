def partition(arr, low, high)->None:
    pivot = arr[high]  # Choose the rightmost element as the pivot
    i = low - 1  # Index of smaller element

    for j in range(low, high):
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]  # Swap arr[i] and arr[j]

    arr[i + 1], arr[high] = arr[high], arr[i + 1]  # Swap arr[i + 1] and pivot
    return i + 1  # Return the index of the pivot

def quick_sort(arr, low, high)->None:
    if low < high:
        pivot = partition(arr, low, high)

        quick_sort(arr, low, pivot - 1)  # Recursively sort elements before the pivot
        quick_sort(arr, pivot + 1, high)  # Recursively sort elements after the pivot


def main():
    my_list = [4, 2, 7, 1, 9, 5, 3, 8, 6]
    quick_sort(my_list, 0, len(my_list) - 1)
    print(my_list)

if __name__ == '__main__':
    main()
