from math import factorial, log10

a = factorial(10) * factorial(365)
b = factorial(5) * factorial(2) * factorial(3) * factorial(358)

c = a / b / (365 ** 10)
print(log10(c))
