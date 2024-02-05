def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a

def main():
    a, b = map(int, input().split())
    if b > a:
        print(gcd(b, a))
    else:
        if a == b:
            print(a)
            return
        if a % b == 0:
            print(b)
            return 
        if a > b:
            print(gcd(a, b))

if __name__ == "__main__":
    main()
