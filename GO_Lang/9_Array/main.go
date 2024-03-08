package main

import "fmt"

func main() {
	fmt.Println("Array Notes")

	var Students [5]string

	Students[0] = "Ram"
	Students[1] = "Joy"
	Students[3] = "Sam"
	Students[4] = "Ravi"

	fmt.Println("Students list", Students)
	fmt.Println("No. of students", len(Students))
}
