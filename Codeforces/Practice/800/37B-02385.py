# Good Bye 2024: 2025 is NEAR A. Tender Carpenter
# https://codeforces.com/contest/2053/problem/A

def check(x, y):
    if 2 * min(x, y) <= max(x, y):
        return False
    return True

def solve():
    n = int(input())
    a = list(map(int, input().split()))
    res = False

    for i in range(0, n - 1):
        if check(a[i], a[i + 1]) == True:
            res = True
            break
    if res == False:
        print("NO")
    else:
        print("YES")

ntests = int(input())
while ntests > 0:
    solve()
    ntests -= 1