import sys
sys.stdin = open('test.inp','r')
sys.stdout = open('test.out','w')

s = str(input())
t = str(input())
rev_s = s[::-1]
n = len(s)
m = len(t)
if n != m :
    print("NO")
    sys.exit()
else :
    for i in range(n) :
        if rev_s[i] != t[i] :
            print("NO")
            sys.exit()

    print("YES")