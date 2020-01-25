n = int(input())
mask = int(0)
while n > 0 :
    mask|=int(n % 10)
    n /= 10
if mask^144==0 :
    print("YES")
elif mask^16==0 :
    print("YES")
elif mask^128==0 :
    print("YES")
else :
    print("NO")