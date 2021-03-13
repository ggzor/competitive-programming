from sys import stdin

fs = [int(x) for x in stdin.readlines()[1].split(" ")]
n = len(fs)


def combs(data, s, i):
    if i == len(data):
        return 0

    total = 0

    for x in range(i, len(data)):
        newSum = s + data[x]

        if newSum >= 200:
            total += newSum

        total += combs(data, newSum, x + 1)

    return total


def solve(fs):
    memo = [None] * len(fs)
    for i in range(len(fs) - 1, -1, -1):
        x = fs[i]
        acc = x if x >= 200 else 0
        scount = 1 if x >= 200 else 0
        l = [] if x >= 200 else [x]

        for j in range(i + 1, len(fs)):
            for y in memo[j][1]:
                v = x + y
                if v >= 200:
                    acc += v
                    scount += 1
                else:
                    l.append(v)

        if i + 1 < len(fs):
            if memo[i + 1][0] > 0:
                acc += 2 * memo[i + 1][0] + x * memo[i + 1][2]
                scount += 2 * memo[i + 1][2]

        memo[i] = (acc, l, scount)

    return memo[0][0]


# result = combs(fs, 0, 0)
# print(result)

print(solve(fs))
