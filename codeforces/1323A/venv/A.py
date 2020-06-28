import sys
from sys import stdin

#your code goes here
def solve():
    test = int(input())
    for numTest in range(0,test) :
        n = int(input())
        a = list(map(int,input().split()))
        pos_even = -1
        pos_odd = []
        for i in range(0,n) :
            if a[i] % 2 == 0 :
                pos_even = i
            else :
                pos_odd.append(i)
        if pos_even > -1 :
            print(1,pos_even + 1,sep="\n")
        elif len(pos_odd) > 1 :
            if(len(pos_odd) % 2 == 1) :
                pos_odd.pop()
            print(len(pos_odd))
            for p in pos_odd :
                print(p + 1,end=" ")
        else :
            print(-1)



def main():
    sys.stdin = open("test.inp", "r")
    solve()

if __name__ == "__main__":
    main()
