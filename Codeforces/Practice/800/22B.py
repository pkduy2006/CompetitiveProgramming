# Codeforces Round 962 (Div. 3) B. Scale
# https://codeforces.com/problemset/problem/1996/B

def solve():
    n, k = map(int, input().split())
    x = []
    res = []
    for i in range(n):
        s = input()
        x.append(s)
    
    for i in range(1, n + 1, k):
        ans = []
        for j in range(1, n + 1, k):
            ans.append(x[i - 1][j - 1])
        res.append(ans)
    for a in res:
        for b in a:
            print(b, end='')
        print()

ntests = int(input())
while ntests > 0:
    solve()
    ntests -= 1