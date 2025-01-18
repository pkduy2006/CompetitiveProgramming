# Codeforces Round 957 (Div. 3) B. Angry Monk
# https://codeforces.com/problemset/problem/1992/B

def solve():
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    
    a.sort()
    res = 0
    for i in range(k - 1):
        res += a[i] - 1
    for i in range(k - 1):
        res += a[i]
    print(res)

ntests = int(input())
while ntests > 0:
    solve()
    ntests -= 1