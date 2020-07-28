import sys
import array

ONL = "__ONLINE_JUDGE__"
OFL = "__main__"

if __name__ == OFL :
    sys.stdin = open('test.inp','r')
    sys.stdout = open('test.out','w')

n,k = [int(x) for x in input().split()]
a = array.array('i',[int(x) for x in input().split()])
a = sorted(a)

if k == 0 :
    if a[0] == 1 :
        print(-1)
        sys.exit()
    else :
        print(a[0] - 1)
        sys.exit()

k -= 1
if k == n - 1 :
    print(a[k])
    sys.exit()
else :
    if a[k] == a[k + 1] :
        print(-1)
        sys.exit()
    else :
        print(a[k])
        sys.exit()