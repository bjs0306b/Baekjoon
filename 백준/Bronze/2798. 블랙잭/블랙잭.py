import math
a, b = map(int, input().split())

arr1 = list(map(int, input().split()))
arr2 = []

for i in range(a-2):
    for j in range(1+i,a-1):
        for k in range(1+j,a):
            if arr1[i]+arr1[j]+arr1[k] <= b:
                arr2.append(arr1[i]+arr1[j]+arr1[k])
            
arr3 = []


for i in arr2:
    arr3.append(b-i)

print(b-min(arr3))