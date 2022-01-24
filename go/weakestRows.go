// 1337. The K Weakest Rows in a Matrix
// https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/

package main

import (
	"reflect"
	"sort"
)

type rowSum struct {
	index int
	sum   int
}

func kWeakestRows(mat [][]int, k int) []int {
	sums := make([]rowSum, len(mat))
	for i, ln := range mat {
		lnSum := 0
		for _, e := range ln {
			lnSum += e
		}
		sums[i] = rowSum{i, lnSum}
	}

	sort.SliceStable(sums, func(i, j int) bool {
		return sums[i].sum < sums[j].sum
	})

	result := make([]int, k)
	for i := 0; i < k; i++ {
		result[i] = sums[i].index
	}
	return result
}

func main() {
	if (!reflect.DeepEqual(kWeakestRows([][]int{
			{1, 1, 0, 0, 0},
			{1, 1, 1, 1, 0},
			{1, 0, 0, 0, 0},
			{1, 1, 0, 0, 0},
			{1, 1, 1, 1, 1},
		}, 3), []int{2, 0, 3})) ||
		(!reflect.DeepEqual(kWeakestRows([][]int{
			{1, 0, 0, 0},
			{1, 1, 1, 1},
			{1, 0, 0, 0},
			{1, 0, 0, 0},
		}, 2), []int{0, 2})) {
		panic("")
	}
}
