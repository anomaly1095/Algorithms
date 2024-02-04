

def fact(n: int)->int:
    if n == 1 or n == 0:
        return 1
    else:
        return fact(n-1)*n


def main():
    n = 5
    print(fact(n))

if __name__ == '__main__':
    main()
