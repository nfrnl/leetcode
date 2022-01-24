// 594. Longest Harmonious Subsequence
// https://leetcode.com/problems/longest-harmonious-subsequence/

package main

func findLHS(nums []int) int {
	result := 0
	numCount := make(map[int]int)
	for _, n := range nums {
		numCount[n]++
		if prevCnt, ok := numCount[n-1]; ok {
			if newRes := numCount[n] + prevCnt; newRes > result {
				result = newRes
			}
		}
		if nextCnt, ok := numCount[n+1]; ok {
			if newRes := numCount[n] + nextCnt; newRes > result {
				result = newRes
			}
		}
	}
	return result
}

func main() {
	if (findLHS([]int{1, 3, 2, 2, 5, 2, 3, 7}) != 5) ||
		(findLHS([]int{1, 2, 3, 4}) != 2) ||
		(findLHS([]int{1, 1, 1, 1}) != 0) {
		panic("")
	}
}
