from math import log


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


for t in [
    (P, R, F)
    for P in range(1, 200)
    for R in range(1, 200)
    for F in range(1, 200)
    if not (P <= F and R == 1)
]:
    a = simple(*t)
    b = brute_force(*t)
    if a != b:
        print(*t, "->", a, "!=", b)
        break
    else:
        print("OK: ", *t)
