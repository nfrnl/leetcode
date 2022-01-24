// 785. Is Graph Bipartite?
// https://leetcode.com/problems/is-graph-bipartite/

package main

func isBipartite(graph [][]int) bool {
	color := make(map[int]bool)
	queue := make([]int, 0)

	for i := range graph {
		if _, isOk := color[i]; isOk {
			continue
		}
		queue = append(queue, i)

		for len(queue) > 0 {
			node := queue[0]
			coloredIter := !color[node]
			for _, next := range graph[node] {
				if colored, isOk := color[next]; isOk {
					if colored != coloredIter {
						return false
					}
				} else {
					color[next] = coloredIter
					queue = append(queue, next)
				}
			}
			queue = queue[1:]
		}
	}

	return true
}

func main() {
	if (isBipartite([][]int{{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}}) != false) ||
		(isBipartite([][]int{{1, 3}, {0, 2}, {1, 3}, {0, 2}}) != true) {
		panic("")
	}
}
