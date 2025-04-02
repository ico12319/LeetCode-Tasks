package main

import "fmt"

//2873. Maximum Value of an Ordered Triplet I
//You are given a 0-indexed integer array nums.
//Return the maximum value over all triplets of indices (i, j, k) such that i < j < k. If all such triplets have a negative value, return 0.
//The value of a triplet of indices (i, j, k) is equal to (nums[i] - nums[j]) * nums[k].

func maxTripletValue(nums []int) int64 {
	var maxSum int64 = 0
	for i := 0; i < len(nums); i++ {
		for j := i + 1; j < len(nums); j++ {
			for k := j + 1; k < len(nums); k++ {
				currSum := int64((nums[i] - nums[j]) * nums[k])
				maxSum = max(maxSum, currSum)
			}
		}
	}
	if maxSum < 0 {
		return 0
	}
	return maxSum
}

func main() {
	nums := []int{12, 6, 1, 2, 7}
	fmt.Println(maxTripletValue(nums))
}
