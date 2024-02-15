





# def palyndrom(n: int):
#     s1, s2 = str(n), ''
#     pivot = len(s1)//2
#     left = 0
#     right = len(s1)-1
#     if len(s1) % 2 == 0:
#         for i in range(0, pivot+1):
#             left, right = right, s1[left]
#             right -= 1
#             left += 1
#     else:
#         for i in range(0, pivot):
            
#             right -= 1
#             left += 1



if __name__ == '__main__':
    # n = 777
    # print(palyndrom(n))
    s = "1562"
    s2 = s
    s2[0] = 'x'