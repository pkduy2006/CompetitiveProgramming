# Increasing Array
# https://cses.fi/problemset/task/1094

n = int(input())
x = map(int, input().split())
a = list(x)
pre = -1
res = 0
for b in a:
    if pre == -1:
        pre = b
    else:
        if b < pre:
            res += pre - b
            b = pre
        else:
            pre = b
print(res)