



def sum(n: int):
    if n == 0:
        return 0
    return n + sum(n - 1)






if __name__ == '__main__':
    n = 160000
    print(sum(n))
