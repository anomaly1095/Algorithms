from typing import Dict, Tuple, List


def sum_is_target(size: int, target: int, d: Dict[str, int], l: List[int])->Tuple[int, int]:
    for i in range(0, size):
        try:
            res = l[i] + d[str(target-l[i])]  # check that there is a value in the dict that is equal to target-l[i] if so break
            return d[str(l[i])], d[str(target-l[i])]
        except KeyError:
            continue


def get_data(size: int)->Tuple[Dict[int, int], List[int]]:
    d: Dict[str, int] = {}
    l: List[int] = []
    val = 276
    for i in range(0, size):
        d[str(val+i*7)] = val + 7 * i
        l.append(val + 7 * i)
    return d, l


def main():
    size = 30
    t: Tuple[Dict[str, int], List[int]] = get_data(size)
    result: Tuple[int, int] = sum_is_target(size=size, target=t[1][5]+t[1][15], d=t[0], l=t[1])
    print(result)

if __name__ == '__main__':
    main()
