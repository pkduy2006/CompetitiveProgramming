# Codeforces Round 900 (Div. 3) B. Aleksa and Stack
# https://codeforces.com/contest/1878/problem/B

def solve():
    n = int(input())
    cnt = 1
    for i in range(n):
        print(cnt, end=' ')
        cnt += 2
    print()
 
ntests = int(input())
while ntests > 0:
    solve()
    ntests -= 1