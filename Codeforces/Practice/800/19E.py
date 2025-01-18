# Codeforces Round 967 (Div. 2) A. Make All Equal
# https://codeforces.com/contest/2001/problem/A

def solve():
    n = int(input())
    a = list(map(int, input().split()))
    mark = {}
    for i in a:
        mark[i] = 0
    for i in a:
        mark[i] += 1
    cnt = 0
    for i in a:
        cnt = max(cnt, mark[i])
    print(len(a) - cnt)

ntests = int(input())
while ntests > 0:
    solve()
    ntests -= 1