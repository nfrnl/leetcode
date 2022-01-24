// 1249. Minimum Remove to Make Valid Parentheses
// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/

package main

func minRemoveToMakeValid(s string) string {
	stack := make([]int, 0)
	result := make([]byte, 0)

	for _, c := range []byte(s) {
		if c == '(' {
			stack = append(stack, len(result))
		} else if c == ')' {
			if l := len(stack); l > 0 {
				stack = stack[:l-1]
			} else {
				continue
			}
		}
		result = append(result, c)
	}

	for i := len(stack) - 1; i >= 0; i-- {
		copy(result[stack[i]:], result[stack[i]+1:])
		result = result[:len(result)-1]
	}

	return string(result)
}

func main() {
	if (minRemoveToMakeValid("lee(t(c)o)de)") != "lee(t(c)o)de") ||
		(minRemoveToMakeValid("a)b(c)d") != "ab(c)d") ||
		(minRemoveToMakeValid("))((") != "") ||
		(minRemoveToMakeValid("(a(b(c)d)") != "a(b(c)d)") ||
		(minRemoveToMakeValid("())()(((") != "()()") {
		panic("")
	}
}
