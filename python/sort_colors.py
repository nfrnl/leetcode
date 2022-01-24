# 75. Sort Colors
# https://leetcode.com/problems/sort-colors/

def sortColors(nums: list[int]) -> None:
    ones_begin = 0
    twos_begin = 0
    for i in range(len(nums)):
        if nums[i] == 0:
            nums[ones_begin], nums[i] = nums[i], nums[ones_begin]
            if twos_begin > ones_begin:
                nums[twos_begin], nums[i] = nums[i], nums[twos_begin]
            ones_begin += 1
            twos_begin += 1
        elif nums[i] == 1:
            nums[twos_begin], nums[i] = nums[i], nums[twos_begin]
            twos_begin += 1


if __name__ == '__main__':
    a = [2, 0, 2, 1, 1, 0]
    sortColors(a)
    assert a == [0, 0, 1, 1, 2, 2]

    a = [2, 0, 1]
    sortColors(a)
    assert a == [0, 1, 2]

    a = [0]
    sortColors(a)
    assert a == [0]

    a = [1]
    sortColors(a)
    assert a == [1]

    a = [0, 1]
    sortColors(a)
    assert a == [0, 1]
