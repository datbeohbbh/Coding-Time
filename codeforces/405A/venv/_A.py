import sys
sys.stdin = open('test.inp','r')
sys.stdout = open('test.out','w')

n = int(input())
a = [int(x) for x in input().split()]
m = max(a)
gra = [[0 for j in range(n)] for i in range(m)]

for j in range(n) :
    for i in range(a[j]) :
        gra[i][j] = 1

ans = [0] * n

for i in range(m) :
    sum = 0
    for j in range(n - 1,-1,-1) :
        sum += gra[i][j]
    for j in range(n - 1,-1,-1) :
        if sum > 0 :
            ans[j] += 1
        sum -= 1

for res in ans :
    print(res,end=" ")