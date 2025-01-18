# Codeforces Round 957 (Div. 3) A. Only Pluses
# https://codeforces.com/problemset/problem/1992/A

def solve():
    a, b, c = map(int, input().split())
    res = 0
    
    for i in range(a, a + 6):
        for j in range(b, b + 6):
            for k in range(c, c + 6):
                if i + j + k - a - b - c > 5:
                    continue
                res = max(res, i * j * k)
    print(res)

ntests = int(input())
while ntests > 0:
    solve()
    ntests -= 1