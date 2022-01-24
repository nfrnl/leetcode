# 1044. Longest Duplicate Substring
# https://leetcode.com/problems/longest-duplicate-substring/

from collections import defaultdict


def rabin_karp_search(text: str, length: int) -> str:
    if length == 0:
        return ''
    q = (1 << 31) - 1   # big prime number
    d = 256             # base (bigger than ord(z))
    h = (1 << 8 * (length - 1)) % q     # used in rolling hash update
    hashes = defaultdict(list)

    t = 0
    for i in range(length):
        t = (d * t + ord(text[i])) % q

    hashes[t].append(0)

    for i in range(len(text) - length):
        t = (d * (t - ord(text[i]) * h) + ord(text[i + length])) % q
        for j in hashes[t]:
            if text[i+1:i+length+1] == (result := text[j:j+length]):
                return result
        hashes[t].append(i + 1)

    return ''


def longestDupSubstring(s: str) -> str:
    begin, end = 0, len(s)
    result = ''
    while begin + 1 < end:
        mid = (begin + end) // 2
        candidate = rabin_karp_search(s, mid)
        if candidate:
            begin, result = mid, candidate
        else:
            end = mid
    return result


if __name__ == '__main__':
    assert longestDupSubstring('banana') == 'ana'
    assert longestDupSubstring('abcd') == ''
