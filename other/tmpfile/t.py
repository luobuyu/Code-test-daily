p = 891234941
q = 1123984201
d = 212353
e = 823816093931522017
c = 20190324


def qpow(a, b, mod):
    ans = 1
    tmp = a
    while b:
        if b & 1:
            ans = ans * tmp % mod
        tmp = tmp * tmp % mod
        b = b >> 1
    return ans


print(qpow(c, e, p * q))
