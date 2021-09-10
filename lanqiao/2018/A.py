import math

a = 2**20 - 1
b = 2**19

g = math.gcd(a, b)

print(str(a // g) +'/'+str(b // g))