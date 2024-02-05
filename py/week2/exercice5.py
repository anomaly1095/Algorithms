def fibonacci_huge_optimized(n, m):
    if n <= 1:
        return n

    previous, current = 0, 1
    pisano_period = [0, 1]

    for _ in range(2, n + 1):
        previous, current = current, (previous + current) % m
        pisano_period.append(current)

        # Check for the start of a new period
        if pisano_period[-2:] == [0, 1]:
            pisano_period = pisano_period[:-2]
            break

    # Calculate the index in the Pisano period for n
    index_in_pisano = n % len(pisano_period)

    return pisano_period[index_in_pisano]

if __name__ == '__main__':
    n, m = map(int, input().split())
    print(fibonacci_huge_optimized(n, m))

