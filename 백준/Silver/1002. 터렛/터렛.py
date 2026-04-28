import math
a = int(input())

for i in range(a):
    arr = list(map(int, input().split()))
    
    len1 = math.sqrt((arr[0]-arr[3])**2+(arr[1]-arr[4])**2)
    
    arr2 = []
    arr2.extend([len1, arr[2], arr[5]])
    arr2.sort()
    
    if arr2[0]+arr2[1] > arr2[2]:
        print(2)
    elif arr2[0]+arr2[1] == arr2[2]:
        if len1 == 0:
            print(-1)
        else:
            print(1)
    elif arr2[0]+arr2[1] < arr2[2]:
        print(0)
    