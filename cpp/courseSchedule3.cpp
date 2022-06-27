// 630. Course Schedule III
// https://leetcode.com/problems/course-schedule-iii/

#include <algorithm>
#include <cassert>
#include <queue>
#include <vector>

class Solution {
public:
    int scheduleCourse(std::vector<std::vector<int>>& courses) {
        std::priority_queue<int> taken;

        std::sort(courses.begin(), courses.end(),
                  [](const auto& l, const auto& r){ return l[1] < r[1]; });

        int total_time = 0;
        for (const auto& course : courses) {
            const int duration = course[0];
            const int last_day = course[1];

            if (total_time + duration <= last_day) {
                taken.push(duration);
                total_time += duration;
            } else if (!taken.empty() && taken.top() > duration) {
                total_time -= taken.top();
                total_time += duration;
                taken.pop();
                taken.push(duration);
            }
        }

        return taken.size();
    }
};

int main()
{
    std::vector<std::vector<int>> input1 = {
            {100, 200},
            {200, 1300},
            {1000, 1250},
            {2000, 3200}
    };
    assert(Solution().scheduleCourse(input1) == 3);

    std::vector<std::vector<int>> input2 = {
            {1, 2}
    };
    assert(Solution().scheduleCourse(input2) == 1);

    std::vector<std::vector<int>> input3 = {
            {3, 2},
            {4, 3}
    };
    assert(Solution().scheduleCourse(input3) == 0);

    return 0;
}