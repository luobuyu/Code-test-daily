import sys

sys.stdout = open('in.txt', 'w')

print(100000)
for i in range(1, 100000 + 1):
    print(i * 2, end=' ')
