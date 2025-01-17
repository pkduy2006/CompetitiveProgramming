# Number Spiral
# https://cses.fi/problemset/task/1071

ntests = int(input())
while ntests > 0:
    ntests -= 1
    y, x = input().split()
    x = int(x)
    y = int(y)
    z = max(x, y)
    value = z ** 2
    if z % 2 == 1:
        value -= abs(1 - y) + abs(z - x)
    else:
        value -= abs(z - y) + abs(1 - x)
    print(value)