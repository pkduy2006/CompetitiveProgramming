import sys
sys.stdin = open('luythua.inp', 'r') 
sys.stdout = open('luythua.out', 'w')


s = input()
a = s.split()
x,y = map(int,a)
ans = 2**x
cnt = 3**y

ans1 = ans + cnt
s = str(ans1)
print(s[0])
