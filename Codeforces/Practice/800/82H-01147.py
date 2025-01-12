# Codeforces Round 971 (Div. 4) B. osu!mania
# https://codeforces.com/problemset/problem/2009/B
# 22/50

def solve():
    n = int(input())
    a = []
    for i in range(n):
        b = input()
        a.append(b)
    for i in range(n - 1, -1, -1):
        for j in range(len(a[i])):
            if a[i][j] == '#':
                print(j + 1, end=' ')
                break
    print()

ntests = int(input())
while ntests > 0:
    solve()
    ntests -= 1