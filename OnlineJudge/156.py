from sys import stdin, stdout
from collections import Counter

original = dict()
pool = set()
repeated = set()

for l in stdin:
    for w in l.strip().split(" "):
        w = w.strip()
        if w != "#" and len(w) > 0:
            sig = "".join(
                map("{0[0]}{0[1]}".format, sorted(Counter(w.lower()).items()))
            )
            if sig not in repeated:
                if sig in pool:
                    pool.remove(sig)
                    repeated.add(sig)
                else:
                    pool.add(sig)
                    original[sig] = w

for x in sorted(map(original.get, pool)):
    print(x)
