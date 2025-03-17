package main

import "fmt"

//2206. Divide Array Into Equal Pairs
//You are given an integer array nums consisting of 2 * n integers.
//You need to divide nums into n pairs such that:
//Each element belongs to exactly one pair.
//The elements present in a pair are equal.
//Return true if nums can be divided into n pairs, otherwise return false.

func divideArray(nums []int) bool {
	seen := make(map[int]int)
	for _, num := range nums {
		_, contains := seen[num]
		if !contains {
			seen[num]++
		} else {
			delete(seen, num)
		}
	}
	return len(seen) == 0
}

func main() {
	nums := []int{3, 2, 1}
	fmt.Println(divideArray(nums))
}
