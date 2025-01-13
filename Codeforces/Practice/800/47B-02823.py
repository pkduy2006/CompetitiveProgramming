# Codeforces Round 971 (Div. 4) A. Minimize!
# https://codeforces.com/problemset/problem/2009/A
# 23/50

def solve():
    a, b = map(int, input().split())
    print(b - a)

ntests = int(input())
while ntests > 0:
    solve()
    ntests -= 1