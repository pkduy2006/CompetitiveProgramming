#Educational Codeforces Round 169 (Rated for Div. 2) A. Closest Point
# https://codeforces.com/problemset/problem/2004/A
# 28/50

def solve():
    n = int(input())
    x = list(map(int, input().split()))
    if n > 2 or x[0] + 1 == x[-1]:
        print('NO')
    else:
        print('YES')
ntests = int(input())
while ntests > 0:
    solve()
    ntests -= 1