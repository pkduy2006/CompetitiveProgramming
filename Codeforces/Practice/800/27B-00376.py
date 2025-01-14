# Codeforces Round 969 (Div. 2) A. Dora's Set
# https://codeforces.com/problemset/problem/2007/A
# 27/50

def solve():
    l, r = map(int, input().split())
    res = 0
    for i in range(l, r + 1):
        if i % 2 == 1:
            res += 1
    print(res // 2)

ntests = int(input())
while ntests > 0:
    solve()
    ntests -= 1