a,b=map(int, input().split())
arr=list(map(int, input().split()))

c=len(arr)

for i in range(c):
    if (b>arr[i]):
        print(arr[i], end=' ')