def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a

def lcm(a: int, b: int):
    print(abs(a * b) // gcd(a, b))

def main():
    a, b = map(int, input().split())
    if b > a:
        lcm(b, a)
    elif b == a:
        print(b)
    else:
        lcm(a, b)


if __name__ == '__main__':
    main()
