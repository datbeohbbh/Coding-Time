import sys
from sys import stdin

#your code goes here
def solve():
    n = int(input())
    dict = {}
    for i in range(1,2048):
        tmp = ""
        for j in range(0,12) :
            tmp += str(((i >> j) & 1))
        tmp = tmp[::-1]
        val = int(tmp)
        if val <= n :
            if val in dict : # has_key was removed from python 3.x
                dict[val] += 1
            else :
                dict[val] = 1
    print(len(dict))

def main():
    #sys.stdin = open("test.inp", "r")
    solve()

if __name__ == "__main__":
    main()
