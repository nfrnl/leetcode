# 279. Perfect Squares
# https://leetcode.com/problems/perfect-squares/

def numSquares(n: int) -> int:
    p_squares = [x * x for x in range(1, int(n**0.5) + 1)]
    square_sums = [0] + [n] * n
    for i in range(1, len(square_sums)):
        for s in p_squares:
            if s > i:
                break
            square_sums[i] = min(square_sums[i], square_sums[i - s] + 1)
    return square_sums[-1]


if __name__ == '__main__':
    assert numSquares(12) == 3
    assert numSquares(13) == 2
    assert numSquares(22) == 3
    assert numSquares(16) == 1
    assert numSquares(1) == 1
