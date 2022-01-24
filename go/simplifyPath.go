// 71. Simplify Path
// https://leetcode.com/problems/simplify-path/

package main

import "strings"

func simplifyPath(path string) string {
	splitPath := strings.Split(path, "/")
	stack := make([]string, 0)
	stackLen := 0
	for _, d := range splitPath {
		switch d {
		case "":
			continue
		case ".":
			continue
		case "..":
			if stackLen > 0 {
				stackLen--
			}
		default:
			stackLen++
			if stackLen > len(stack) {
				stack = append(stack, d)
			} else {
				stack[stackLen-1] = d
			}
		}
	}
	return "/" + strings.Join(stack[:stackLen], "/")
}

func main() {
	if (simplifyPath("/home/") != "/home") ||
		(simplifyPath("/../") != "/") ||
		(simplifyPath("/home//foo/") != "/home/foo") ||
		(simplifyPath("/a/./b/../../c/") != "/c") {
		panic("")
	}
}
