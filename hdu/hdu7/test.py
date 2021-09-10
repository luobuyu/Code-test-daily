import sys
from math import * 

sys.stdout=open("out.txt", "w")

n = 100
print("  ", end="  ")
for i in range (n):
    print(i+1, end='  ')
print()
for i in range(1, n + 1):
    print(i, end='  ')
    for j in range(1, n + 1):
        if gcd(i, j) > 1:
            print(1, end='  ')
        else:
            print(0, end='  ')
    else:
        print()


