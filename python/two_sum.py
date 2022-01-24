# 1. Two Sum
# https://leetcode.com/problems/two-sum/

def twoSum(nums: list[int], target: int) -> list[int]:
    to_add = {}
    for i, x in enumerate(nums):
        if x in to_add.keys():
            return [to_add[x], i]
        to_add[target - x] = i


if __name__ == '__main__':
    assert twoSum([2, 7, 11, 15], 9) == [0, 1]
    assert twoSum([3, 2, 4], 6) == [1, 2]
    assert twoSum([3, 3], 6) == [0, 1]
