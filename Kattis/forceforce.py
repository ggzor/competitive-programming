from subprocess import run
from random import randint, randrange


def run_with(n, p, times, caps):
    return run(
        ["python", "force.py"],
        capture_output=True,
        input=f'{n} {p}\n{" ".join(map(str, times))}\n{" ".join(map(str, caps))}',
        encoding="ascii",
    ).stdout


for _ in range(20):
    n = randint(2, 10)
    p = randrange(20, 60)
    times = [randint(1, 8) for _ in range(n)]
    caps = [randint(1, 8) for _ in range(n - 1)]
    print(f"{n:2} {times} {caps} {p} = {run_with(n, p, times, caps)}")
