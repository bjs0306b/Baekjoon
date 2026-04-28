a,b = map(int, input().split())
sum = 1
for i in range(a,a-b,-1):
    sum *= i
for i in range(1,b+1):
    sum //= i

print(int(sum))

