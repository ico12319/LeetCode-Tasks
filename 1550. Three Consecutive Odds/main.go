package main

import "fmt"

//1550. Three Consecutive Odds
//Given an integer array arr, return true if there are three consecutive odd numbers in the array. Otherwise, return false.

func isEven(num int) bool {
	return num&1 == 0
}

func threeConsecutiveOdds(arr []int) bool {
	consecOdds := 0
	for _, num := range arr {
		if !isEven(num) {
			consecOdds++
			if consecOdds == 3 {
				return true
			}
			continue
		}
		consecOdds = 0
	}
	return false
}

func main() {
	fmt.Println(threeConsecutiveOdds([]int{2, 6, 4, 1}))
	fmt.Println(threeConsecutiveOdds([]int{1, 2, 34, 3, 4, 5, 7, 23, 12}))
}
