import sys

with open('in.txt', 'w') as file:
    n = 100000
    file.writelines(n)
    for i in range(n):
        file.writelines(i, end=' ')