package main

import (
	"fmt"
	"sync"
)

func shouldPrintFizzBuzz(n int) bool {
	return n%3 == 0 && n%5 == 0
}

func shouldPrintFizz(n int) bool {
	return n%3 == 0 && n%5 != 0
}

func shouldPrintBuzz(n int) bool {
	return n%5 == 0 && n%3 != 0
}

func shouldPrintNumber(n int) bool {
	return n%3 != 0 && n%5 != 0
}

type fizzBuzz struct {
	n            int
	fizzChan     chan struct{}
	buzzChan     chan struct{}
	fizzBuzzChan chan struct{}
	numChan      chan int
	doneChan     chan struct{}
}

func NewFizzBuzz(n int) *fizzBuzz {
	return &fizzBuzz{
		n:            n,
		fizzChan:     make(chan struct{}),
		buzzChan:     make(chan struct{}),
		fizzBuzzChan: make(chan struct{}),
		numChan:      make(chan int),
		doneChan:     make(chan struct{}),
	}
}

func (f *fizzBuzz) printFizz() {
	for range f.fizzChan {
		fmt.Println("fizz")
		f.doneChan <- struct{}{}
	}
}

func (f *fizzBuzz) printBuzz() {
	for range f.buzzChan {
		fmt.Println("buzz")
		f.doneChan <- struct{}{}
	}
}

func (f *fizzBuzz) printFizzBuzz() {
	for range f.fizzBuzzChan {
		fmt.Println("fizzBuzz")
		f.doneChan <- struct{}{}
	}
}

func (f *fizzBuzz) printNumber() {
	for number := range f.numChan {
		fmt.Println(number)
		f.doneChan <- struct{}{}
	}
}

func (f *fizzBuzz) cleanupChannels() {
	close(f.numChan)
	close(f.buzzChan)
	close(f.fizzBuzzChan)
	close(f.fizzChan)
	close(f.doneChan)
}

func main() {
	var wg sync.WaitGroup
	fizzBuzzInstance := NewFizzBuzz(15)
	wg.Go(fizzBuzzInstance.printNumber)
	wg.Go(fizzBuzzInstance.printFizz)
	wg.Go(fizzBuzzInstance.printBuzz)
	wg.Go(fizzBuzzInstance.printFizzBuzz)

	for i := 1; i <= fizzBuzzInstance.n; i++ {
		if shouldPrintNumber(i) {
			fizzBuzzInstance.numChan <- i
		}
		if shouldPrintFizz(i) {
			fizzBuzzInstance.fizzChan <- struct{}{}
		}
		if shouldPrintBuzz(i) {
			fizzBuzzInstance.buzzChan <- struct{}{}
		}
		if shouldPrintFizzBuzz(i) {
			fizzBuzzInstance.fizzBuzzChan <- struct{}{}
		}

		<-fizzBuzzInstance.doneChan
	}

	fizzBuzzInstance.cleanupChannels()
	wg.Wait()
}
