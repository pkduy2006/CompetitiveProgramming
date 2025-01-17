# Codeforces Round 974 (Div. 3) A. Robin Helps
# https://codeforces.com/problemset/problem/2014/A
# 18/50

def solve():
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    res = 0
    cnt = 0
    for x in a:
        if x >= k:
            cnt += x
        if x == 0 and cnt > 0:
            cnt -= 1
            res += 1
    print(res)

ntests = int(input())
while ntests > 0:
    solve()
    ntests -= 1