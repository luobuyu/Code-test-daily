import sys

sys.stdout = open("in.txt", "w")

print('[', end='')

for i in range(10**5, 1, -1):
    print(i, end=',')
print(']')
