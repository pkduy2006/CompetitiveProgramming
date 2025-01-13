# Codeforces Round 970 (Div. 3) A. Sakurako's Exam
# https://codeforces.com/problemset/problem/2008/A
# 26/50

def solve():
    a, b = map(int, input().split())
    
    if a % 2 == 1:
        print("NO")
    else:
        if b % 2 == 0:
            print("YES")
        else:
            if a >= 2:
                print("YES")
            else:
                print("NO")

ntests = int(input())
while ntests > 0:
    solve()
    ntests -= 1