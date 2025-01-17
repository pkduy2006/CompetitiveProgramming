# Codeforces Round 973 (Div. 2) A. Zhan's Blender
# https://codeforces.com/problemset/problem/2013/A
# 19/50

def solve():
    n = int(input())
    x, y = list(map(int, input().split()))
    z = min(x, y)
    if n % z == 0:
        print(n // z)
    else:
        print(n // z + 1)

ntests = int(input())
while ntests > 0:
    solve()
    ntests -= 1