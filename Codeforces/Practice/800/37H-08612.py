# Codeforces Round 970 (Div. 3) C. Longest Good Array
# https://codeforces.com/problemset/problem/2008/C
# 24/50 

def solve():
    l, r = map(int, input().split())
    left = 1
    right = r - l
    while left <= right:
        mid = (left + right) // 2
        if mid * (mid + 1)  <= 2 * (r - l):
            left = mid + 1
        else:
            right = mid - 1
    print(right + 1)

ntests = int(input())
while ntests > 0:
    solve()
    ntests -= 1