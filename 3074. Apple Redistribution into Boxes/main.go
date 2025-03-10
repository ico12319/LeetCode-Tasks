package main

import (
	"fmt"
	"sort"
)

//3074. Apple Redistribution into Boxes
//You are given an array apple of size n and an array capacity of size m.
//There are n packs where the ith pack contains apple[i] apples. There are m boxes as well, and the ith box has a capacity of capacity[i] apples.
//Return the minimum number of boxes you need to select to redistribute these n packs of apples into boxes.
//Note that, apples from the same pack can be distributed into different boxes.

func findTotalApplesCount(apple []int) int {
	count := 0
	for _, apples := range apple {
		count += apples
	}
	return count
}

func minimumBoxes(apple []int, capacity []int) int {
	sort.Slice(capacity, func(i, j int) bool {
		return capacity[i] > capacity[j]
	})
	apples := findTotalApplesCount(apple)
	count := 0
	for i := 0; i < len(capacity); i++ {
		count++
		apples -= capacity[i]
		if apples <= 0 {
			return count
		}
	}
	return count
}

func main() {

	apple := []int{5, 5, 5}
	capacity := []int{2, 4, 2, 7}

	fmt.Println(minimumBoxes(apple, capacity))

}
