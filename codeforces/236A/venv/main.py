a = str(input())
cnt = [0] * 26

for c in a :
    cnt[ord(c) - ord('a')] += 1

ans = 0

for i in range(26):
    if cnt[i] > 0 :
        ans += 1

if ans % 2 == 1 :
    print("IGNORE HIM!")
else :
    print("CHAT WITH HER!")