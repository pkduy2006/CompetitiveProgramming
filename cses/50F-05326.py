# Tower of Hanoi
# https://cses.fi/problemset/task/2165

res = []

def solve(k, x, y, z):
    if k == 1:
        res.append((x, y))
    else:
        solve(k - 1, x, z, y)
        solve(1, x, y, z)
        solve(k - 1, z, y, x)

k = int(input())
solve(k, 1, 3, 2)
print(len(res))
for a, b in res:
    print(a, b)