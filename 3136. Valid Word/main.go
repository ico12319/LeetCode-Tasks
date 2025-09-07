package main

import "fmt"

type set[T comparable] struct {
	elements map[T]struct{}
}

func new[T comparable]() *set[T] {
	return &set[T]{
		elements: make(map[T]struct{}),
	}
}

func (s *set[T]) construct(arr []T) {
	for _, elem := range arr {
		s.add(elem)
	}
}

func (s *set[T]) add(elem T) {
	s.elements[elem] = struct{}{}
}

func (s *set[T]) contains(elem T) bool {
	_, contains := s.elements[elem]
	return contains
}

func (s *set[T]) remove(elem T) {
	if !s.contains(elem) {
		return
	}

	delete(s.elements, elem)
}

func isDigit(c rune) bool {
	return c >= '0' && c <= '9'
}

func isLetter(c rune) bool {
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
}

func isValid(word string) bool {
	if len(word) < 3 {
		return false
	}

	vowelsMap := new[rune]()
	vowelsMap.construct([]rune{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'})

	var containsVowel bool
	var containsConsonant bool

	for _, character := range word {
		isVowel := vowelsMap.contains(character)

		if !isDigit(character) && !vowelsMap.contains(character) && !isLetter(character) {
			return false
		}

		if isVowel {
			containsVowel = true
		}

		if !isVowel && isLetter(character) {
			containsConsonant = true
		}
	}

	return containsConsonant && containsVowel

}

func main() {
	word := "234Adas"
	fmt.Print(isValid(word))
}
