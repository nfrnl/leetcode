// 454. 4Sum II
// https://leetcode.com/problems/4sum-ii/

#include <cassert>
#include <unordered_map>
#include <vector>

int fourSumCount(std::vector<int>& nums1, std::vector<int>& nums2, std::vector<int>& nums3, std::vector<int>& nums4) {
    std::unordered_map<int, int> target;
    int count = 0;
    for (const int x : nums1) {
        for (const int y : nums2) {
            ++target[x + y];
        }
    }
    for (const int x : nums3) {
        for (const int y : nums4) {
            count += target[-x - y];
        }
    }
    return count;
}

int main()
{
    {
        std::vector<int> in1{ 1, 2 }, in2{ -2, -1 }, in3{ -1, 2 }, in4{ 0, 2 };
        assert(fourSumCount(in1, in2, in3, in4) == 2);
    }
    {
        std::vector<int> in1{ 0 }, in2{ 0 }, in3{ 0 }, in4{ 0 };
        assert(fourSumCount(in1, in2, in3, in4) == 1);
    }

    return 0;
}
