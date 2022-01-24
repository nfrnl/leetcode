# 151. Reverse Words in a String
# https://leetcode.com/problems/reverse-words-in-a-string/

def reverseWords(s: str) -> str:
        return ' '.join(reversed(s.split()))


if __name__ == '__main__':
    assert reverseWords("the sky is blue") == "blue is sky the"
    assert reverseWords("  hello world  ") == "world hello"
    assert reverseWords("a good   example") == "example good a"
