# 994. Rotting Oranges
# https://leetcode.com/problems/rotting-oranges/

from collections import deque
from itertools import product


def orangesRotting(grid: list[list[int]]) -> int:
    dirs = ((1, 0), (-1, 0), (0, 1), (0, -1))
    cell_queue: deque[tuple[int, int]] = deque()
    fresh_amt = 0
    m = len(grid)
    n = len(grid[0])
    for i, j in product(range(m), range(n)):
        cell = grid[i][j]
        if cell == 1:
            fresh_amt += 1
        elif cell == 2:
            cell_queue.append((i, j))

    minutes = -1
    while cell_queue:
        minutes += 1
        for _ in range(len(cell_queue)):
            x, y = cell_queue.popleft()
            for dx, dy in dirs:
                i = x + dx
                j = y + dy
                if 0 <= i < m and 0 <= j < n and grid[i][j] == 1:
                    fresh_amt -= 1
                    grid[i][j] = 2
                    cell_queue.append((i, j))

    return -1 if fresh_amt > 0 else max(minutes, 0)


if __name__ == '__main__':
    assert orangesRotting([[2, 1, 1], [1, 1, 0], [0, 1, 1]]) == 4
    assert orangesRotting([[2, 1, 1], [0, 1, 1], [1, 0, 1]]) == -1
    assert orangesRotting([[0, 2]]) == 0
