# Codeforces Global Round 27 B. Everyone Loves Tres
# https://codeforces.com/problemset/problem/2035/B

def solve():
    n = int(input())

    res = ""
    if n == 1 or n == 3:
        res = "-1"
    elif n % 2 == 0:
        for i in range(n - 2):
            res += "3"
        res += "66"
    else:
        for i in range(n - 5):
            res += "3"
        res += "36366"
    print(res)

ntests = int(input())
while ntests > 0:
    solve()
    ntests -= 1