// 1091. Shortest Path in Binary Matrix
// https://leetcode.com/problems/shortest-path-in-binary-matrix/

package main

type pos struct {
	row int
	col int
}

func max(a, b int) int {
	if a >= b {
		return a
	} else {
		return b
	}
}

func min(a, b int) int {
	if a <= b {
		return a
	} else {
		return b
	}
}

func shortestPathBinaryMatrix(grid [][]int) int {
	n := len(grid) - 1
	if grid[0][0] == 1 || grid[n][n] == 1 {
		return -1
	}

	queue := make([]pos, 1)
	queue[0] = pos{0, 0}
	grid[0][0] = 1

	for len(queue) > 0 {
		curr := queue[0]
		i, j := curr.row, curr.col
		queue = queue[1:]

		if i == n && j == n {
			return grid[n][n]
		}

		for a := max(i-1, 0); a <= min(i+1, n); a++ {
			for b := max(j-1, 0); b <= min(j+1, n); b++ {
				if grid[a][b] == 0 {
					grid[a][b] = grid[i][j] + 1
					queue = append(queue, pos{a, b})
				}
			}
		}
	}

	return -1
}

func main() {
	if (shortestPathBinaryMatrix([][]int{{0, 1}, {1, 0}}) != 2) ||
		(shortestPathBinaryMatrix([][]int{{0, 0, 0}, {1, 1, 0}, {1, 1, 0}}) != 4) ||
		(shortestPathBinaryMatrix([][]int{{1, 0, 0}, {1, 1, 0}, {1, 1, 0}}) != -1) {
		panic("")
	}
}
