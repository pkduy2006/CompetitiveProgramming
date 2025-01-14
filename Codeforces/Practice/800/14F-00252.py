# Codeforces Round 975 (Div. 2) A. Max Plus Size
# https://codeforces.com/problemset/problem/2019/A
# 16/50

def solve():
    n = int(input())
    a = list(map(int, input().split()))
    res = 0
    for i in range(len(a)):
        if len(a) % 2 == 1:
            if i % 2 == 0:
                res = max(res, a[i] + len(a) // 2 + 1)
            else:
                res = max(res, a[i] + len(a) // 2)
        else:
            res = max(res, a[i] + len(a) // 2)
    print(res)

ntests = int(input())
while ntests > 0:
    solve()
    ntests -= 1