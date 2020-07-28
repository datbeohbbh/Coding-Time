import sys
sys.stdin = open('test.inp','r')
sys.stdout = open('test.out','w')

m,s = [int(x) for x in input().split()]

if m > 1 and s == 0 :
    print("-1 -1")
    sys.exit()

f = [[[0] *(s + 1) for j in range(10)] for i in range(0,m + 1)]

for j in range(min(10,s + 1)) :
    f[1][j][j] = 1

for i in range(2,m + 1) :
    for j in range(min(10,s + 1)) :
        for k in range(s + 1) :
            if k >= j :
                for t in range(min(10,s + 1)) :
                    f[i][j][k] = f[i][j][k] | f[i - 1][t][k - j]

max_value = []
tmp = s
for i in range(m,0,-1) :
    flag = 0
    for j in range(9,-1,-1) :
        if f[i][j][tmp] == 1 :
            flag = j
            break
    max_value.append(flag)
    tmp -= flag
    if i == m and flag == 0 :
        break

if tmp > 0 :
    print("-1 -1")
    sys.exit()

min_value = []
tmp = s
for i in range(m,0,-1) :
    flag = 0
    t = 0
    if i == m :
        t = 1
    for j in range(t,10) :
        if f[i][j][tmp] == 1 :
            flag = j
            break
    min_value.append(flag)
    tmp -= flag
    if i == m and flag == 0 :
        break

if tmp > 0 :
    print("-1 -1")
    sys.exit()

for i in min_value :
    print(i,end = "")

print(" ",end = "")

for i in max_value :
    print(i,end = "")




