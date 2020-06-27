
import sys
"""
sys.stdin = open('test.inp','r')
sys.stdout = open('test.out','w')
"""

s = str(input())
n = len(s)

for i in range(0,n):
    for j in range(i + 1,n) :
        for k in range(j + 1,n) :
            for u in range(k + 1,n) :
                for v in range(u + 1,n) :
                    st = s[i] + s[j] + s[k] + s[u] + s[v]
                    if st == "hello" :
                        print("YES")
                        sys.exit()

print("NO")
