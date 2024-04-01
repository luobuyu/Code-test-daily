import sys

sys.stdout = open('in.txt', 'w')

print(400, 1)

for i in range(400):
    print(1000000000, end=' ')