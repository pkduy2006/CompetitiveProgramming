# Codeforces Round 974 (Div. 3) B. Robin Hood and the Major Oak
# https://codeforces.com/problemset/problem/2014/B
# 17/50

def solve():
    n, k = map(int, input().split())
    if ((2 * n - k + 1) * k // 2) % 2 == 0:
        print('YES')
    else:
        print('NO')

ntests = int(input())
while ntests > 0:
    solve()
    ntests -= 1