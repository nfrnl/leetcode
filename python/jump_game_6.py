# 1696. Jump Game VI
# https://leetcode.com/problems/jump-game-vi/

from collections import deque


def max_result(nums: list[int], k: int) -> int:
    n = len(nums)
    deq = deque([n - 1])
    for i in reversed(range(0, n - 1)):
        if deq[0] - i > k:
            deq.popleft()
        nums[i] += nums[deq[0]]
        while len(deq) and nums[deq[-1]] <= nums[i]:
            deq.pop()
        deq.append(i)
    return nums[0]


if __name__ == '__main__':
    assert max_result([1, -1, -2, 4, -7, 3], 2) == 7
    assert max_result([10, -5, -2, 4, 0, 3], 3) == 17
    assert max_result([1, -5, -20, 4, -1, 3, -6, -3], 2) == 0
    assert max_result([0, -3, -20, -25, -3, 10], 2) == -13
