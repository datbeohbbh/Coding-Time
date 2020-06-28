import sys
from sys import stdin

#your code goes here
def solve():
    n = int(input())
    a = list(map(int,input().split()))
    b = [int(x) for x in a]
    b.sort()

    sum_a = [0] * n
    sum_b = [0] * n
    for i in range(n) :
        sum_a[i] = ((sum_a[i - 1] if i > 0 else 0) + a[i])
        sum_b[i] = ((sum_b[i - 1] if i > 0 else 0) + b[i])
    m = int(input())
    for i in range(m) :
        type,l,r = [int(x) for x in input().split()]
        l -= 1
        r -= 1
        if type == 1 :
            print(sum_a[r] - (sum_a[l - 1] if l > 0 else 0))
        else :
            print(sum_b[r] - (sum_b[l - 1] if l > 0 else 0))

def main():
    #sys.stdin = open("test.inp", "r")
    solve()

if __name__ == "__main__":
    main()
