// 153. Find Minimum in Rotated Sorted Array
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

#include <vector>
#include <cassert>
#include <cstddef>

int findMin(const std::vector<int>& nums) {
	if (nums.size() == 1) {
		return nums[0];
	}
	std::size_t l = 0;
	std::size_t r = nums.size() - 1;
	while (l < r) {
		if (nums[l] < nums[r]) {
			return nums[l];
		}
		std::size_t mid = l + (r - l) / 2;
		if (nums[mid] > nums[r]) {
			l = mid + 1;
		}
		else {
			r = mid;
		}
	}
	return nums[l];
}

int main()
{
	assert(findMin({ 3, 4, 5, 1, 2 }) == 1);
	assert(findMin({ 4, 5, 6, 7, 0, 1, 2 }) == 0);
	assert(findMin({ 11, 13, 15, 17 }) == 11);
	assert(findMin({ 0, 1, 2, 3, 4, 5, 6, 7 }) == 0);
	assert(findMin({ 2, 3, 1 }) == 1);
	assert(findMin({ 2, 3, 4, 5, 6, 1 }) == 1);
	
	return 0;
}
