import sys

n,m = [int(x) for x in input().split()]

ans = 10000000

for x in range(0,n + 1):
    if(2*x <= n):
        for y in range(0,n + 1):
            if(2*x + y == n):
                if((x + y) % m == 0):
                    ans = min(ans,x + y)


if(ans == 10000000):
    print(-1)
else :
    print(ans)
