# VNOI
# USACO 2021 - Open - Silver - Acowdemia
# https://oj.vnoi.info/problem/usaco21os_acow

def check(h):
    cnt = 0
    remain = k * l
    for i in c:
        if i >= h:
            cnt += 1
        else:
            if h - i <= k and h - i <= remain:
                cnt += 1
                remain -= h - i
    return cnt >= h

n, k, l = map(int, input().split())
c = list(map(int, input().split()))

c.sort(reverse=True)
vasen = 0
oikea = n
while vasen <= oikea:
    keskella = (vasen + oikea) // 2
    if check(keskella):
        vasen = keskella + 1
    else:
        oikea = keskella - 1
print(oikea)