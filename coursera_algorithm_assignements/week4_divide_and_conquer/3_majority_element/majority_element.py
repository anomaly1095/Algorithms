def majority_element(elements):
    d = dict()
    for e in elements:
        if e in d:
            d[e] += 1
        else:
            d[e] = 1

        if d[e] > len(elements) // 2:
            return 1

    return 0

if __name__ == '__main__':
    input_n = int(input())
    input_elements = list(map(int, input().split()))
    assert len(input_elements) == input_n
    print(majority_element(input_elements))
