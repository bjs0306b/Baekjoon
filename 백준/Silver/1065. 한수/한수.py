a=int(input())
if a>99:
    cnt=99
    for i in range(100,a+1):
        b=str(i)
        if len(b)<4:
            for j in range(len(b)-2):
                if int(b[j])-int(b[j+1]) == int(b[j+1])-int(b[j+2]):
                    cnt+=1
                
    print(cnt)
else:
    print(a)
    
