# 1338. Reduce Array Size to The Half
# https://leetcode.com/problems/reduce-array-size-to-the-half/

from collections import Counter


def min_set_size(arr: list[int]) -> int:
    counter_items = sorted(Counter(arr).values(), reverse=True)
    arr_sz = len(arr)
    iter_len = arr_sz
    half_len = (arr_sz + 1) // 2
    i = 0
    while iter_len > half_len:
        iter_len -= counter_items[i]
        i += 1
    return i


assert(min_set_size([3, 3, 3, 3, 5, 5, 5, 2, 2, 7]) == 2)
assert(min_set_size([7, 7, 7, 7, 7, 7]) == 1)
assert(min_set_size([1, 9]) == 1)
assert(min_set_size([1000, 1000, 3, 7]) == 1)
assert(min_set_size([1, 2, 3, 4, 5, 6, 7, 8, 9, 10]) == 5)
