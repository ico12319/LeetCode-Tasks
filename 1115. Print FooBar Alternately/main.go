package main

//1115. Print FooBar Alternately
//The same instance of FooBar will be passed to two different threads:
//
//thread A will call foo(), while
//thread B will call bar().
//Modify the given program to output "foobar" n times.

import (
	"fmt"
	"sync"
)

type FooBar struct {
	n       int
	fooTurn chan struct{}
	barTurn chan struct{}
}

func NewFooBar(n int) *FooBar {
	return &FooBar{
		n:       n,
		fooTurn: make(chan struct{}, 1),
		barTurn: make(chan struct{}, 1),
	}
}

func (fb *FooBar) Foo(printFoo func()) {
	for i := 0; i < fb.n; i++ {
		// printFoo() outputs "foo". Do not change or remove this line.
		<-fb.fooTurn
		printFoo()
		fb.barTurn <- struct{}{}
	}
}

func (fb *FooBar) Bar(printBar func()) {
	for i := 0; i < fb.n; i++ {
		// printBar() outputs "bar". Do not change or remove this line.
		<-fb.barTurn
		printBar()
		fb.fooTurn <- struct{}{}
	}
}

func genericPrinter(str string) {
	fmt.Print(str)
}

func fooPrinter() {
	genericPrinter("foo")
}

func barPrinter() {
	genericPrinter("bar")
}

func main() {
	fb := NewFooBar(10000)
	wg := sync.WaitGroup{}

	wg.Add(2)
	go func() {
		defer wg.Done()
		fb.Foo(fooPrinter)
	}()

	go func() {
		defer wg.Done()
		fb.Bar(barPrinter)
	}()

	fb.fooTurn <- struct{}{}
	wg.Wait()
}
