from sys import stdin

lines = stdin.read().splitlines()
n = int(lines[0])
nums = [[int(v) for v in l.split("-")] for l in lines[1:]]

for i in range(1, n + 1):
    print(i)

for i, j in nums:
    print(i, j)
