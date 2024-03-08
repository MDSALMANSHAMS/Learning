package main

import "fmt"

func main() {
	var A int
	var B int

	fmt.Println("Enter A")
	fmt.Scan(&A)

	fmt.Println("Enter B")
	fmt.Scan(&B)

	if A > B {
		fmt.Printf(
			"Number A=%v is greater then B=%v",
			A, B,
		)
	} else if A < B {
		fmt.Printf(
			"Number A=%v is smaller then B=%v",
			A, B,
		)
	} else {
		fmt.Printf(
			"Number A and B are equal(%v)",
			A,
		)
	}

}
