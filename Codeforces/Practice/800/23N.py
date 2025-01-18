# Codeforces Round 961 (Div. 2) A. Diagonals
# https://codeforces.com/problemset/problem/1995/A

def solve():
    n, k = map(int, input().split())
    cnt = [0] * (2 * n + 1)
    
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            cnt[i + j] += 1
    cnt.sort(reverse=True)
    res = 0
    it = 0
    #for i in range(n + 1):
        #print(cnt[i], end=' ')
    while k > 0:
        k -= cnt[it]
        it += 1
        res += 1
    print(res)

ntests = int(input())
while ntests > 0:
    solve()
    ntests -= 1