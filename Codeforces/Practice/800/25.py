# Codeforces Round 963 (Div. 2) A. Question Marks
# https://codeforces.com/problemset/problem/1993/A

def solve():
    n = int(input())
    s = input()
    cnta = cntb = cntc = cntd = 0
    for i in s:
        if i == 'A':
            cnta += 1
        elif i == 'B':
            cntb += 1
        elif i == 'C':
            cntc += 1
        elif i == 'D':
            cntd += 1
    print(min(n, cnta) + min(n, cntb) + min(n, cntc) + min(n, cntd))

ntests = int(input())
while ntests > 0:
    solve()
    ntests -= 1