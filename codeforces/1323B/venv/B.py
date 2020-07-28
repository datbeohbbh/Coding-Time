import sys
from sys import stdin
import math

#your code goes here
def solve():
    n,m,k = list(map(int,input().split()))
    a = list(map(int,input().split()))
    b = list(map(int,input().split()))
    l = [0] * (n + 2)
    r = [0] * (m + 2)
    i = 0
    while i < n :
        if a[i] == 1 :
            j = i
            while j < n and a[j] == 1 :
                j += 1
            for t in range(1,j - i + 1) :
                l[t] += j - i - t + 1
            i = j
        else :
            i += 1

    i = 0
    while i < m:
        if b[i] == 1 :
            j = i
            while j < m and b[j] == 1 :
                j += 1
            for t in range(1, j - i + 1):
                r[t] += j - i - t + 1
            i = j
        else :
            i += 1
    ans = 0
    sqrtK = int(math.sqrt(k))
    for x in range(1,min(n + 1,sqrtK + 1)) :
        if k % x == 0 :
            y = int(k / x)
            if y <= m :
                ans += l[x] * r[y]
            if x != y and x <= m and y <= n:
                ans += l[y] * r[x]
    print(ans)
def main():
    sys.stdin = open("test.inp", "r")
    solve()

if __name__ == "__main__":
    main()
