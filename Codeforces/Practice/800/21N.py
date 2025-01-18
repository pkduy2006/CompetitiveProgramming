# Codeforces Round 964 (Div. 4) C. Showering
# https://codeforces.com/problemset/problem/1999/C

def solve():
    n, s, m = map(int, input().split())
    tasks = []
    for i in range(n):
        l, r = map(int, input().split())
        tasks.append([l, r])
    
    check = False
    if tasks[0][0] >= s:
        check = True
    if m - tasks[n - 1][1] >= s:
        check = True
    for i in range(1, n):
        if tasks[i][0] - tasks[i - 1][1] >= s:
            check = True
    if check == True:
        print("YES")
    else:
        print("NO")

ntests = int(input())
while ntests > 0:
    solve()
    ntests -= 1