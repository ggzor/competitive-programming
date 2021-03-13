from itertools import groupby
from os import environ
from subprocess import run
from sys import stdin

nums = [[int(x) for x in l.split(" ")] for l in stdin.readlines()]

n, p = nums[0]
times = nums[1]
cap = nums[2]


def main():
    paddings = [0] * p

    result = None
    for i in range(1, p + 1):
        while (result := run_with(p=i, seq=paddings[:i])) and result.stderr:
            paddings[i - 1] += 1

    print("{:2}".format(sum([len(list(g)) for _, g in groupby(paddings)][:-1])), end="")
    print(
        f" ({[l for l in result.stdout.splitlines() if l.startswith('Result')][0].rsplit('=')[-1].strip()}) >>",
        end="",
    )
    print("".join(map("{:3}".format, paddings)))


def run_with(p, seq):
    text = f'{n} {p}\n{" ".join(map(str, times))}\n{" ".join(map(str, cap))}'
    env = environ.copy()
    env["SEQ"] = "0" + "".join(["0" * x + "1" for x in seq])

    return run(
        ["./sequentialmanufacturing"],
        input=text,
        encoding="ascii",
        capture_output=True,
        env=env,
    )


main()
