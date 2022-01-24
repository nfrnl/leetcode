# 15. 3Sum
# https://leetcode.com/problems/3sum/

import itertools


def threeSum(nums: list[int]) -> list[list[int]]:
    result = set()
    neg = []
    pos = []
    zeroes_count = 0
    for x in nums:
        if x < 0:
            neg.append(x)
        elif x > 0:
            pos.append(x)
        else:
            zeroes_count += 1

    neg_set = set(neg)
    pos_set = set(pos)

    if zeroes_count:
        for n in filter(lambda x: -x in neg_set, pos_set):
            result.add((-n, 0, n))

    if zeroes_count >= 3:
        result.add((0, 0, 0))

    for x, y in itertools.combinations(neg, 2):
        target = -(x + y)
        if target in pos_set:
            result.add(tuple(sorted([x, y, target])))
    for x, y in itertools.combinations(pos, 2):
        target = -(x + y)
        if target in neg_set:
            result.add(tuple(sorted([x, y, target])))

    return result


if __name__ == '__main__':
    assert threeSum([-1, 0, 1, 2, -1, -4]) == [[-1, -1, 2], [-1, 0, 1]]
    assert threeSum([]) == []
    assert threeSum([0]) == []
