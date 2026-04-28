import math
T = int(input())

for i in range(T):
    a = int(input())
    b = int(input())
    
    print(int(math.factorial(a+b) / math.factorial(b-1) / math.factorial(a+1)) )
    
    