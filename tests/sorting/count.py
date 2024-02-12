import base

#---------------------------------------- Count sort

def count_sort(arr: list, min: int, max: int)->None:
    d: base.Dict[int, int] = {}
    for e in arr:
        if e not in d:
            d[e] = 1
        else:
            d[e] += 1
    i = 0
    for k in sorted(d.keys()):
        for j in range(d[k]):
            arr[i] = k
            i += 1