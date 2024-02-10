def quick_sort(arr):
    if len(arr) <= 1:
        return arr
    else:
        less = [x for x in arr[1:] if x <= arr[0]]
        greater = [x for x in arr[1:] if x > arr[0]]
        return quick_sort(less) + [arr[0]] + quick_sort(greater)

def main():
    my_list = [4, 2, 7, 1, 9, 5, 3, 8, 6]
    sorted_list = quick_sort(my_list)
    print(sorted_list)

if __name__ == '__main__':
    main()