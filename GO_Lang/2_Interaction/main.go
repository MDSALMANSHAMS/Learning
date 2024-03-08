// user greeting
package main

import "fmt"

func main() {
	var userName string
	var userAge int

	fmt.Println("Enter your name:")
	fmt.Scan(&userName)

	fmt.Println("Enter your age:")
	fmt.Scan(&userAge)
	//userAge = 14
	fmt.Printf("Hi %v, your age is %v years", userName, userAge)
}
