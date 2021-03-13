from sys import stdin

lines = iter(map(str.rstrip, stdin))

while True:
    n = int(next(lines))

    if n == 0:
        break

    nums = [int(x) for x in next(lines).split(" ")]
    nums.sort()

    s = psum = nums[0] + nums[1]
    for i in range(2, n):
        s += nums[i]
        psum += s

    print(psum)
