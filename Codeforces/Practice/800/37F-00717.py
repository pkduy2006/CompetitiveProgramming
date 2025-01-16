# Codeforces Round 968 (Div. 2) B. Turtle and Piggy Are Playing a Game 2
# https://codeforces.com/problemset/problem/2003/B

def solve():
    n = int(input())
    a = list(map(int, input().split()))
    a.sort()
    if len(a) % 2 == 0:
        print(max(a[len(a) // 2 - 1], a[len(a) // 2]))
    else:
        print(a[len(a) // 2])

ntests = int(input())
while ntests > 0:
    solve()
    ntests -= 1