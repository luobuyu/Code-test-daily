ONLINE_JUDGE = 0
if ONLINE_JUDGE == 0:
    import sys
    sys.stdin = open('in.txt', 'r')


tcase = int(input())

for ii in range(tcase):
    x, y = input().strip().split()
    x = bin(int(x, 16))[2:]
    y = bin(int(y, 16))[2:]
    ans = ''
    for i in range(min(len(x), len(y))):
        if x[i] != y[i]:
            break
        ans = ans + (x[i])
    ans = hex(int(ans, 2))[2:]
    print('Case #%d: %s' % (ii+1, ans), end='\n\n')
