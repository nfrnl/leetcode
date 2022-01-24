# 566. Reshape the Matrix
# https://leetcode.com/problems/reshape-the-matrix/

def matrix_reshape(mat: list[list[int]], r: int, c: int) -> list[list[int]]:
    m = len(mat)
    n = len(mat[0])
    if m * n != r * c:
        return mat
    mat_elems = (elem for row in mat for elem in row)
    res = []
    for _ in range(r):
        row = []
        for _ in range(c):
            row.append(next(mat_elems))
        res.append(row)
    return res

if __name__ == '__main__':
    assert matrix_reshape([[1, 2], [3, 4]], 1, 4) == [[1, 2, 3, 4]]
    assert matrix_reshape([[1, 2], [3, 4]], 2, 4) == [[1, 2], [3, 4]]
    assert matrix_reshape([[1, 2, 3], [4, 5, 6]], 5, 8) == [[1, 2, 3], [4, 5, 6]]
