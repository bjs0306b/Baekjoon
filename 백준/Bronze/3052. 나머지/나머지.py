arr=[]

for i in range(10):
    arr.append(int(input())%42)
for j in range(9,0,-1):
    if arr.count(arr[j])>1:
        arr.remove(arr[j])
        
print(len(arr))