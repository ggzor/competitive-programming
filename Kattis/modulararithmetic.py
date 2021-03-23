from sys import stdin

lines = iter(map(lambda s: s.split(" "), stdin))


def egcd(a, b):
    if b == 0:
        return a, 0, 1
    else:
        gcd, y, x = egcd(b, a % b)
        return gcd, x + y * (-(a // b)), y


N = 0
for l in lines:
    if len(l) == 2:
        N = int(l[0])
        if N == 0:
            break
    elif len(l) == 3:
        a, op, b = int(l[0]), l[1], int(l[2])

        if op == "+":
            print((a + b) % N)
        elif op == "-":
            print((a - b) % N)
        elif op == "*":
            print((a * b) % N)
        elif op == "/":
            if b == 0:
                print(-1)
            else:
                g, y, x = egcd(N, b)

                if g != 1:
                    print(-1)
                else:
                    print((a * y) % N)
