# Codeforces Round 968 (Div. 2) A. Turtle and Good Strings
# https://codeforces.com/problemset/problem/2003/A

def solve():
    a = int(input())
    s = input()
    if s[0] == s[-1]:
        print("NO")
    else:
        print("YES")

ntests = int(input())
while ntests > 0:
    solve()
    ntests -= 1