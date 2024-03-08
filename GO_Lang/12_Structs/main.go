package main

import "fmt"

func main() {
	fmt.Println("Structs notes")

	salman := User{"Salman Shams", "ss@ss.com", true, 22}
	fmt.Println(salman)
	fmt.Printf("%+v", salman)

}

type User struct {
	Name   string
	Email  string
	Status bool
	Age    int
}
