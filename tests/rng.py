"""Random list generators.

    integer functions
    -------------
           sorted_random_int_list
           unsorted_random_int_list
           
    float functions
    -------------
           sorted_random_float_list
           unsorted_random_float_list


    C equivalent
    ---------------------------------------------
           same program in c is in developpement 

General notes on the code:

* shell and heap are not yet implemented
* For sorted function many sorting algorithms can be applied 
* 
  

"""

import random
import sorting.base as base
import sorting.count as count
import sorting.merge as merge 
import sorting.quick as quick 
import sorting.shell as shell 
import sorting.heap as heap 


def generate_unsorted_random_int_list(size: int, min: int, max: int)->any:
    """Generates unsorted integer list

    Args:
        size (int): size of list
        min (int) : minimum item value
        max (int): maximum item value
        
    Returns:
        List[int]: Populated list
    """
    
    if not isinstance(min, int) or not isinstance(max, int):
        raise count.InvalidInputError("min and max must be integers.")

    arr = [random.randint(min, max) for _ in range(size)]
    return arr
    

def generate_unsorted_random_float_list(size: int, min: float, max: float)->any:
    """Generates unsorted float list

    Args:
        size (int): size of list
        min (float) : minimum item value
        max (float): maximum item value

    Returns:
        List[float]: Populated list
    """
    
    if not isinstance(min, float) or not isinstance(max, float):
        raise count.InvalidInputError("min and max must be floating point numbers.")

    arr = [random.random(min, max) for _ in range(size)]
    return arr


def generate_sorted_random_int_list(size: int, min: int, max: int, sorting_method: int = 3)->any:
    """
    Generates sorted integeger list
    if the range of values is < 100
    
    Args:
        size (int): size of list
        min (int) : minimum item value
        max (int): maximum item value
    
    Sorting_method:
        * 1: count sort
        * 2: merge sort
        * 3: quick sort 1
        * 4: shell sort
        * 5: heap sort
        
        Default: quick sort(3)
        
    Returns:
        List[int]: Populated list
    """
    
    if not isinstance(min, int) or not isinstance(max, int):
        raise base.InvalidInputError("min and max must be integers.")
    
    arr = [random.randint(min, max) for _ in range(size)]
    
    # when finished writing all algorithms change all to inplace for space efficiency
    match sorting_method:
        case 1:
            count.count_sort(arr, min, max)
        case 2:
            arr = merge.int_merge_sort(arr, 0, size-1)
        case 3:
            arr = quick.quick_sort(arr, 0, size-1)
        case 4:
            arr = shell.shell_sort(arr)
        case 5:
            arr = heap.heap_sort(arr)
    
    return arr


def generate_sorted_random_float_list(size: int, min: float, max: float, sorting_method: int = 3)->any:
    """Generates sorted float list

    Args:
        size (int): size of list
        min (float) : minimum item value
        max (float): maximum item value

    Returns:
        List[float]: Populated list
    """
    
    if not isinstance(min, float) or not isinstance(max, float):
        raise count.InvalidInputError("min and max must be floating point numbers.")

    arr = [random.random(min, max) for _ in range(size)]
    
    count.merge_sort_float_list(arr, 0, size-1)
    return arr

