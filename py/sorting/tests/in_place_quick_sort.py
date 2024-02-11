def partition(arr: list, low: int, up: int)->list:
    
    for i in range(low, up):
        if arr[i] <= :
            
    for i in range(len(arr)):
        if arr[i] > pivot:
            pass
    
def quick_sort(arr: list)->list:
    else:
        pivot = arr[0]
        partition(arr, low, up)
        return quick_sort(arr) + [pivot] + quick_sort(arr, )

def fill_data(size: int, arr: int):
    for i in range(30, 1, -1):
        arr.append(i)

def main():
    size = 20
    arr = []
    fill_data(size, arr)
    print(arr)
    print(quick_sort(arr= arr, low= 0, up= size-1))

if __name__ == '__main__':
    main()