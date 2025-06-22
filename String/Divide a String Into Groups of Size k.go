package main

func divideString(s string, k int, fill byte) []string {
	var ans []string
	n := len(s)

	for i := 0; i < n; i += k {
		var result string
		for j := i; j < n && j < i+k; j++ {
			result += string(s[j])
		}

		ans = append(ans, result)
	}

	lastIdx := len(ans) - 1
	lastIdxLength := len(ans[lastIdx])

	if lastIdxLength < k {
		for i := lastIdxLength; i < k; i++ {
			ans[lastIdx] += string(fill)
		}
	}

	return ans
}