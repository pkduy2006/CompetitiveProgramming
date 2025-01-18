# Codeforces Round 966 (Div. 3) A. Primary Task
# https://codeforces.com/contest/2000/problem/A

def solve():
    a = input()
    if int(a) < 102:
        print("NO")
    else:
        if a[0] == '1' and a[1] == '0':
            b = int(a[2:])
            if b >= 2 and a[2] != '0':
                print("YES")
            else:
                print("NO")
        else:
            print("NO")

ntests = int(input())
while ntests > 0:
    solve()
    ntests -= 1