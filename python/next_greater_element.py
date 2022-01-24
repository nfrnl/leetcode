# 496. Next Greater Element I
# https://leetcode.com/problems/next-greater-element-i/

def nextGreaterElement(nums1: list[int], nums2: list[int]) -> list[int]:
    stack = []
    next_greater = {}
    for x in nums2:
        while len(stack) > 0 and stack[-1] < x:
            next_greater[stack.pop()] = x
        stack.append(x)
    for x in stack:
        next_greater[x] = -1
    result = []
    for x in nums1:
        result.append(next_greater[x])
    return result


if __name__ == '__main__':
    assert nextGreaterElement([4, 1, 2], [1, 3, 4, 2]) == [-1, 3, -1]
    assert nextGreaterElement([2, 4], [1, 2, 3, 4]) == [3, -1]
    assert nextGreaterElement([15, 6, 0, 1, 7], [6, 4, 3, 1, 5, 7, 2, 0, 15]) == [-1, 7, 15, 5, 15]
