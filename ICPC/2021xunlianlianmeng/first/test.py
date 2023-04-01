import math

import sys

sys.stdin = open('in.txt', 'r')
n = int(input())
a = list(map(int, input().strip().split(' ')))
map = [0] * 110
sum = 0
for i in a:
    sum = sum + i

for i in a:
    map[i] = map[i] + 1
ans = math.log10(math.factorial(sum))
for i in a:
    ans = ans - math.log10(math.factorial(i))
for i in range(1, 101):
    ans = ans - math.log10( math.factorial(map[i]))
ans = math.log10(ans) + math.log10(math.factorial(365)) - \
    math.log10(math.factorial(365 - n)) - math.log10((365 ** sum))
print(ans)
