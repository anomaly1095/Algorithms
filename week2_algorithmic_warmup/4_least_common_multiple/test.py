def lcm(a, b):
    return abs(a * b) // gcd(a, b)

def main():
    a, b = map(int, input().split())
    result = lcm(a, b)
    print(f"The LCM of {a} and {b} is {result}")
if __name__ == '__main__':
    main()
