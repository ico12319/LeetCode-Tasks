package main

import (
	"fmt"
	"sync"
)

//1114. Print in Order
//The same instance of Foo will be passed to three different threads.
//Thread A will call first(), thread B will call second(), and thread C will call third(). Design a mechanism and modify the program to ensure that second() is executed after first(), and third() is executed after second().
type FirstPrinter struct{}

func NewFirstPrinter() *FirstPrinter {
	return &FirstPrinter{}
}

func (f *FirstPrinter) Print() {
	fmt.Print("first")
}

type SecondPrinter struct{}

func NewSecondPrinter() *SecondPrinter {
	return &SecondPrinter{}
}

func (s *SecondPrinter) Print() {
	fmt.Print("second")
}

type ThirdPrinter struct{}

func NewThirdPrinter() *ThirdPrinter {
	return &ThirdPrinter{}
}

func (t *ThirdPrinter) Print() {
	fmt.Print("third")
}

type Foo struct {
	firstTurn  chan struct{}
	secondTurn chan struct{}
	thirdTurn  chan struct{}
}

func NewFoo() *Foo {
	f := &Foo{
		firstTurn:  make(chan struct{}, 1),
		secondTurn: make(chan struct{}, 1),
		thirdTurn:  make(chan struct{}, 1),
	}

	f.firstTurn <- struct{}{}
	return f
}

func (f *Foo) first(printFirst func()) {
	<-f.firstTurn
	printFirst()
	f.secondTurn <- struct{}{}
}

func (f *Foo) second(printSecond func()) {
	<-f.secondTurn
	printSecond()
	f.thirdTurn <- struct{}{}
}

func (f *Foo) third(printThird func()) {
	<-f.thirdTurn
	printThird()
}

func main() {
	wg := &sync.WaitGroup{}
	fooInstance := NewFoo()
	wg.Add(3)

	go func() {
		defer wg.Done()
		fooInstance.first(NewFirstPrinter().Print)
	}()

	go func() {
		defer wg.Done()
		fooInstance.second(NewSecondPrinter().Print)
	}()

	go func() {
		defer wg.Done()
		fooInstance.third(NewThirdPrinter().Print)
	}()

	wg.Wait()
}
