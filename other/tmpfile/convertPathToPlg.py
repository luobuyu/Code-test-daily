import re
s = '''
<path d="M143.351 509.685 
L143.351 509.675
L142.6129091 507.8930909
L140.831 507.155
L139.0490909 507.8930909
L138.311 509.675
v3.798907258
L139.0483194 515.2561367
L140.8299095 515.9949998
L140.831 515.995
L142.612926 515.2569019
L143.3509954 513.4869478
L143.351 513.475
v-3.79
z
M140.191 509.6827967 
L140.3778463 509.2299898
L140.8301493 509.0419272
L141.2829562 509.2287735
L141.4710188 509.6810766
L141.2792307 510.1318444
L140.831 510.315
L140.3784176 510.1275341
L140.191 509.6827967
z
M140.1909914 513.4820621 
L140.3784472 513.0295038
L140.8310055 512.8420481
L141.2835638 513.0295039
L141.4710188 513.4810766
L141.2792307 513.9318444
L140.831 514.115
L140.3784176 513.9275341
L140.1909914 513.4820621
z
" style="fill-rule: nonzero; fill:#DA52D4; opacity:0.5; stroke:#09D917; stroke-width:1"></path>
<path d="M142.858421 510.9779444 
L143.241 509.675
L142.858421 508.3720556
L141.8321502 507.4827869
L140.4880212 507.2895303
L139.2527856 507.8536435
L138.5186219 508.9960245
v1.357950924
L139.2527856 511.4963565
L140.4880212 512.0604697
L141.8321502 511.8672131
L142.858421 510.9779444
z
" style="fill-rule: nonzero; fill:#B1C240; opacity:0.5; stroke:#C168CA; stroke-width:1"></path>

'''


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
            print(len(points))
            print(convertListToPoly(points))
            points.clear()
            continue
        elif line[0] == 'M' or line[0] == 'L':
            point = line.strip()[1:].split(' ')
        elif line[0] == 'v':
            point[1] = str(float(point[1]) + float(line.strip()[1:]))
        points.append(point.copy())
    print('-' * 100)
