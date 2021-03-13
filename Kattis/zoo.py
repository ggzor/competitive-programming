from sys import stdin
from itertools import groupby
from collections import Counter

groups = (Counter(x.split(' ')[-1].lower() for x in g)
          for is_num, g in groupby(map(str.strip, stdin.readlines()), key=str.isnumeric)
          if not is_num)

for i, c in enumerate(groups, 1):
    print('List {}:'.format(i))
    for k, v in sorted(c.items()):
        print('{} | {}'.format(k, v))
