ONLINE_JUDGE = 0
if ONLINE_JUDGE == 0:
    import sys
    sys.stdin = open('in.txt', 'r')

Tcase = int(input())
for tcase in range(1, Tcase+1):
    a = list(map(int, input().strip().split()))
