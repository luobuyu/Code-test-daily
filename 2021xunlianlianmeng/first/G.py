from math import factorial, log, log10

ONLINE_JUDGE = False
if ONLINE_JUDGE == False:
    import sys
    sys.stdin = open("in.txt", 'r')


n = int(input())
a = list(map(int, input().strip().split()))
b = [0] * 400
sum = 0
for i in a:
    b[i] = b[i] + 1
    sum = sum + i

ans = - sum * log10(365) + log10(factorial(sum)) + log10(factorial(n)) + log10(factorial(365)) - log10(factorial(n)) - log10(factorial(365 - n))
for i in b:
    if i != 0:
        ans = ans - log10(factorial(i))


for j in a:
    ans = ans - log10(factorial(j))

print(ans)
