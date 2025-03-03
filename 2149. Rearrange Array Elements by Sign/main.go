package main

import "fmt"

//2149. Rearrange Array Elements by Sign
//You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.
//You should return the array of nums such that the the array follows the given conditions:
//Every consecutive pair of integers have opposite signs.
//For all integers with the same sign, the order in which they were present in nums is preserved.
//The rearranged array begins with a positive integer.
//Return the modified array after rearranging the elements to satisfy the aforementioned conditions.

func rearrangeArray(nums []int) []int {
	positiveNumbers := make([]int, 0, len(nums)/2)
	negativeNumbers := make([]int, 0, len(nums)/2)
	for _, num := range nums {
		if num >= 0 {
			positiveNumbers = append(positiveNumbers, num)
		} else {
			negativeNumbers = append(negativeNumbers, num)
		}
	}
	iter1 := 0
	iter2 := 0
	iter3 := 0
	for iter3 < len(nums) {
		if iter1 == iter2 {
			nums[iter3] = positiveNumbers[iter1]
			iter3++
			iter1++
		} else {
			nums[iter3] = negativeNumbers[iter2]
			iter3++
			iter2++
		}
	}
	return nums
}

func main() {
	nums := []int{-1, 1}
	nums = rearrangeArray(nums)
	fmt.Println(nums)
}
