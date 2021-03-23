from sys import stdin
from operator import itemgetter

(_, _, K), *ps = [[int(x) for x in [i, *l.split(" ")]] for i, l in enumerate(stdin, -1)]

bests = {
    x[0] for i in range(1, 4) for x in sorted(ps, key=itemgetter(i), reverse=True)[:K]
}

print(len(bests))
