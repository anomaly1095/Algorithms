def matrix_multiply(a, b, m):
    return ((a[0]*b[0] + a[1]*b[2]) % m, (a[0]*b[1] + a[1]*b[3]) % m,
            (a[2]*b[0] + a[3]*b[2]) % m, (a[2]*b[1] + a[3]*b[3]) % m)

def matrix_power(matrix, exponent, m):
    result = (1, 0, 0, 1)  # Identity matrix
    while exponent > 0:
        if exponent % 2 == 1:
            result = matrix_multiply(result, matrix, m)
        matrix = matrix_multiply(matrix, matrix, m)
        exponent //= 2
    return result

def fibonacci_huge_optimized(n, m):
    if n <= 1:
        return n

    matrix = (1, 1, 1, 0)  # Fibonacci matrix

    result_matrix = matrix_power(matrix, n - 1, m)

    return result_matrix[0] % m

if __name__ == '__main__':
    input = sys.stdin.read();
    n, m = map(int, input.split())
    print(fibonacci_huge_optimized(n, m))

