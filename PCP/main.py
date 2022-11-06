l = ['aaaaa, 11', 'baaaa, 10', 'aaaaa, 2']

l.sort(key=lambda x: x.split(',')[1])
print(l)