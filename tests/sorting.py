import typing
from random import randint
#parent class
class sorting_algo():...

#---------------------------------------- Count sort

def count_sort(arr: list)->None:
    d: typing.Dict[int, int] = {}
    for e in arr:
        if e not in d:
            d[e] = 1
        else:
            d[e] += 1
    i = 0
    for k in sorted(d.keys()):
        for j in range(d[k]):
            arr[i] = k
            i += 1


#---------------------------------------- Merge sort
class merge_sort_algo(sorting_algo):
    
    @staticmethod
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
    
    @staticmethod
    def merge_sort(arr: list)->list:
        if len(arr) > 1:
            mid = len(arr) // 2
            arr1 = merge_sort_algo.merge_sort(arr[0: mid])
            arr2 = merge_sort_algo.merge_sort(arr[mid: len(arr)])
            return merge_sort_algo.merge(arr1, arr2)
        else:
            return arr
        
    #------------------In-place versions---------------------------

    @staticmethod
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

    @staticmethod
    def in_place_merge_sort(arr, lower: int, upper: int) -> None:
        if upper - lower > 0:
            mid = (upper + lower) // 2
            merge_sort_algo.in_place_merge_sort(arr, lower, mid)
            merge_sort_algo.in_place_merge_sort(arr, mid + 1, upper)
            merge_sort_algo.in_place_merge(arr=arr, lower1=lower, upper1=mid, lower2=mid + 1, upper2=upper)


#---------------------------------------- Quick Sort

class quick_sort(sorting_algo):
    
    @classmethod
    def random_quick_sort3(cls, arr: list):
        if len(arr) <= 1:
            return arr
        else:
            pivot_index = randint(0, len(arr)-1)
            pivot_arr = [x for x in arr if x == arr[pivot_index]]
            less_arr = [x for x in arr if x < arr[pivot_index]]
            greater_arr = [x for x in arr if x > arr[pivot_index]]
            
        return cls.random_quick_sort3(less_arr) + pivot_arr + cls.random_quick_sort3(greater_arr)

    @classmethod
    def in_place_random_quick_sort3(cls, arr, lower, upper):
        if lower < upper:
            pivot_index = randint(lower, upper)
            pivot = arr[pivot_index]

            # Initialize pointers for three-way partitioning
            left = lower
            right = upper
            i = lower

            while i <= right:
                if arr[i] < pivot:
                    arr[i], arr[left] = arr[left], arr[i]
                    left += 1
                    i += 1
                elif arr[i] > pivot:
                    arr[i], arr[right] = arr[right], arr[i]
                    right -= 1
                else:
                    i += 1

            # Recursive calls on the sub-arrays
            cls.in_place_random_quick_sort3(arr, lower, left - 1)
            cls.in_place_random_quick_sort3(arr, right + 1, upper)
            
            
            

#---------------------------------------- Heap sort

def heap_sort(arr: list):
    return arr



#---------------------------------------- Shell sort

def shell_sort(arr: list):
    return arr



#----------------------------------------

if __name__ == '__main__':
    arr = [1, 9, 2, 8, 1, 0, 4, 1, 3, 5, 7, 6, 3, 6, 0, 9, 1]
    quick_sort.in_place_random_quick_sort3(arr, 0, len(arr)-1)
    print(arr)