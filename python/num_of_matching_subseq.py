# 792. Number of Matching Subsequences
# https://leetcode.com/problems/number-of-matching-subsequences/

def num_matching_subseq(s: str, words: list[str]) -> int:
    result = 0
    for w in words:
        pos = -1
        for c in w:
            if (pos := s.find(c, pos + 1)) == -1:
                break
        if pos != -1:
            result += 1
    return result


if __name__ == '__main__':
    assert num_matching_subseq("abcde", ["a", "bb", "acd", "ace"]) == 3
    assert num_matching_subseq("dsahjpjauf", ["ahjpjau", "ja", "ahbwzgqnuk", "tnmlanowax"]) == 2
