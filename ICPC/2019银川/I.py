x, y, z = input().split(' ')
x = int(x)
y = int(y)


def toTen(z):
    sum = 0
    for i in z:
        sum = sum * x
        if i >= '0' and i <= '9':
            sum = sum + ord(i) - ord('0')
        elif i >= 'A' and i <= 'Z':
            sum = sum + ord(i) - ord('A') + 10
        elif i >= 'a' and i <= 'z':
            sum = sum + ord(i) - ord('a') + 36
    return sum


ten = toTen(z)
ans = []

if ten == 0:
    print(0)
else:
    while ten != 0:
        ans.append(ten % y)
        ten = ten // y
    ans.reverse()
    for i in ans:
        if i >= 0 and i <= 9:
            print(i, end='')
        elif i >= 10 and i <= 35:
            print(chr(ord('A') + i - 10), end='')
        elif i >= 36 and i <= 61:
            print(chr(ord('a') + i - 36), end='')
    print()
