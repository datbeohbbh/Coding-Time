import sys
from sys import stdin

#your code goes here
def solve():
    a = list(map(int,input().split()))
    a = list(map(lambda x : int(x / 3),a))
    print(a)

def main():
    #sys.stdin = open("test.inp", "r")
    solve()

if __name__ == "__main__":
    main()
