# Missing Number
# https://cses.fi/problemset/task/1083

n = int(input())
a = map(int, input().split())
b = list(a)
b.sort()
res = -1
for i, value in enumerate(b):
    if i + 1 != value:
        res = i + 1
        break
if res == -1:
    res = n
print(res)