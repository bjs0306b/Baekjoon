import sys
kg = int(input())
a, b = 0, 0
err = [1, 2, 4, 7]
if kg in err:
    print(-1)
    sys.exit()
    
while kg % 3 != 0 and kg > 0:
    
    kg -= 5
    b += 1
    
while kg >= 15:
    kg -= 15
    b += 3
    
    
a = kg / 3
    
print(int(a+b))

    