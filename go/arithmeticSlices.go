// 413. Arithmetic Slices
// https://leetcode.com/problems/arithmetic-slices/

package main

func numOfSubsequences(length int) int {
	return (length - 2) * (length - 1) / 2
}

func numberOfArithmeticSlices(A []int) int {
	if len(A) < 3 {
		return 0
	}
	result := 0

	currDiff := A[1] - A[0]
	prev := A[1]
	currCnt := 2
	for i := 2; i < len(A); i++ {
		if A[i]-prev == currDiff {
			currCnt++
		} else {
			if currCnt >= 3 {
				result += numOfSubsequences(currCnt)
			}
			currCnt = 2
			currDiff = A[i] - prev
		}
		prev = A[i]
	}
	if currCnt >= 3 {
		result += numOfSubsequences(currCnt)
	}

	return result
}

func main() {
	if (numberOfArithmeticSlices([]int{1, 2, 3, 4}) != 3) ||
		(numberOfArithmeticSlices([]int{1}) != 0) ||
		(numberOfArithmeticSlices([]int{1, 1, 2, 5, 7}) != 0) ||
		(numberOfArithmeticSlices([]int{1, 3, 5, 7, 9}) != 6) ||
		(numberOfArithmeticSlices([]int{7, 7, 7, 7}) != 3) ||
		(numberOfArithmeticSlices([]int{3, -1, -5, -9}) != 3) {
		panic("")
	}
}
