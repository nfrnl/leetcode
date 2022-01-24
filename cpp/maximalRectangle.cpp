// 85. Maximal Rectangle
// https://leetcode.com/problems/maximal-rectangle/

#include <algorithm>
#include <cassert>
#include <vector>

int maximalRectangle(std::vector<std::vector<char>>& matrix) {
    if (matrix.empty()) {
        return 0;
    }
    int rows = matrix.size(), cols = matrix[0].size();
    int rectangle = 0;
    std::vector<std::vector<short>> consec_ones(rows + 1, std::vector<short>(cols + 1));
    for (int i = rows - 1; i >= 0; i--) {
        for (int j = cols - 1; j >= 0; j--) {
            consec_ones[i][j] = matrix[i][j] == '1' ? (consec_ones[i][j + 1] + 1) : 0;
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int width = cols;
            for (int row = i; row < rows && matrix[row][j] == '1'; row++) {
                width = std::min(width, static_cast<int>(consec_ones[row][j]));
                rectangle = std::max(rectangle, (row - i + 1) * width);
            }
        }
    }
    return rectangle;
}

int main()
{
    std::vector<std::vector<char>> input1{
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };
    assert(maximalRectangle(input1) == 6);

    std::vector<std::vector<char>> input2{ { '0' } };
    assert(maximalRectangle(input2) == 0);

    std::vector<std::vector<char>> input3{ { '1' } };
    assert(maximalRectangle(input3) == 1);

    return 0;
}
