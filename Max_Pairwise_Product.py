def max_pairwise_product(numbers):
    val1 = 0
    val2 = 0
    for item in numbers:
        if item >= val1 and item >= val2:
            val2 = val1
            val1 = item
        elif item <= val1 and item > val2:
            val2 = item
    return val2 * val1


if __name__ == '__main__':
    _ = int(input())
    input_numbers = list(map(int, input().split()))
    print(max_pairwise_product(input_numbers))
