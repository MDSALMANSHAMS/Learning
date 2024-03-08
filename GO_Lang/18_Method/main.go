package main

import "fmt"

func main() {
	fmt.Println("Structs notes")

	salman := User{"Salman Shams", "ss@ss.com", true, 22}
	fmt.Println(salman)
	fmt.Printf("%+v\n", salman)

	salman.getInfo()
}

type User struct {
	Name   string
	Email  string
	Status bool
	Age    int
}

func (u *User) getInfo() {
	fmt.Println("Get user's info: ", u.Email)
}
