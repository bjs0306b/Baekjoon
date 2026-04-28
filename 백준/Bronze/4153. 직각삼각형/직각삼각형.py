while 1:
    a, b, c = map(int, input().split())
    
    if a == 0 and b == 0 and c == 0:
        break
    
    arr = []
    
    arr.append(a)
    arr.append(b)
    arr.append(c)
    
    arr.sort()
    
    if arr[0]**2 + arr[1]**2 == arr[2]**2:
        print('right')
    else:
        print('wrong')