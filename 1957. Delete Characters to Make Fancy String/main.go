package main

import (
	"fmt"
	"strings"
)

//1957. Delete Characters to Make Fancy String
//A fancy string is a string where no three consecutive characters are equal.
//Given a string s, delete the minimum possible number of characters from s to make it fancy.
//Return the final string after the deletion. It can be shown that the answer will always be unique.

func makeFancyString(s string) string {
	trackOccurs := make(map[int32]int)
	builder := strings.Builder{}
	for _, symbol := range s {
		_, contained := trackOccurs[symbol]
		if !contained {
			clear(trackOccurs)
		}
		trackOccurs[symbol]++
		if trackOccurs[symbol] >= 3 {
			continue
		}
		builder.WriteString(string(symbol))
	}
	return builder.String()
}

func main() {
	str := "aaabaaaa"
	fancy := makeFancyString(str)
	fmt.Println(fancy)
}
