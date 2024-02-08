from sys import stdin

def optimal_value(capacity, sorted_data):
    val = 0.0

    for weight, unit_price in sorted_data:
        
        if capacity >= weight:
            val += weight * unit_price
            capacity -= weight
        else:
            val += capacity * unit_price
            break
    return val

if __name__ == "__main__":
    data = list(map(int, stdin.read().split()))
    n, capacity = data[0:2]

    sorted_data = sorted([(data[2*i + 3], data[2*i + 2] / data[2*i + 3]) for i in range(n)], key=lambda x: x[1], reverse=True)

    opt_value = optimal_value(capacity, sorted_data)
    print("{:.10f}".format(opt_value))
