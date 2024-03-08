package main

import (
	"fmt"
	"math/rand"
	"time"
)

func main() {
	fmt.Println("Switch case nootes")

	rand.Seed(time.Now().UnixNano())
	diceNumber := rand.Intn(6) + 1
	fmt.Println("Dice value is ", diceNumber)

	switch diceNumber {
	case 1:
		fmt.Println("you can move 1 sport, or open")
	case 2:
		fmt.Println("you can move 2 sport")
	case 3:
		fmt.Println("you can move 3 sport")
		fallthrough
	case 4:
		fmt.Println("you can move 4 sport")
		fallthrough
	case 5:
		fmt.Println("you can move 5 sport")
	case 6:
		fmt.Println("you can move 6 sport, and make another dice role")

	}
}
