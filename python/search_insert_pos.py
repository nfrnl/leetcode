# 35. Search Insert Position
# https://leetcode.com/problems/search-insert-position/

def searchInsert(nums: list[int], target: int) -> int:
    lt, rt = 0, len(nums)
    mid = rt // 2
    while lt < rt:
        if nums[mid] == target:
            return mid
        elif nums[mid] > target:
            rt = mid
        else:
            lt = mid + 1
        mid = lt + (rt - lt) // 2
    return mid


if __name__ == '__main__':
    assert searchInsert([1, 3, 5, 6], 5) == 2
    assert searchInsert([1, 3, 5, 6], 2) == 1
    assert searchInsert([1, 3, 5, 6], 7) == 4
    assert searchInsert([1, 3, 5, 6], 0) == 0
    assert searchInsert([1], 0) == 0
