package main

import "fmt"

func main() {
	var ClintName string
	var ClintAge int
	var ClientWeight float32
	var Vacinated bool

	ClintName = "Jo"
	ClintAge = 34
	ClientWeight = 67.5
	Vacinated = true

	fmt.Printf(
		"%s %v %.2f %v",
		ClintName, ClintAge, ClientWeight, Vacinated,
	)
}
