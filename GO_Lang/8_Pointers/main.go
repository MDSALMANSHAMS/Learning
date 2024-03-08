package main

import "fmt"

func main() {
	fmt.Println("Pointer notes")

	a := 23
	var ptr = &a

	fmt.Println(ptr)  // adress
	fmt.Println(*ptr) // exact value

	*ptr = *ptr * 2

	fmt.Println(*ptr)

}
