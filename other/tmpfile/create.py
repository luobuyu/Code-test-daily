import re
import sys
sys.stdin = open('in.txt', 'r')
s = input()
# Polygon((1, 1), (3, 0), (3, 2), (0, 4))
s = s.strip().split(' ')
ret = ''
for i in range(len(s)):
    if i != 0:
        ret += ','
    ret += '(' + s[i] + ')'
ret = 'Polygon(' + ret + ')'
print(ret)
