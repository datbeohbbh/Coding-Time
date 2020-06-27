import sys

sys.stdin = open("test.inp","r")

n = int(input())
a = [int(x) for x in input().split()]

cur = 0
ans = 0

for i in range(0,n):
    if i > 0 and a[i] >= a[i - 1] :
        cur += 1
    else :
        cur = 1
    ans = max(ans,cur)

print(ans)
