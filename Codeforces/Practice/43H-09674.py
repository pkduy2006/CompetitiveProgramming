# IAEPC Preliminary Contest (Codeforces Round 999, Div. 1 + Div. 2) B. Kevin and Geometry
# https://codeforces.com/contest/2061/problem/B

def solve():
    n = int(input())
    a = list(map(int, input().split()))
    
    mp = {}
    for x in a:
        mp[x] = 0
    for x in a:
        mp[x] += 1
    res1 = -1
    res2 = -1
    res3 = -1
    res4 = -1
    for x in a:
        if mp[x] >= 2:
            if res1 == -1 and res2 == -1:
                res1 = x
                res2 = x
                mp[x] -= 2
                if mp[x] >= 2:
                    res3 = x
                    res4 = x
                    mp[x] -= 2
            elif res3 == -1 and res4 == -1:
                res3 = x
                res4 = x
                mp[x] -= 2
    if res1 != -1 and res2 != -1 and res3 != -1 and res4 != -1:
        print(res1, res2, res3, res4, end=' ')
        print()
    else:
        remained = []
        for x in a:
            if mp[x] > 0:
                remained.append(x)
                mp[x] -= 1
        remained.sort()
        for i in range(len(remained) - 1):
            if abs(remained[i] - remained[i + 1]) < 2 * res1:
                res3 = remained[i]
                res4 = remained[i + 1]
                break
        if res3 == -1 and res4 == -1:
            print(-1)
        else:
            print(res1, res2, res3, res4, end=' ')
            print()

ntests = int(input())
while ntests > 0:
    solve()
    ntests -= 1