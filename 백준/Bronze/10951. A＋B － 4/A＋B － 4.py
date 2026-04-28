import sys
while(1):
    arr=list(map(int, sys.stdin.readline().split()))
    if len(arr)==0:
        break
    print(arr[0]+arr[1])
    
        