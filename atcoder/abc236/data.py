with open('./in.txt', 'w') as file:
    file.write('100000\n')
    for i in range(100000):
        file.write('1000000000 ')