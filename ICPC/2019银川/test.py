import math
import sys

sys.stdout = open('in.txt', 'w')
for i in range(1, 1001):
    for j in range(1, 1001):
        print((i - 1) * 1000 + j, end=' ')
    print()