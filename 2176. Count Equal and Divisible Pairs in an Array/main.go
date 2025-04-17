package main

import "fmt"

//2176. Count Equal and Divisible Pairs in an Array
//Given a 0-indexed integer array nums of length n and an integer k,
//return the number of pairs (i, j) where 0 <= i < j < n,
//such that nums[i] == nums[j] and (i * j) is divisible by k.

func countPairs(nums []int, k int) int {
	seen := make(map[int][]int) // key, indexes
	counter := 0
	for index, num := range nums {
		indexes, isContained := seen[num]
		if isContained {
			for _, idx := range indexes {
				if (idx*index)%k == 0 {
					counter++
				}
			}
		}
		seen[num] = append(seen[num], index)
	}
	return counter
}

func main() {
	nums := []int{3, 1, 2, 2, 2, 1, 3}
	k := 2
	fmt.Println(countPairs(nums, k))
}
