def optimal_summands(n):
    summands = []
    current_sum = 0
    i = 1

    while current_sum + i <= n:
        summands.append(i)
        current_sum += i
        i += 1

    # If there is remaining value, add it as a single summand
    if current_sum < n:
        summands.append(n - current_sum)

    return summands

if __name__ == '__main__':
    n = int(input())
    summands = optimal_summands(n)
    print(len(summands))
    print(*summands)

