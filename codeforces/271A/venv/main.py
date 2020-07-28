import sys

#sys.stdin = open("test.inp","r")

y = int(input())

for i in range(y + 1,10000) :
    a = int(i % 10)
    b = int(int(i / 10) % 10)
    c = int(int(i / 100) % 10)
    d = int(int(i / 1000) % 10)
    if a != b and a != c and a != d and b != c and b != d and c != d :
        print(i)
        sys.exit(0)

