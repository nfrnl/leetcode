# 797. All Paths From Source to Target
# https://leetcode.com/problems/all-paths-from-source-to-target/

def allPathsSourceTarget(graph: list[list[int]]) -> list[list[int]]:
    if not graph:
        return []
    stack = [[0, [0]]]
    result = []
    last_node = len(graph) - 1
    while len(stack) > 0:
        node, path = stack.pop()
        if node == last_node:
            result.append(path)
        for out in graph[node]:
            stack.append([out, path + [out]])
    return result


if __name__ == '__main__':
    assert sorted(allPathsSourceTarget([[1, 2], [3], [3], []])) == sorted([[0, 1, 3], [0, 2, 3]])
    assert sorted(allPathsSourceTarget([[4, 3, 1], [3, 2, 4], [3], [4], []])) == sorted(
        [[0, 4], [0, 3, 4], [0, 1, 3, 4],
         [0, 1, 2, 3, 4], [0, 1, 4]])
    assert sorted(allPathsSourceTarget([[1], []])) == sorted([[0, 1]])
    assert sorted(allPathsSourceTarget([[1, 2, 3], [2], [3], []])) == sorted([[0, 1, 2, 3], [0, 2, 3], [0, 3]])
    assert sorted(allPathsSourceTarget([[1, 3], [2], [3], []])) == sorted([[0, 1, 2, 3], [0, 3]])
    assert sorted(allPathsSourceTarget([[4, 3, 1], [3, 2, 4], [], [4], []])) == sorted(
        [[0, 4], [0, 3, 4], [0, 1, 3, 4], [0, 1, 4]])
