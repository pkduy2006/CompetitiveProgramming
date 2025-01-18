# Codeforces Round 966 (Div. 3) B. Seating in a Bus
# https://codeforces.com/contest/2000/problem/B

def solve():
    n = int(input())
    a = list(map(int, input().split()))
    res = True
    mark = [False] * (n + 1)
    mark[a[0] - 1] = True
    for i in range(1, n):
        if mark[a[i] - 2] == True or mark[a[i]] == True:
            mark[a[i] - 1] = True
        else:
            res = False
            break
    #for i in mark:
       # print(i)
    if res == False:
        print("NO")
    else:
        print("YES")
 
ntests = int(input())
while ntests > 0:
    solve()
    ntests -= 1