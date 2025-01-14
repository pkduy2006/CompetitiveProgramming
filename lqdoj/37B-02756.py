#Hoán Vị Lớn Nhỏ
#https://lqdoj.edu.vn/problem/maxperm

from itertools import permutations

def convert_to_list(a):
    b = []
    while a > 0:
        b.append(a % 10)
        a = int(a / 10)
    return b

def convert_to_int(c):
    res = 0
    cnt = 1
    for d in c:
        res += d * cnt
        cnt *= 10
    return res

x = int(input())
result = 10000000
e = convert_to_list(x)
all = list(permutations(e))
for f in all:
    g = convert_to_int(f)
    if g > x:
        result = min(g, result)
if result == 10000000:
    print(0)
else:
    print(result)