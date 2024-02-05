#                               S(n) = F(n+2)-1

def fibonacci_sum(n: int):
    current = 1
    previous = 0
    if n == current:
        return current
    elif n == previous:
        return previous
    else:
        for _ in range(2, n+2):
            previous, current = current, previous + current
    return (current-1) % 10






if __name__ == '__main__':
    #n = int(input())
    print(fibonacci_sum(100000000))
