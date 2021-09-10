import sys

sys.stdin = open('in.txt', 'r')

t = int(input())
bits = [1] * 1500
for i in range(1, 1200):
    bits[i] = bits[i - 1] * 2
for i in range(t):
    n, m = map(int, input().split(' '))
    if n % m == 0:
        print(n // m)
    else:
        s = str(bin(n))
        ans = 0
        for i in range(len(s) - 1, -1, -1):
            if (bits[i] - 1) * m < n:
                # 该位必须存在
                n = n % bits[i]
                ans = ans + bits[i]
        print(int(ans))


