from sys import stdin
from math import gcd


def sim(t):
    x, y = t
    g = gcd(x, y)
    return x // g, y // g


def fsum(a, b):
    an, ad = a
    bn, bd = b

    l = (ad * bd) // gcd(ad, bd)

    return an * (l // ad) + bn * (l // bd), l


def go(s):
    minfrac = None
    for i in range(1, len(s) + 1):
        left = s[:-i]
        right = s[-i:]

        if len(left) == 0:
            lnum = 0
        else:
            lnum = int(left)

        left = (lnum, 10 ** len(left))
        right = (int(right), left[1] * (10 ** len(right) - 1))

        result = sim(fsum(left, right))
        if minfrac is None or minfrac[1] > result[1]:
            minfrac = result

        # print(i)
        # print(*left, sep="%")
        # print(*right, sep="%")
        # print(*result, sep="%")
        # print()

    return minfrac


for l in map(str.strip, stdin):
    if l != "0":
        n, d = go(l.split(".")[1])
        print(n, d, sep="/")
    else:
        break
