
def f(n,x):
    #n为待转换的十进制数，x为机制，取值为2-16
    b=[]
    while True:
        s=n//x  # 商
        y=n%x  # 余数
        b=b+[y]
        if s==0:
            break
        n=s
    b.reverse()
    sum = 0
    for i in b:
        sum = sum + i
    return sum

def root(n, k):
    if n < k:
        return n
    else:
        return root(f(n, k), k)

while True:
    x, y, k = map(int, input().split())
    print(root(x ** y, k))
    
