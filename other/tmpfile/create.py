import re
import sys


def parserLine(s):
    # Polygon((1, 1), (3, 0), (3, 2), (0, 4))
    s = s.strip().split(' ')
    ret = ''
    for i in range(len(s)):
        if i != 0:
            ret += ','
        ret += '(' + s[i] + ')'
    ret = 'Polygon(' + ret + ')'
    return ret


def parserTag(html):
    l = []
    for i in re.findall(r'polygon points="(.*?)"', html):
        l.append(parserLine(i))
    return l


def main():
    with open('in.txt', 'r') as file:
        html = file.read()
    polygons = parserTag(html)
    with open('out.txt', 'w') as file:
        for polygon in polygons:
            file.write(polygon)
            file.write('\n')


main()
