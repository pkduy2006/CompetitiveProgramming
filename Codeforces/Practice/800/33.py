# EPIC Institute of Technology Round Summer 2024 (Div. 1 + Div. 2) A. Upload More RAM
# https://codeforces.com/problemset/problem/1987/A

def solve():
    n, k = map(int, input().split())
    print(1 + (n - 1) * k)

ntests = int(input())
while ntests > 0:
    solve()
    ntests -= 1