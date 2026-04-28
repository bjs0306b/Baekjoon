import math

def sosu(a):
    for i in range(2, a):
        if a % i == 0:
            return 0
    return 1



t = int(input())

for i in range(t):
    
    n = int(input())
    
    arr = []
    for j in range(int(n/2), 1, -1):
        if sosu(j) and sosu(n-j):
            print(j, n-j)
            break
            