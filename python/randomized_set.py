# 380. Insert Delete GetRandom O(1)
# https://leetcode.com/problems/insert-delete-getrandom-o1/

from random import randint


class RandomizedSet:

    def __init__(self):
        self.value_to_index = {}
        self.index_to_value = []

    def insert(self, val: int) -> bool:
        n = len(self.value_to_index)
        if self.value_to_index.setdefault(val, n) == n:
            self.index_to_value.append(val)
            return True
        return False

    def remove(self, val: int) -> bool:
        if (i := self.value_to_index.pop(val, None)) is not None:
            if len(self.index_to_value) - 1 > i:
                self.index_to_value[i] = last_value = self.index_to_value.pop()
                self.value_to_index[last_value] = i
            else:
                del self.index_to_value[-1]
            return True
        return False

    def getRandom(self) -> int:
        rand_index = randint(0, len(self.index_to_value) - 1)
        return self.index_to_value[rand_index]


if __name__ == '__main__':
    randomizedSet = RandomizedSet()
    assert randomizedSet.insert(1) is True
    assert randomizedSet.remove(2) is False
    assert randomizedSet.insert(2) is True
    assert randomizedSet.getRandom() in {1, 2}
    assert randomizedSet.remove(1) is True
    assert randomizedSet.insert(2) is False
    assert randomizedSet.getRandom() == 2

    anotherSet = RandomizedSet()
    assert anotherSet.remove(0) is False
    assert anotherSet.remove(0) is False
    assert anotherSet.insert(0) is True
    assert anotherSet.getRandom() == 0
    assert anotherSet.remove(0) is True
    assert anotherSet.insert(0) is True

    thirdSet = RandomizedSet()
    assert thirdSet.insert(3) is True
    assert thirdSet.insert(3) is False
    assert thirdSet.getRandom() == 3
    assert thirdSet.getRandom() == 3
    assert thirdSet.insert(1) is True
    assert thirdSet.remove(3) is True
    assert thirdSet.getRandom() == 1
    assert thirdSet.getRandom() == 1
    assert thirdSet.insert(0) is True
    assert thirdSet.remove(0) is True
