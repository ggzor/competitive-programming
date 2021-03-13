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


for l in map(str.strip, stdin):
    if l != "0":
        count = l.find(".", 2) - 1
        dig = l[count]

        # while l[count - 1] != "." and l[count - 1] == "9":
        #     count -= 1

        s = l[2:count]
        if len(s) == 0:
            left = (0, 1)
        else:
            left = (int(s), 10 ** len(s))

        if dig == "9":
            left = (left[0] + 1, left[1])
            right = (0, 1)
        else:
            right = (int(dig), 9 * 10 ** len(s))

        n, d = sim(fsum(left, right))
        print(n, d, sep="/")
    else:
        break
