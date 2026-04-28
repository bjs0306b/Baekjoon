
def sosu(a):
    cnt1 = 0
    for i in range(1,a+1):
        if a % i == 0:
            cnt1 += 1
    return cnt1
    

a = int(input())
b = int(input())

cnt2 = 0

arr = []
for i in range(a, b+1):
    if sosu(i) == 2:
        arr.append(i)
if len(arr)==0:
    print(-1)
else:
    print(sum(arr))
    print(arr[0])

    
