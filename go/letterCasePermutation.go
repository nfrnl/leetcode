// 784. Letter Case Permutation
// https://leetcode.com/problems/letter-case-permutation/

package main

import (
	"reflect"
	"unicode"
)

func appendRune(s string, r rune) []string {
	if unicode.IsDigit(r) {
		return []string{s + string(r)}
	} else if unicode.IsUpper(r) {
		return []string{s + string(unicode.ToLower(r)), s + string(r)}
	} else {
		return []string{s + string(r), s + string(unicode.ToUpper(r))}
	}
}

func letterCasePermutation(S string) []string {
	result := []string{""}
	for _, r := range S {
		temp := make([]string, 0)
		for _, s := range result {
			temp = append(temp, appendRune(s, r)...)
		}
		result = temp
	}

	return result
}

func main() {
	if (!reflect.DeepEqual(letterCasePermutation("a1b2"), []string{"a1b2", "a1B2", "A1b2", "A1B2"})) ||
		(!reflect.DeepEqual(letterCasePermutation("3z4"), []string{"3z4", "3Z4"})) ||
		(!reflect.DeepEqual(letterCasePermutation("12345"), []string{"12345"})) ||
		(!reflect.DeepEqual(letterCasePermutation("0"), []string{"0"})) {
		panic("")
	}
}
