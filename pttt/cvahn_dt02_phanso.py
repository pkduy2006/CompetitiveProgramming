import re
import sys
from math import gcd

sys.stdin = open("phanso.inp", "r")
sys.stdout = open("phanso.out", "w")

def split(calculation):
    numbers = re.split("\+|\-|\*|:", calculation)
    fractions = []
    for s in numbers:
        tmp = s.find("/")
        fractions.append([int(s[:tmp]), int(s[tmp+1:])])
    
    dau = re.split("1|2|3|4|5|6|7|8|9|0|/", calculation)
    dau = [v for v in dau if v != ""]
    
    return (fractions, dau)

def nhan(x, y):
    return [x[0] * y[0], x[1] * y[1]]
def chia(x, y):
    return [x[0] * y[1], x[1] * y[0]]
def cong(x, y):
    return [x[0]*y[1] + y[0]*x[1], x[1]*y[1]]
def tru(x, y):
    return [x[0]*y[1] - y[0]*x[1], x[1]*y[1]]

s = input()
ps,dau = split(s)

i = 0
while i < len(dau):
    if dau[i] == "*" or dau[i] == ":":
        if dau[i] == "*":
            kq = nhan(ps[i], ps[i+1])
        else:
            kq = chia(ps[i], ps[i+1])
        
        ps = ps[:i] + [kq] + ps[i+2:]
        dau = dau[:i] + dau[i+1:]
        
    else:
        i += 1

while len(dau) > 0:
    if dau[0] == "+":
        kq = cong(ps[0], ps[1])
    else:
        kq = tru(ps[0], ps[1])
    ps = [kq] + ps[2:]
    dau = dau[1:]

u,b = ps[0][0], ps[0][1]

uc = gcd(u, b)

print("%s/%s" % (u // uc, b // uc))
