a= int(input())
for i in range(a):
    arr= list(map(int, input().split()))
    add,cnt=0,0
    for j in range(1,arr[0]+1): add+=arr[j]
    aver=float(add)/arr[0]
    
    for k in range(1,arr[0]+1):
        if aver<arr[k]: cnt+=1
    
    print("{0:.3f}%".format(float(cnt/arr[0]*100)))   
