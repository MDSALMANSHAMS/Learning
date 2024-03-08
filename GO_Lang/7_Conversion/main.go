package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	fmt.Println("Welcome to the Gaming app")

	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the rating from 1 and 5")

	input, _ := reader.ReadString('\n')
	fmt.Printf("Thank you for rating %v", input)

	numRating, err := strconv.ParseFloat(strings.TrimSpace(input), 64)

	if err != nil {
		fmt.Println(err)
	} else {
		fmt.Println("Adding 1 to the input", 1+numRating)
	}
}
