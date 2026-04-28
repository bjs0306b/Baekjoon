a=int(input())

for i in range(a):
    arr=input()
    b=0
    n=0
    for j in range(len(arr)):
        if arr[j]=='O':
            n+=1
            b+=n
        else:
            n=0
    print(int(b))