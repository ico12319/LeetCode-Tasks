package main

import (
	"fmt"
)

//57. Insert Interval
//You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.
//Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).
//Return intervals after the insertion.
//Note that you don't need to modify intervals in-place. You can make a new array and return it.

func binarySearch(intervals [][]int, searched []int) int {
	low := 0
	high := len(intervals) - 1
	for low <= high {
		mid := (low + high) / 2
		if intervals[mid][0] == searched[0] {
			if intervals[mid][1] == searched[1] {
				return mid
			} else if intervals[mid][1] < searched[1] {
				low = mid + 1
			} else {
				high = mid - 1
			}
		} else if intervals[mid][0] < searched[0] {
			low = mid + 1
		} else if intervals[mid][0] > searched[0] {
			high = mid - 1
		}
	}
	return high + 1
}

func overlap(start1 int, end1 int, start2 int, end2 int) bool {
	return start1 < end2 && start2 <= end1
}

func insert(intervals [][]int, newInterval []int) [][]int {
	if len(intervals) == 0 {
		return [][]int{newInterval}
	}
	merged := make([][]int, 0, 8)
	var iter int
	properIndex := binarySearch(intervals, newInterval)
	if properIndex == 0 {
		iter = 0
		merged = append(merged, newInterval)
	} else {
		merged = append(merged, intervals[0])
		iter = 1
	}
	flag := false
	for {
		if properIndex != 0 && iter == properIndex && !flag {
			if overlap(merged[len(merged)-1][0], merged[len(merged)-1][1], newInterval[0], newInterval[1]) {
				merged[len(merged)-1][1] = max(merged[len(merged)-1][1], newInterval[1])
			} else {
				merged = append(merged, newInterval)
			}
			flag = true
		} else {
			if iter >= len(intervals) {
				break
			}
			if overlap(merged[len(merged)-1][0], merged[len(merged)-1][1], intervals[iter][0], intervals[iter][1]) {
				merged[len(merged)-1][1] = max(merged[len(merged)-1][1], intervals[iter][1])
			} else {
				merged = append(merged, intervals[iter])
			}
			iter++
		}
	}
	return merged
}

func main() {
	intervals := [][]int{{1, 5}}
	searched := []int{1, 7}
	merged := insert(intervals, searched)
	fmt.Println(merged)
}
