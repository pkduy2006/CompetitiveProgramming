# Codeforces Round 964 (Div. 4) A. A+B Again?
# https://codeforces.com/problemset/problem/1999/A
# 29/50

def solve():
    n = int(input())
    print(n % 10 + (n // 10))

ntests = int(input())
while ntests > 0:
    solve()
    ntests -= 1