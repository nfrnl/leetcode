# 451. Sort Characters By Frequency
# https://leetcode.com/problems/sort-characters-by-frequency/

from collections import defaultdict
import operator


def frequencySort(s: str) -> str:
    chars = defaultdict(int)
    for c in s:
        chars[c] += 1
    result = str()
    for k, v in sorted(chars.items(), key=operator.itemgetter(1), reverse=True):
        result += k * v
    return result


if __name__ == '__main__':
    assert frequencySort('tree') in {'eert', 'eetr'}
    assert frequencySort('cccaaa') in {'aaaccc', 'cccaaa'}
    assert frequencySort('Aabb') in {'bbAa', 'bbaA'}
