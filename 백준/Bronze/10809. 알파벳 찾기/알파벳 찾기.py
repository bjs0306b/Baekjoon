a=str(input())
arr=[]
for i in range (26):
    arr.append(-1)

for j in range(len(a)):
    if arr[ord(a[j])-97] == -1:
        arr[ord(a[j])-97]=j
        
for i in arr:
    print(i, end=' ')