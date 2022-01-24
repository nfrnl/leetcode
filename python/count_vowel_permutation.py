# 1220. Count Vowels Permutation
# https://leetcode.com/problems/count-vowels-permutation/

def count_vowel_permutation(n: int) -> int:
    res_map: dict[str, int] = {'a': 1, 'e': 1, 'i': 1, 'o': 1, 'u': 1}
    for _ in range(n - 1):
        a, e, i, o, u = res_map.values()
        res_map['a'] = e + i + u
        res_map['e'] = a + i
        res_map['i'] = e + o
        res_map['o'] = i
        res_map['u'] = i + o
    return sum(res_map.values()) % (10 ** 9 + 7)


if __name__ == '__main__':
    assert count_vowel_permutation(1) == 5
    assert count_vowel_permutation(2) == 10
    assert count_vowel_permutation(3) == 19
    assert count_vowel_permutation(5) == 68
    assert count_vowel_permutation(144) == 18208803
