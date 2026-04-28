a = input()
cnt = 0
for i in range(len(a)):
    if a[i] == "S":
        cnt += 8
    elif a[i] == "T" or a[i] == "U" or a[i] == "V":
        cnt += 9
    elif a[i] == "X" or a[i] == "Y" or a[i] == "Z" or a[i] == "W":
        cnt += 10
    else:
        cnt += (ord(a[i])-65) // 3 + 3
print(cnt)