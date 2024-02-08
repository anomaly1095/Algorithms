def change(x: int):
    val = 0;
    if x <= 0:
        printf("Imposible transtaction!")
        return 0

    while x != 0:
        if x >= 10:
            x -= 10
            val += 1
        if x >= 5 and x < 10:
            x -= 5
            val += 1
        if x < 5 and x > 0:
            x -= 1
            val += 1
        if x == 0:
            return val


if __name__ == '__main__':
    m = int(input())
    print(change(m))
