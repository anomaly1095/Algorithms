

def quick_sort(arr: list):
    if len(arr) <= 1:
        return arr
    else:
        lower = [x for x in arr[1:] if x <= arr[0]]
        upper = [x for x in arr[1:] if x > arr[0]]
        return quick_sort(lower) + [arr[0]] + quick_sort(upper)

def fill_data(size: int, arr: int):
    for i in range(30, 1, -1):
        arr.append(i)

def main():
    size = 20
    arr = []
    fill_data(size, arr)
    print(arr)
    print(quick_sort(arr))

if __name__ == '__main__':
    main()