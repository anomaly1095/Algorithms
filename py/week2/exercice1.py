




def fibonacci_value(n: int)->int:
    val1 = 0
    val2 = 1
    if n == 0:
        return val1
    elif n == 1:
        return val2
    else:
        for i in range(1, n):
            val0 = val2
            val2 += val1
            val1 = val0
    return val2




if __name__ == '__main__':
    n = int(input())
    print(fibonacci_value(n))


