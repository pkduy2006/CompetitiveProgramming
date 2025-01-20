# Codeforces Round 981 (Div. 3) B - Sakurako and Water
# https://codeforces.com/contest/2033/problem/B

def solve():
    n = int(input())
    a = []
    for i in range(n):
        b = list(map(int, input().split()))
        a.append(b)
    
    zahlen = [0] * n * 2
    res = 0
    for i in range(n):
        for j in range(n):
            if a[i][j] < 0:
                zahlen[i - j + n] = min(zahlen[i - j + n], a[i][j])
    for i in zahlen:
        res -= i
    print(res)

ntests = int(input())
while ntests > 0:
    solve()
    ntests -= 1