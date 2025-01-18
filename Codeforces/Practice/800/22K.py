# Educational Codeforces Round 168 (Rated for Div. 2) A. Strong Password
# https://codeforces.com/problemset/problem/1997/A

def solve():
    s = input()
    
    if len(s) == 1:
        if s != 'a':
            print('a' + s)
        else:
            print('b' + s)
    else:
        pos = 0
        for i in range(len(s) - 1):
            if s[i] == s[i + 1]:
                pos = i
                break
        if s[pos] != s[pos + 1]:
            if (s[pos] == 'a' and s[pos + 1]) == 'b' or (s[pos] == 'b' and s[pos + 1] == 'a'):
                print(s[0] + 'c' + s[1:])
            elif s[pos] == 'a' and s[pos + 1] != 'b':
                print(s[0] + 'b' + s[1:])
            elif s[pos] == 'b' and s[pos + 1] != 'a':
                print(s[0] + 'a' + s[1:])
            elif s[pos] != 'b' and s[pos + 1] == 'a':
                print(s[0] + 'b' + s[1:])
            elif s[pos] != 'a' and s[pos + 1] == 'b':
                print(s[0] + 'a' + s[1:])
            else:
                print(s[0] + 'a' + s[1:])
        else:
            if s[pos] == 'a':
                print(s[:(pos + 1)] + 'b' + s[(pos + 1):])
            else:
                print(s[:(pos + 1)] + 'a' + s[(pos + 1):])


ntests = int(input())
while ntests > 0:
    solve()
    ntests -= 1