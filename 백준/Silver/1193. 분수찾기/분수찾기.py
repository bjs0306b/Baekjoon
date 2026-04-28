import sys
a = int(sys.stdin.readline())
n = 1

while a > n*(n+1)/2:
    n += 1

if n % 2 == 0:
    print('%d/%d' % (a-n*(n-1)/2, n*(n+1)/2-a+1))
else:
    print('%d/%d' % (n*(n+1)/2-a+1, a-n*(n-1)/2))
        