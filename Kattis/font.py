from sys import stdin

abc = "".join(chr(x) for x in range(ord("a"), ord("z") + 1))


def rotate(s, i):
    return (s + s)[i : i + len(s)]


for x in range(25):
    print(rotate(abc, x)[:-2])

exit(1)

ss = stdin.read().splitlines()[1:]
print("\n".join(f'{s:10} {"".join(sorted(s))}' for s in ss))
n = len(ss)

bins = [("0" * n + bin(x)[2:])[-(n + 1) :] for x in range(2 ** n)]

options = []

letters = lambda l: "".join(sorted(set("".join(l))))

for b in bins:
    l = [p for i, p in enumerate(ss) if b[-(i + 1)] == "1"]
    ls = letters(l)

    if ls == abc:
        options.append((l, ls))

print("\n".join(" ".join(l) + " -- " + letters(l[:-1]) for l, _ in options))
