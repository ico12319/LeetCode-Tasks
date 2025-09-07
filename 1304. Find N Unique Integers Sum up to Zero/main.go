package main

import "fmt"

//1304. Find N Unique Integers Sum up to Zero
//Given an integer n, return any array containing n unique integers such that they add up to 0.

func sumZero(n int) []int {
	sumZeroArr := make([]int, 0)

	if (n & 1) != 0 {
		sumZeroArr = append(sumZeroArr, 0)
	}

	currNumber := n

	for len(sumZeroArr) < n {
		positiveAddition := currNumber
		negativeAddition := -currNumber

		sumZeroArr = append(sumZeroArr, positiveAddition)
		sumZeroArr = append(sumZeroArr, negativeAddition)

		currNumber--
	}

	return sumZeroArr
}

func main() {
	n := 7
	fmt.Print(sumZero(n))
}
