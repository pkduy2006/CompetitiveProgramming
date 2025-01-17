# Codeforces Round 970 (Div. 3) B. Square or Not
# https://codeforces.com/problemset/problem/2008/B
# 25/50

def solve():
    n = int(input())
    s = input()

    if n == 4 and s == '1111':
        print("YES")
    else:
        i = 0
        while i < n and s[i] == '1':
            i += 1
        if (i - 1) * (i - 1) == n:
            print("Yes")
        else:
            print("No")

ntests = int(input())
while ntests > 0:
    solve()
    ntests -= 1