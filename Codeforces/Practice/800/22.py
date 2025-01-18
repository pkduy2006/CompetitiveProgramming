# Codeforces Round 965 (Div. 2) A. Find K Distinct Points with Fixed Center
# https://codeforces.com/problemset/problem/1998/A

def solve():
    xc, yc, k = map(int, input().split())
    res = []
    for i in range(1, k // 2 + 1):
        res.append([xc + i, yc + i])
        res.append([xc - i, yc - i])
    if k % 2 == 1:
        res.append([xc, yc])
    for x in res:
        print(f'{x[0]} {x[1]}')

ntests = int(input())
while ntests > 0:
    solve()
    ntests -= 1