a = int(input())

ok = False

for i in range(1,a + 1):
    if a % i == 0 :
        f = True
        tmp = i

        while tmp > 0 :
            if tmp % 10 != 4 and tmp % 10 != 7 :
                f = False
            tmp = int(tmp / 10)

        if f == True :
            ok = True

if ok == True :
    print("YES")
else :
    print("NO")