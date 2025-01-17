# EPIC Institute of Technology Round August 2024 (Div. 1 + Div. 2) A. Distanced Coloring
# https://codeforces.com/problemset/problem/2002/A

def solve():
    n, m, k = map(int, input().split())
    if n >= k and m >= k:
        print(k * k)
    elif n < k and m < k:
        print(n * m)
    elif n < k:
        print(n * k)
    else:
        print(m * k)

ntests = int(input())
while ntests > 0:
    solve()
    ntests -= 1