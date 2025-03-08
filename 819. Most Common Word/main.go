package main

import (
	"fmt"
	"strings"
	"unicode"
)

//819. Most Common Word
//Given a string paragraph and a string array of the banned words banned, return the most frequent word that is not banned. It is guaranteed there is at least one word that is not banned, and that the answer is unique.
//The words in paragraph are case-insensitive and the answer should be returned in lowercase.

func mostCommonWord(paragraph string, banned []string) string {
	paragraph = strings.ToLower(paragraph)
	words := strings.FieldsFunc(paragraph, func(r rune) bool {
		return !unicode.IsDigit(r) && !unicode.IsLetter(r)
	})
	freq := make(map[string]int)
	seen := make(map[string]int)
	for _, bann := range banned {
		seen[bann]++
	}
	for _, word := range words {
		freq[word]++
	}

	maxFreq := 0
	mostCommon := ""
	for key, value := range freq {
		_, contained := seen[key]
		if value > maxFreq && !contained {
			mostCommon = key
			maxFreq = value
		}
	}
	return mostCommon
}

func main() {
	paragraph := "Bob hit a ball, the hit BALL flew far after it was hit."
	banned := []string{"hit"}
	mostCommon := mostCommonWord(paragraph, banned)
	fmt.Println(mostCommon)
}
