# Testing Round 19 (Div. 3) A. Alternating Sum of Numbers
# https://codeforces.com/problemset/problem/2010/A
# 21/50

def solve():
    n = int(input())
    a = list(map(int, input().split()))
    res = 0
    for i in range(len(a)):
        if i % 2 == 0:
            res += a[i]
        else:
            res -= a[i]
    print(res)

ntests = int(input())
while ntests > 0:
    solve()
    ntests -= 1