# Weird Algorithm
# https://cses.fi/problemset/task/1068  

res = []
n = int(input())
res.append(n)
while n != 1:
    if n % 2 == 0:
        n /= 2
        n = int(n)
    else:
        n *= 3
        n += 1
    res.append(n)
print(*res)