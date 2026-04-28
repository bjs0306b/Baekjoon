arr1, arr2 = [], []
for i in range(3):
    a, b = map(int, input().split())
    arr1.append(a)
    arr2.append(b)
    
for i in arr1:
    if arr1.count(i) == 2:
        arr1.remove(i)
        arr1.remove(i)

for i in arr2:
    if arr2.count(i) == 2:
        arr2.remove(i)
        arr2.remove(i)

print(arr1[0], arr2[0])
