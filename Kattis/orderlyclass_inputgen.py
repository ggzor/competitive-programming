from sys import argv, stderr
import random

N, M, *_ = [int(x) for x in argv[1:]]
d = "".join(chr(c) for i, c in enumerate(range(ord("a"), ord("z") + 1)) if i < 100)

print("dict=", d, file=stderr)

s = "".join(random.choice(d) for _ in range(N))
s2 = s

for _ in range(M):
    a = random.randrange(0, len(s) - 1)
    b = random.randrange(a + 1, min(a + 10, len(s)))
    print("->", a, b, file=stderr)
    s2 = s2[:a] + s2[a:b][::-1] + s2[b:]

print(s)
print(s2)
