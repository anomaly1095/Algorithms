import base

def merge(arr1: list, arr2: list)->list:
    arr = []
    i, j = 0, 0
    while i < len(arr1) or j < len(arr2):
        if i == len(arr1):
            arr.append(arr2[j])
            j += 1
        elif j == len(arr2):
            arr.append(arr1[i])
            i += 1
        elif arr1[i] < arr2[j]:
            arr.append(arr1[i])
            i += 1
        elif arr1[i] > arr2[j]:
            arr.append(arr2[j])
            j += 1
        else:
            arr.append(arr1[i])
            arr.append(arr2[j])
            i, j = i+1, j+1
    return arr

def merge_sort(arr: list)->list:
    if len(arr) > 1:
        mid = len(arr) // 2
        arr1 = merge_sort(arr[0: mid])
        arr2 = merge_sort(arr[mid: len(arr)])
        return merge(arr1, arr2)
    else:
        return arr
    
#------------------In-place versions---------------------------


def in_place_merge(arr: list, lower1: int, upper1: int, lower2: int, upper2: int) -> None:
    i, j = lower1, lower2
    while i <= upper1 and j <= upper2:
        if arr[i] > arr[j]:
            temp = arr[j]
            for k in range(j, i, -1):
                arr[k], arr[k - 1] = arr[k - 1], arr[k]  # Swap elements
            arr[i] = temp
            j += 1
            i += 1
            upper1 += 1
        elif arr[i] < arr[j]:
            i += 1
        else:  # arr[i] == arr[j]
            temp = arr[j]
            for k in range(j, i, -1):
                arr[k], arr[k - 1] = arr[k - 1], arr[k]  # Swap elements
            arr[i + 1] = temp
            i += 1
            j += 1
            upper1 += 1


def in_place_merge_sort(arr, lower: int, upper: int) -> None:
    if upper - lower > 0:
        mid = (upper + lower) // 2
        in_place_merge_sort(arr, lower, mid)
        in_place_merge_sort(arr, mid + 1, upper)
        in_place_merge(arr=arr, lower1=lower, upper1=mid, lower2=mid + 1, upper2=upper)


if __name__ == '__main__':
    import random
    # arr = [random.randint(0, 1000) for _ in range(30)]
    arr = [159, 939, 155, 709, 462, 768, 380, 883, 545, 842, 903, 535, 57, 75, 774, 747, 462, 238, 119, 293, 785, 911, 283, 730, 745, 63, 936, 97, 768, 781, 213]
    in_place_merge_sort(arr, 0, 29)
    print(arr)
