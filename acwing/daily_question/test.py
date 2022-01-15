import random
s = '500000 '
for i in range(500000):
    s += str(random.randint(0, 10000))
    s += ' '
with open('./in.txt', 'w') as file:
    file.write(s)