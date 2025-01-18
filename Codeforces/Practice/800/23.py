def solve():
    n = int(input())
    
    if n % 4 == 0:
        print(n // 4)
    else:
        print(n // 4 + 1)

ntests = int(input())
while ntests > 0:
    solve()
    ntests -= 1
