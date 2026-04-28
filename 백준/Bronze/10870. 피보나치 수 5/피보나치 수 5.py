a = int(input())

a1 = 0
a2 = 1

for i in range(a):
    tmp = a2
    a2 = a1 + a2
    a1 = tmp
    
print(a1)