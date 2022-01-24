// 240. Search a 2D Matrix II
// https://leetcode.com/problems/search-a-2d-matrix-ii/

#include <cassert>
#include <vector>

bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
	int i = 0;
	int j = matrix[0].size() - 1;

	while ((i < matrix.size()) && (j >= 0)) {
		if (target < matrix[i][j]) {
			j--;
		} else if (target > matrix[i][j]) {
			i++;
		} else {
			return true;
		}
	}

	return false;
}

int main() {
	const std::vector<std::vector<int>> mat = {
		{1, 4, 7, 11, 15},
		{2, 5, 8, 12, 19},
		{3, 6, 9, 16, 22},
		{10, 13, 14, 17, 24},
		{18, 21, 23, 26, 30}
	};
	assert(searchMatrix(mat, 5) == true);
	assert(searchMatrix(mat, 20) == false);
	
	return 0;
}
