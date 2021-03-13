from sys import stdin

nums = [[int(x) for x in l.split(" ")] for l in stdin.readlines()]
_, p = nums[0]
times = nums[1]

print(sum(times) - max(times) + max(times) * p)
