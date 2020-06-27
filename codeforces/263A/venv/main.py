a = [[int(x) for x in input().split()] for i in range(5)]

for i in range(5):
    for j in range(5):
        if a[i][j] == 1 :
            row = i + 1
            col = j + 1

print(abs(row - 3) + abs(col - 3))


