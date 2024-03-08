package main

import "fmt"

func main() {
	defer fmt.Println("Salman")
	defer fmt.Println("One")
	defer fmt.Println("Two")
	fmt.Println("Hi")

	myDefer()
}

func myDefer() {
	for i := 0; i < 3; i++ {
		defer fmt.Println(i)
	}
}
