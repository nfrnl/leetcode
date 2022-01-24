# 238. Product of Array Except Self
# https://leetcode.com/problems/product-of-array-except-self/

def productExceptSelf(nums: list[int]) -> list[int]:
    result = [1] * len(nums)
    accumulator = 1
    for i in reversed(range(1, len(nums))):
        accumulator *= nums[i]
        result[i-1] *= accumulator
    accumulator = 1
    for i in range(0, len(nums) - 1):
        accumulator *= nums[i]
        result[i+1] *= accumulator
    return result


if __name__ == '__main__':
    assert productExceptSelf([1, 2, 3, 4]) == [24, 12, 8, 6]
    assert productExceptSelf([-1, 1, 0, -3, 3]) == [0, 0, 9, 0, 0]
