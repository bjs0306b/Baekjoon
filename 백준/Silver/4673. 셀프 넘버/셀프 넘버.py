def d(n):
    sum=n
    for i in range(len(str(n))):
        sum+=int(str(n)[i])
    return sum
arr1=[]

for i in range(10000):
    arr1.append(d(i))

for j in range(10000):
    if j not in arr1:
        print(j)