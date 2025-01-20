# Codeforces Round 900 (Div. 3) C. Vasilije in Cacak
# https://codeforces.com/contest/1878/problem/C

def solve():
    n, k, x = map(int, input().split())
    if (2 * n - k + 1) * k // 2 >= x and x >= k * (k + 1) / 2:
        print("YES")
    else:
        print("NO")
 
ntests = int(input())
while ntests > 0:
    solve()
    ntests -= 1