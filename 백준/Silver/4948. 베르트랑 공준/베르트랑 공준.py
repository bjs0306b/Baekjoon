
   

while 1:
    a = int(input())
    
    if a == 0:
        break
    
    arr = [True for i in range(2*a+1)]
    
    arr[0], arr[1] = False, False
    
    for i in range(2*a+1):
        if arr[i]:
            for j in range(i*2, 2*a+1, i):
                arr[j] = False
    cnt = 0
    for i in range(a+1, 2*a+1):
        if arr[i]:
            cnt += 1
    
    print(cnt)