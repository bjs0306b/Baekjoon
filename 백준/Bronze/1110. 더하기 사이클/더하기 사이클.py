a=int(input())
b=1
c=a
while ((a%10)*10+(a//10+a%10)%10 != c):
    b+=1
    a= (a%10)*10+(a//10+a%10)%10

print(b)