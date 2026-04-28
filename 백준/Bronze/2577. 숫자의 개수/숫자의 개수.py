a = int(input())
b = int(input())
c = int(input())
e = str(a * b * c)
f = len(e)

for i in range(10):
    cnt = 0
    for j in range(f):
        if (e[j] == str(i)):
            cnt += 1
    print(cnt)