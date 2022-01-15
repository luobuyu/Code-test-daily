ONLINE_JUDGE = 1
if ONLINE_JUDGE == 0:
    import sys
    sys.stdin = open('in.txt', 'r')
n, m = map(int, input().split())
dis = 1
d = [[0] * n ] * n
print(d)
for i in range(n):
    for j in range(n):
        d[i][j] = float('inf')
for i in range(m):
    u, v = map(int, input().split())
    d[u][v] = d[v][u] = dis
    dis = dis * 2

for k in range(n):
    for i in range(n):
        for j in range(n):
            d[i][j] = min(d[i][j], d[i][k] + d[k][j])
for i in range(1, n):
    if d[0][i] == float('inf'):
        print('-1')
    else:
        print(d[0][i] % 100000)
