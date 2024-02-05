def fibonacci_sum_optimized(n):
    if n <= 1:
        return n

    previous, current = 0, 1
    pisano_period = [0, 1]

    for _ in range(2, n + 1):
        previous, current = current, (previous + current) % 10
        pisano_period.append(current)

        # Check for the start of a new period
        if pisano_period[-2:] == [0, 1]:
            pisano_period = pisano_period[:-2]
            break

    index_in_pisano = n % len(pisano_period)

    return sum(pisano_period[:index_in_pisano + 1]) % 10

def fibonacci_partial_sum_optimized(from_, to):
    if to <= 1:
        return fibonacci_sum_optimized(to) - fibonacci_sum_optimized(from_ - 1)
    else:
        return (fibonacci_sum_optimized(to) - fibonacci_sum_optimized(from_ - 1)) % 10

if __name__ == '__main__':
    from_, to = map(int, input().split())
    print(fibonacci_partial_sum_optimized(from_, to))

