x = 59084709587505

a = 0
while x % 3 == 0:
    a = a + 1
    x /= 3
b = 0
c = 0
while x % 5 == 0:
    b = b + 1
    x /= 5
while x % 7 == 0:
    c = c + 1
    x /= 7
print(a, b, c)
