package main

import "fmt"

//2570. Merge Two 2D Arrays by Summing Values
//You are given two 2D integer arrays nums1 and nums2.
//nums1[i] = [idi, vali] indicate that the number with the id idi has a value equal to vali.
//nums2[i] = [idi, vali] indicate that the number with the id idi has a value equal to vali.
//Each array contains unique ids and is sorted in ascending order by id.
//Merge the two arrays into one array that is sorted in ascending order by id, respecting the following conditions:
//Only ids that appear in at least one of the two arrays should be included in the resulting array.
//Each id should be included only once and its value should be the sum of the values of this id in the two arrays. If the id does not exist in one of the two arrays, then assume its value in that array to be 0.
//Return the resulting array. The returned array must be sorted in ascending order by id.

func mergeArrays(nums1 [][]int, nums2 [][]int) [][]int {
	merged := make([][]int, 0, 8)
	iter1 := 0
	iter2 := 0
	for iter1 < len(nums1) && iter2 < len(nums2) {
		if nums1[iter1][0] == nums2[iter2][0] {
			merged = append(merged, []int{nums1[iter1][0], nums1[iter1][1] + nums2[iter2][1]})
			iter1++
			iter2++
		} else if nums1[iter1][0] < nums2[iter2][0] {
			merged = append(merged, []int{nums1[iter1][0], nums1[iter1][1]})
			iter1++
		} else {
			merged = append(merged, []int{nums2[iter2][0], nums2[iter2][1]})
			iter2++
		}
	}
	for iter1 < len(nums1) {
		merged = append(merged, []int{nums1[iter1][0], nums1[iter1][1]})
		iter1++
	}

	for iter2 < len(nums2) {
		merged = append(merged, []int{nums2[iter2][0], nums2[iter2][1]})
		iter2++
	}
	return merged
}

func main() {
	nums1 := [][]int{{1, 2}, {2, 3}, {4, 5}}
	nums2 := [][]int{{1, 4}, {3, 2}, {4, 1}}

	fmt.Println(mergeArrays(nums1, nums2))
}
