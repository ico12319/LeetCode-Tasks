package main

import (
	"fmt"
	"sync"
)

// You have a function printNumber that can be called with an integer parameter and prints it to the console.
//
//For example, calling printNumber(7) prints 7 to the console.
//You are given an instance of the class ZeroEvenOdd that has three functions: zero, even, and odd. The same instance of ZeroEvenOdd will be passed to three different threads:
//
//Thread A: calls zero() that should only output 0's.
//Thread B: calls even() that should only output even numbers.
//Thread C: calls odd() that should only output odd numbers.

type zeroEvenOdd struct {
	n        int
	zeroChan chan struct{}
	oddChan  chan struct{}
	evenChan chan struct{}
}

func isEven(n int) bool {
	return n%2 == 0
}

func NewZeroEvenOdd(n int) *zeroEvenOdd {
	zeroChan := make(chan struct{}, 1)

	instance := &zeroEvenOdd{
		n:        n,
		zeroChan: zeroChan,
		oddChan:  make(chan struct{}, 1),
		evenChan: make(chan struct{}, 1),
	}

	zeroChan <- struct{}{}

	return instance
}

func (z *zeroEvenOdd) zero(printNumber func(num int)) {
	for i := 1; i <= z.n; i++ {
		<-z.zeroChan
		printNumber(0)
		if isEven(i) {
			z.evenChan <- struct{}{}
		} else {
			z.oddChan <- struct{}{}
		}
	}
}

func (z *zeroEvenOdd) even(printNumber func(num int)) {
	for i := 2; i <= z.n; i += 2 {
		<-z.evenChan
		printNumber(i)
		z.zeroChan <- struct{}{}
	}
}

func (z *zeroEvenOdd) odd(printNumber func(num int)) {
	for i := 1; i < z.n; i += 2 {
		<-z.oddChan
		printNumber(i)
		z.zeroChan <- struct{}{}
	}
}

func printer[T any](arg T) {
	fmt.Println(arg)
}

func main() {
	instance := NewZeroEvenOdd(5)
	wg := &sync.WaitGroup{}
	wg.Add(3)

	go func() {
		defer wg.Done()
		instance.zero(printer)
	}()

	go func() {
		defer wg.Done()
		instance.even(printer)
	}()

	go func() {
		defer wg.Done()
		instance.odd(printer)
	}()

	wg.Wait()
}
