# 201. Bitwise AND of Numbers Range
# https://leetcode.com/problems/bitwise-and-of-numbers-range/

def rangeBitwiseAnd(left: int, right: int) -> int:
    if left == right:
        return left
    leftmost_bit = right.bit_length()
    leftmost_diff_bit = (left ^ right).bit_length()
    str_result = f'{right:b}'[:leftmost_bit - leftmost_diff_bit] + '0' * leftmost_diff_bit
    return int(str_result, 2)


if __name__ == '__main__':
    assert rangeBitwiseAnd(5, 7) == 4
    assert rangeBitwiseAnd(0, 0) == 0
    assert rangeBitwiseAnd(0, 1) == 0
    assert rangeBitwiseAnd(1, 2147483647) == 0
