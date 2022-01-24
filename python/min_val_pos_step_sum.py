# 1413. Minimum Value to Get Positive Step by Step Sum
# https://leetcode.com/problems/minimum-value-to-get-positive-step-by-step-sum/

def minStartValue(nums: list[int]) -> int:
    running_sum = 0
    min_point = 0
    for x in nums:
        running_sum += x
        min_point = min(min_point, running_sum)
    return -min_point + 1


if __name__ == '__main__':
    assert minStartValue([-3, 2, -3, 4, 2]) == 5
    assert minStartValue([1, 2]) == 1
    assert minStartValue([1, -2, -3]) == 5
