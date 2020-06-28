import sys
from sys import stdin

#your code goes here
def solve():
    t = int(input())
    for test in range(0,t):
        n = int(input())
        a = set(map(int,input().split()))
        print(len(a))

def main():
    sys.stdin = open("test.inp", "r")
    solve()

if __name__ == "__main__":
    main()
