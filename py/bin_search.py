x, y = map(int, input("Enter values for binary search: ").split( ))
val = y // 2
print(f"cut at: {val}")

while True:
    b_or_l = input("b/l: ")
    if b_or_l == 'b':
        val += val // 2
        print(f"cut at: {val}")
    elif b_or_l == 'l':
        val -= val // 2
        print(f"cut at: {val}")
