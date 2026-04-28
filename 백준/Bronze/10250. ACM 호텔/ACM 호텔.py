import math
T = int(input())

for i in range(T):
    a, b, c = map(int, input().split())
    
    if c%a != 0 :
        print(math.ceil(c/a) + c%a*100)
    else:
        print(math.ceil(c/a) + a*100)
    
