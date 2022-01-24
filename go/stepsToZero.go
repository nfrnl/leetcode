// 1342. Number of Steps to Reduce a Number to Zero
// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/

package main

func numberOfSteps(num int) int {
	var i int
	for num != 0 {
		if num%2 == 0 {
			num = num / 2
		} else {
			num--
		}
		i++
	}
	return i
}

func main() {
	if (numberOfSteps(14) != 6) ||
		(numberOfSteps(8) != 4) ||
		(numberOfSteps(123) != 12) {
		panic("")
	}
}
