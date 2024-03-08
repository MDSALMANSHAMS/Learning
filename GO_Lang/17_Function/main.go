package main

import "fmt"

func main() {
	fmt.Println("Hi")
	greeter()

	var value1 int
	var value2 int

	fmt.Println("Enter value1")
	fmt.Scan(&value1)

	fmt.Println("Enter value2")
	fmt.Scan(&value2)

	result := add(value1, value2)
	fmt.Println("Addition of value1 & value2 is: ", result)

	result2 := proAdd(2, 4, 5, 6, 2)
	fmt.Println("Result: ", result2)
}

func greeter() {
	fmt.Println("welcome to golang")
}

func add(value1 int, value2 int) int {
	return value1 + value2
}

func proAdd(value ...int) int {
	total := 0
	for _, val := range value {
		total += val
	}
	return total
}
