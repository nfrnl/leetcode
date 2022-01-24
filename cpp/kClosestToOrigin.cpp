// 973. K Closest Points to Origin
// https://leetcode.com/problems/k-closest-points-to-origin/

#include <algorithm>
#include <cassert>
#include <iterator>
#include <utility>
#include <vector>

using VectorOfVectorsOfInt = std::vector<std::vector<int>>;

VectorOfVectorsOfInt kClosest(VectorOfVectorsOfInt& points, int k) {
    auto computeDistanceToOrigin = [i = 0](const std::vector<int> point) mutable {
        return std::make_pair(point[0] * point[0] + point[1] * point[1], i++);
    };
    std::vector<std::pair<int, int>> distances;
    distances.reserve(points.size());
    std::transform(points.begin(), points.end(), std::back_inserter(distances), computeDistanceToOrigin);
    const std::size_t sort_count = std::min(static_cast<std::size_t>(k), distances.size());
    std::partial_sort(distances.begin(), distances.begin() + sort_count, distances.end(),
        [](std::pair<int, int> lhs, std::pair<int, int> rhs) { return lhs.first < rhs.first; });

    VectorOfVectorsOfInt result;
    result.reserve(sort_count);
    std::for_each(distances.begin(), distances.begin() + sort_count,
        [&result, &points](std::pair<int, int> elem) {result.push_back(std::move(points[elem.second])); });
    return result;
}

int main()
{
    const VectorOfVectorsOfInt v1 = { { 1, 3 }, { -2, 2 } };
    assert(kClosest(v1, 1) == VectorOfVectorsOfInt({ { -2, 2 } }));

    const VectorOfVectorsOfInt v2 = { { 3, 3 }, { 5, -1 }, { -2, 4 } };
    assert(kClosest(v2, 2) == VectorOfVectorsOfInt({ { 3, 3 }, { -2, 4 } }));
	
	return 0;
}
