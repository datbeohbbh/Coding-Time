import sys
n = int(input())

pos = [0] * (n + 2)

for i in range(1,n + 1):
    a,b = [int(x) for x in input().split()]
    pos[a] = b;

quality = -1
ok = False

for a in range (1,n + 1) :
    if(pos[a] > 0):
        if(quality != -1 and pos[a] < quality):
            ok = True
        quality = max(quality,pos[a])

if(ok == True):
    print("Happy Alex")
else :
    print("Poor Alex")
