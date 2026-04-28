a,b=input().split()
c,d=0,0
for i in range(3):
    c+=int(a[i])*(10**i)
    
for i in range(3):
    d+=int(b[i])*(10**i)
    
print(max(c,d))