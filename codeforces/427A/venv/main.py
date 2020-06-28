import sys
sys.stdin = open("test.inp","r")


n = int(input())
a = [int(x) for x in input().split()]

ans = 0
cur_police = 0

for i in range(0,n):
    if a[i] == -1 :
        if cur_police == 0 :
            ans += 1
        else :
            cur_police -= 1
    else :
        cur_police += a[i]

print(ans);