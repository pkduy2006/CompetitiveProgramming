# Distinct Numbers
# https://cses.fi/problemset/task/1621/

n = int(input())
a = list(map(int, input().split()))
a.sort()
result = 1
for i in range(1, n, 1):
    if a[i] != a[i - 1]:
        result += 1
print(result)