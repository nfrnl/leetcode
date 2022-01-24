# 1286. Iterator for Combination
# https://leetcode.com/problems/iterator-for-combination/

from itertools import combinations


class CombinationIterator:

    def __init__(self, characters: str, combinationLength: int):
        self.gen = combinations(characters, combinationLength)
        self.next_item = next(self.gen)

    def next(self) -> str:
        result = ''.join(self.next_item)
        try:
            self.next_item = next(self.gen)
        except StopIteration:
            self.next_item = None
        return result

    def hasNext(self) -> bool:
        return self.next_item is not None


if __name__ == '__main__':
    itr = CombinationIterator('abc', 2)
    assert itr.next() == 'ab'
    assert itr.hasNext()
    assert itr.next() == 'ac'
    assert itr.hasNext()
    assert itr.next() == 'bc'
    assert not itr.hasNext()
