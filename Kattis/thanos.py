from itertools import islice
from sys import stdin
from math import log

nums = ([int(x) for x in l.split(" ")] for l in islice(stdin, 1, None))


def simple(P, R, F):
    d = F // P
    if d == 0 or R == 1:
        return 0
    else:
        return int(log(d, R)) + 1


def brute_force(P, R, F):
    count = 0
    while P <= F:
        P *= R
        count += 1
    return count


for P, R, F in nums:
    print(brute_force(P, R, F))
