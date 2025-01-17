# Permutations
# https://cses.fi/problemset/task/1070

n = int(input())
if 2 <= n < 4:
    print("NO SOLUTION")
else:
    res = []
    for i in range(2, n + 1, 2):
        res.append(i)
    for i in range(1, n + 1, 2):
        res.append(i)
    print(*res)