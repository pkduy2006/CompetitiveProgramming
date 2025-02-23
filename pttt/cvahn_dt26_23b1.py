import math
import sys

sys.stdin = open("Bai1.inp","r")
sys.stdout = open("Bai1.out","w")

t = int(input())
h = int(input())

a = int((t + h) / 2)
b = int((t - h) / 2)

print(a)
print(b)
