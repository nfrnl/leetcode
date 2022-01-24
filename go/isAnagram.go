// 242. Valid Anagram
// https://leetcode.com/problems/valid-anagram/

package main

import "sort"

func isAnagram(s string, t string) bool {
	var sr, tr []rune
	for _, r := range s {
		sr = append(sr, r)
	}
	for _, r := range t {
		tr = append(tr, r)
	}
	if len(sr) != len(tr) {
		return false
	}
	sort.Slice(sr, func(i, j int) bool {
		return sr[i] < sr[j]
	})
	sort.Slice(tr, func(i, j int) bool {
		return tr[i] < tr[j]
	})
	for i, r := range sr {
		if r != tr[i] {
			return false
		}
	}
	return true
}

func main() {
	if (isAnagram("anagram", "nagaram") != true) ||
		(isAnagram("rat", "car") != false) ||
		(isAnagram("a", "ab") != false) {
		panic("")
	}
}
