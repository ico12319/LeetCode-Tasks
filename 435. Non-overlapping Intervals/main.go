package main

import (
	"fmt"
	"sort"
)

//435. Non-overlapping Intervals
//Given an array of intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.
//Note that intervals which only touch at a point are non-overlapping. For example, [1, 2] and [2, 3] are non-overlapping

func eraseOverlapIntervals(intervals [][]int) int {
	count := 0
	sort.Slice(intervals, func(i, j int) bool {
		return intervals[i][1] < intervals[j][1]
	})

	lastEnd := intervals[0][1]
	for i := 1; i < len(intervals); i++ {
		if intervals[i][0] < lastEnd {
			count++
		} else {
			lastEnd = intervals[i][1]
		}
	}
	return count
}

func main() {
	intervals := [][]int{{2, 3}, {3, 4}, {4, 5}, {1, 10}}
	fmt.Println(eraseOverlapIntervals(intervals))
}
