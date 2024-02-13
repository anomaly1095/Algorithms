def binary_search(arr, lower, upper, target)->int:#returns index of element
    if upper-lower >= 0:
        mid = (upper+lower)//2
        
        if arr[mid] > target:
            return binary_search(arr, lower, mid-1, target)  
        
        elif arr[mid] < target:
            return binary_search(arr, mid+1, upper, target)
        
        else:
            return mid
    return -1


if __name__ == '__main__':
    num_keys = int(input())
    input_keys = list(map(int, input().split()))
    assert len(input_keys) == num_keys

    num_queries = int(input())
    input_queries = list(map(int, input().split()))
    assert len(input_queries) == num_queries

    for q in input_queries:
        print(binary_search(input_keys, 0, len(input_keys)-1, q), end=' ')
