import sys
from sys import stdin

#your code goes here
def solve():
    na, nb = [int(x) for x in input().split()]
    k, m = [int(x) for x in input().split()]
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    if a[k - 1] < b[nb - m]:
        print("YES")
    else:
        print("NO")

def main():
    #sys.stdin = open("test.inp", "r")
    solve()

if __name__ == "__main__":
    main()
