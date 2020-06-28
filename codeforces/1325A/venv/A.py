import sys
from sys import stdin

#your code goes here
def solve():
    t = int(input())
    for i in range(0,t):
        x = int(input())
        print(1,x - 1,sep=" ",end='\n')

def main():
    #sys.stdin = open("test.inp", "r")
    solve()

if __name__ == "__main__":
    main()
