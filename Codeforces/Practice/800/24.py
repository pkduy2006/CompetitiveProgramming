# Codeforces Round 959 sponsored by NEAR (Div. 1 + Div. 2) A. Diverse Game
# https://codeforces.com/problemset/problem/1994/A

def solve():
    n, m = map(int, input().split())
    a = []
    for i in range (n):
        b = list(map(int, input().split()))
        a.append(b)

    if n == m == 1:
        print(-1)
    else:
        for i in range(n):
            for j in range(m):
                print(a[(i + 1) % n][(j + 1) % m], end=' ')
            print()

ntests = int(input())
while ntests > 0:
    solve()
    ntests -= 1