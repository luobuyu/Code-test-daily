import re
import sys
s = ''
with open('in.txt', 'r') as file:
    s = file.read()
# print(s)

sys.stdout = open('out.txt', 'w')


def convertListToPoly(points):
    poly = ""
    for i, point in enumerate(points):
        if i != 0:
            poly += ','
        poly += '(' + point[0] + ", " + point[1] + ')'
    poly = 'Polygon(' + poly + ')'
    return poly


paths = re.findall(r'\"(M.*?)\"', s, re.MULTILINE | re.DOTALL)
for path in paths:
    points = []
    point = [0, 0]
    for line in path.split('\n'):
        if line == "":
            continue
        if line[0] == 'z':
            points.pop()
            # if (len(points) == 10 or len(points) == 11):
            print(len(points))
            print(convertListToPoly(points))
            points.clear()
            continue
        elif line[0] == 'M' or line[0] == 'L':
            point = line.strip()[1:].split(' ')
        elif line[0] == 'v':
            point[1] = str(float(point[1]) + float(line.strip()[1:]))
        elif line[0] == 'h':
            point[0] = str(float(point[0]) + float(line.strip()[1:]))
        points.append(point.copy())
    print('-' * 100)
