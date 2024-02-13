from random import randint

def partition3(array, left, right):
    pivot = array[left]
    less_than_pivot = left
    equal_to_pivot = left
    greater_than_pivot = right

    while equal_to_pivot <= greater_than_pivot:
        if array[equal_to_pivot] < pivot:
            array[less_than_pivot], array[equal_to_pivot] = array[equal_to_pivot], array[less_than_pivot]
            less_than_pivot += 1
            equal_to_pivot += 1
        elif array[equal_to_pivot] == pivot:
            equal_to_pivot += 1
        else:
            array[equal_to_pivot], array[greater_than_pivot] = array[greater_than_pivot], array[equal_to_pivot]
            greater_than_pivot -= 1

    return less_than_pivot, equal_to_pivot - 1


def randomized_quick_sort(array, left, right):
    if left >= right:
        return
    k = randint(left, right)
    array[left], array[k] = array[k], array[left]
    m1, m2 = partition3(array, left, right)
    randomized_quick_sort(array, left, m1 - 1)
    randomized_quick_sort(array, m2 + 1, right)


if __name__ == '__main__':
    input_n = int(input())
    elements = list(map(int, input().split()))
    assert len(elements) == input_n
    randomized_quick_sort(elements, 0, len(elements) - 1)
    print(*elements)
