package main

import (
	"fmt"
	"sort"
)

//3169. Count Days Without Meetings
//You are given a positive integer days representing the total number of days an employee is available for work (starting from day 1). You are also given a 2D array meetings of size n where, meetings[i] = [start_i, end_i] represents the starting and ending days of meeting i (inclusive).
//Return the count of days when the employee is available for work but no meetings are scheduled.
//Note: The meetings may overlap.

func overlap(start1 int, end1 int, start2 int, end2 int) bool {
	return start1 <= end2 && start2 <= end1
}

func countDays(days int, meetings [][]int) int {
	merged := make([][]int, 0, 8)
	sort.Slice(meetings, func(i int, j int) bool {
		if meetings[i][0] != meetings[j][0] {
			return meetings[i][0] < meetings[j][0]
		} else {
			return meetings[i][1] < meetings[j][1]
		}
	})

	merged = append(merged, meetings[0])

	for i := 1; i < len(meetings); i++ {
		if overlap(merged[len(merged)-1][0], merged[len(merged)-1][1], meetings[i][0], meetings[i][1]) {
			merged[len(merged)-1][0] = min(merged[len(merged)-1][0], meetings[i][0])
			merged[len(merged)-1][1] = max(merged[len(merged)-1][1], meetings[i][1])
		} else {
			merged = append(merged, meetings[i])
		}
	}
	freeDays := 0
	for i := 0; i < len(merged)-1; i++ {
		diff := (merged[i+1][0] - merged[i][1]) - 1
		freeDays += diff
	}
	freeDays += days - merged[len(merged)-1][1]
	freeDays += merged[0][0] - 1
	if freeDays < 0 {
		freeDays = 0
	}
	return freeDays
}

func main() {
	meetings := [][]int{{1, 3}, {2, 4}, {5, 7}, {6, 8}}
	fmt.Println(countDays(10, meetings))
}
