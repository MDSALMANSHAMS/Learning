package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	name := "Jojo"
	fmt.Printf("Hi %v \n", name)

	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter your age here:")

	input, _ := reader.ReadString('\n')
	fmt.Println("Thank you for entring your age", input)

}
