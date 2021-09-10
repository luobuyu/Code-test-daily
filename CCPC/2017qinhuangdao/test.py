from random import randint
import sys
import random
sys.stdin = open('out.txt', 'r')
sys.stdout = open('in.txt', 'w')

# for i in range(1000000):
#     print(random.randint(1, 100000000),' ',random.randint(1, 100000000))
for i in range(1000000):
    n, m = map(int, input().split())
    print(n + m)
