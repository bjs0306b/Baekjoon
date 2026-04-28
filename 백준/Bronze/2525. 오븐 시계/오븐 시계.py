a, b=map(int, input().split())
c= int(input())

d,e=c//60,c%60

print((a+d+(b+e)//60)%24, (b+e)%60)
