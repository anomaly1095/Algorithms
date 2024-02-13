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

import rng
from copy import copy
from sys import argv
from os import getcwd
from time import perf_counter
import sorting
from datetime import datetime
from typing import List, Dict


class check_int_or_float:
    @staticmethod
    def int_or_float()->int:
        try:
            float_or_int = int(input("Enter 1 to work with integers / 2 for floating point numbers: "))
        except ValueError:
            exit("Enter 1 or 2.")
        except KeyboardInterrupt:
            exit(1)
        else:
            if 1 <= float_or_int <= 2:
                return float_or_int
            else:
                exit("Enter 1 or 2.")

    @staticmethod
    def _int() -> List[int]:
        #check the type of the values
        try:
            size, min, max = map(int, argv[1:4])
        except ValueError as e:
            print(f"Error: {e}")
            print("All arguments must be integers.")
            exit(1)

        # making sure that max >= min
        if max-min >= 0:
            arr: List[int] = rng.unsorted_random_number_generator.generate_unsorted_random_int_list(size, min, max)
            return arr
        else:
            exit(f"max should be bigger than min.")

    @staticmethod
    def _float() -> List[float]:
        #check the type of the values
        try:
            size = int(argv[1])
        except ValueError as e:
            print(f"Error: {e}")
            print("size must be an int")
            exit(1)

        arr: List[float] = rng.unsorted_random_number_generator.generate_unsorted_random_float_list(size)
        return arr


class test_performance:
    
    @staticmethod
    def start_count_sort(arr: list, result_list: List[str]) -> None:
        
        start_count_sort = perf_counter()
        sorting.count_sort(arr)
        end_count_sort = perf_counter()
        
        s = f"count sort O(n)'technically': {end_count_sort-start_count_sort:.8f}"
        result_list.append(s)

    #------------------------------
    @staticmethod
    def start_merge_sort(arr: list, result_list: List[str]) -> None:
        
        start_merge_sort = perf_counter()
        sorting.merge_sort_algo.in_place_merge_sort(arr, 0, len(arr)-1)
        end_merge_sort = perf_counter()
        
        
        s = f"merge sort O(nlog(n)): {end_merge_sort-start_merge_sort:.8f}"
        result_list.append(s)
    
    #------------------------------
    @staticmethod
    def start_quick_sort(arr: list, result_list: List[str]) -> None:
        
        start_quick_sort = perf_counter()
        arr = sorting.quick_sort.quick_sort3(arr, 0, len(arr)-1)   #change for the most efficient algorithms
        end_quick_sort = perf_counter()
        
        s = f"quick sort O(nlog(n)): {end_quick_sort-start_quick_sort:.8f}"
        result_list.append(s)
    
    #------------------------------
    @staticmethod
    def start_shell_sort(arr: list, result_list: List[str]) -> None:
        
        start_shell_sort = perf_counter()
        arr = sorting.shell_sort(arr)
        end_shell_sort = perf_counter()
        
        s = f"shell sort: {end_shell_sort-start_shell_sort:.8f}"
        result_list.append(s)
    
    #------------------------------
    @staticmethod
    def start_heap_sort(arr: list, result_list: List[str]) -> None:
        
        start_heap_sort = perf_counter()
        arr = sorting.heap_sort(arr)
        end_heap_sort = perf_counter()
        
        s = f"heap sort: {end_heap_sort-start_heap_sort:.8f}"
        result_list.append(s)
    
    #------------------------------
    @classmethod
    def sorting_algo_performance(cls, arr: list, input_type: type) -> List[str]:
        result_list: List[str] = []
        arr1 = copy(arr); arr2 = copy(arr); arr3 = copy(arr); arr4 = copy(arr); arr5 = copy(arr)   # making copies for each algo to work on
        
        try:
            output_file = open(file="output.txt", mode='w')
        except FileNotFoundError:
            exit(f"Output file not found at {getcwd()}/output.txt")
        
        output_file.write(f"---------------------Unsorted array---------------------\n{arr}\n")
        
        if input_type == int:
            cls.start_count_sort(arr1, result_list)
            output_file.write(f"---------------------count sort output---------------------\n{arr1}\n")
        
        cls.start_merge_sort(arr2, result_list)
        output_file.write(f"---------------------merge sort output---------------------\n{arr2}\n")
        
        # cls.start_quick_sort(arr3, result_list)
        # output_file.write(f"---------------------quick sort output---------------------\n{arr3}\n")
        
        # cls.start_shell_sort(arr4, result_list)
        # output_file.write(f"---------------------shell sort output---------------------\n{arr4}\n")
        
        # cls.start_heap_sort(arr5, result_list)
        # output_file.write(f"---------------------heap sort output---------------------\n{arr5}\n")
        output_file.close()
        return result_list

    #------------------------------
    @staticmethod
    def write_file(arr: list, result_list: List[Dict[str, float]]) -> None:
        try:
            log_file = open(file="sorting_performance.log", mode= 'a')
        except FileNotFoundError:
            exit("Log file not found.")
        else:
            log_file.write(f"-------------------------\n")
            log_file.write(f"* Benchmarking results\n")
            log_file.write(f"* Date: {datetime.now()}\n")
            log_file.write(f"* Size of input: {len(arr)}\n")
            for s in result_list:
                log_file.write(f"{s}\n")
            
            log_file.close()


def main() -> None:
    #list of ints
    if check_int_or_float.int_or_float() == 1:
        #check number of command line arguments
        if len(argv) != 4:
            exit(f"Correct script usage with integers: {argv[0]} <size> <min> <max>")
        #generate int random array with min and max values 
        arr: List[int] = check_int_or_float._int()
        result_list = test_performance.sorting_algo_performance(arr, int)
    
    #list of floating point numbers
    else:
        #check number of command line arguments
        if len(argv) != 2:
            exit(f"Correct script usage with floats: {argv[0]} <size>")
        arr: List[int] = check_int_or_float._float()
        print(arr)
        result_list = test_performance.sorting_algo_performance(arr, float)
        
    test_performance.write_file(arr, result_list)


if __name__ == '__main__':
    main()