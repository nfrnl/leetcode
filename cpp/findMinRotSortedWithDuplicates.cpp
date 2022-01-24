// 154. Find Minimum in Rotated Sorted Array II
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/

#include <vector>
#include <cassert>
#include <cstddef>

int findMinWithDuplicates(const std::vector<int>& nums) {
	if (nums.size() == 1) {
		return nums[0];
	}
	std::size_t l = 0;
	std::size_t r = nums.size() - 1;
	while (l < r) {
		std::size_t mid = l + (r - l) / 2;
		if (nums[mid] > nums[r]) {
			l = mid + 1;
		}
		else if (nums[mid] < nums[r]) {
			r = mid;
		}
		else {
			r--;
		}
	}
	return nums[l];
}

int main()
{
	assert(findMinWithDuplicates({ 4, 5, 6, 7, 0, 1, 4 }) == 0);
	assert(findMinWithDuplicates({ 0, 1, 4, 4, 5, 6, 7 }) == 0);
	assert(findMinWithDuplicates({ 1, 3, 5 }) == 1);
	assert(findMinWithDuplicates({ 2, 2, 2, 0, 1 }) == 0);
	assert(findMinWithDuplicates({ 3, 3, 1, 3 }) == 1);
	
	return 0;
}
