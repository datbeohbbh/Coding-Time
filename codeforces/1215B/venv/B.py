import sys
from sys import stdin

#your code goes here
def solve():
    n = int(input())
    a = list(map(int,input().split()))
    sumNeg = [0] * (n + 2)
    sumNeg[0] = 0
    for i in range(1,n + 1) :
        sumNeg[i] = (sumNeg[i - 1] + (1 if a[i - 1] < 0 else 0)) % 2
    cntNeg = 0
    cntPos = 0
    cnt = [0] * 2
    cnt[0] += 1
    for i in range(1,n + 1) :
        cntNeg += cnt[sumNeg[i] ^ 1]
        cntPos += cnt[sumNeg[i]]
        cnt[sumNeg[i]] += 1
    print(cntNeg,cntPos)

def main():
    sys.stdin = open("test.inp", "r")
    solve()

if __name__ == "__main__":
    main()
