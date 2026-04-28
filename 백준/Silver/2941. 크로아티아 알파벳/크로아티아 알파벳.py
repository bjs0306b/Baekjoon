import sys
a = list(input())
cnt = 0
for i in range(len(a)-2):
    if a[i] == 'd' and a[i+1] == 'z' and a[i+2] == '=':
        cnt+=1
        a[i], a[i+1], a[i+2] = ' ', ' ', ' '
for i in range(len(a)-1):        
    if a[i] == 'c' and a[i+1] == '=':
        cnt+=1
        a[i], a[i+1] = ' ', ' '
    elif a[i] == 'c' and a[i+1] == '-':
        cnt+=1
        a[i], a[i+1] = ' ', ' '
    elif a[i] == 'd' and a[i+1] == '-':
        cnt+=1
        a[i], a[i+1] = ' ', ' '
    elif a[i] == 'l' and a[i+1] == 'j':
        cnt+=1
        a[i], a[i+1] = ' ', ' '
    elif a[i] == 'n' and a[i+1] == 'j':
        cnt+=1
        a[i], a[i+1] = ' ', ' '
    elif a[i] == 's' and a[i+1] == '=':
        cnt+=1
        a[i], a[i+1] = ' ', ' '
    elif a[i] == 'z' and a[i+1] == '=':
        cnt+=1
        a[i], a[i+1] = ' ', ' '

for i in range(len(a)):
    if a[i] != ' ':
        cnt += 1
print(cnt)