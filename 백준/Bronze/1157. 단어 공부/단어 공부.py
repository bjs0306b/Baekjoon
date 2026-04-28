import sys
a=sys.stdin.readline().strip().upper()
b = [0]*26
for i in a:
    b[ord(i)-65]+=1
if b.count(max(b))>1:
    print("?")
else:
    print(chr(b.index(max(b))+65))