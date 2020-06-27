import sys
from sys import stdin

inf = 1000000000

#your code goes here
def solve():
    n = int(input())
    a = list(map(int,input().split()))
    max_pref = [0] * n
    max_suff = [0] * n
    min_pref = [0] * n
    min_suff = [0] * n

    for i in range(n) :
        max_pref[i] = max((max_pref[i - 1] if i > 0 else -inf),a[i])
        min_pref[i] = min((min_pref[i - 1] if i > 0 else inf),a[i])

    for i in range(n - 1,0,-1) :
        max_suff[i] = max((max_suff[i + 1] if i < n - 1 else -inf),a[i])
        min_suff[i] = min((min_suff[i + 1] if i < n - 1 else inf),a[i])

    ans = inf
    for i in range(n) :
        mx = max(max_pref[i - 1] if i > 0 else -inf,max_suff[i + 1] if i < n - 1 else -inf)
        mi = min(min_pref[i - 1] if i > 0 else inf,min_suff[i + 1] if i < n - 1 else inf)
        ans = min(ans,mx - mi)

    print(ans)

def main():
    sys.stdin = open("test.inp", "r")
    solve()

if __name__ == "__main__":
    main()
