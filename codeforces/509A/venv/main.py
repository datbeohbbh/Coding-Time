import sys

def solve():
    ans = 1
    n = int(input())
    a = [[0] * n for i in range(n)]
    for i in range(n) :
        a[0][i] = a[i][0] = 1
    for i in range(1,n):
        for j in range(1,n) :
            a[i][j] = a[i - 1][j] + a[i][j - 1]
            ans = max(ans,a[i][j])
    print(ans)

if __name__ == "__ONLINE_JUDGE__" :
    sys.stdin = open("test.inp","r")

solve()
