# 374. Guess Number Higher or Lower
# https://leetcode.com/problems/guess-number-higher-or-lower/

def guess(num: int) -> int:
    return 0


def guessNumber(n: int) -> int:
    lt, rt = 1, n
    while (res := guess(pick := (lt + rt) // 2)) != 0:
        if res > 0:
            lt = pick
        else:
            rt = pick
    return pick


if __name__ == '__main__':
    guessNumber(6)
