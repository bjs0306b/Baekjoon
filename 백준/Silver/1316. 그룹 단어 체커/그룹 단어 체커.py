a = int(input())
CNT = a
for i in range(a):
    b = input()
    for j in range(26):
        cnt = 0
        for k in range(len(b)):
            if b[k] == chr(j+97):
                cnt += 1
        if chr(j+97)*cnt not in b:
            CNT -= 1
            break
  
print(CNT)