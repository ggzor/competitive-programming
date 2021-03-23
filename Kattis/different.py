from sys import stdin

for l in stdin:
    x, y = [int(s) for s in l.split(" ")]
    print(abs(x - y))
