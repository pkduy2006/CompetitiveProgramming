# Pinely Round 4 (Div. 1 + Div. 2) A. Maximize the Last Element
# https://codeforces.com/problemset/problem/1991/A

def solve():
    n = int(input())
    a = list(map(int, input().split()))
    
    res = 0
    for i in range(n):
        if i % 2 == 0:
            res = max(res, a[i])
    print(res)

ntests = int(input())
while ntests > 0:
    solve()
    ntests -= 1