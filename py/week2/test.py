from typing import List

# n is the n'th fibonacci number m is the modulo
def modulo_fibonacci(n: int, m: int)-> int:
    if n <= 1:
        return n
    pisano_seq: List[int] = [0, 1]
    previous, current = 0, 1
    for i in range(1, n+1):
        previous, current = current, previous+current
        pisano_seq.append(current % m)
        if pisano_seq[0] == previousi % m and (pisano_seq[1] == current % m) and pisano_seq[2] == pisano_seq[i-2] and pisano_seq[3] == pisano_seq[i-3]:
            break
    print(pisano_seq)
    return pisano_seq[n // len(pisano_seq)]


if __name__ == '__main__':
    
    print(modulo_fibonacci(8, 3))
