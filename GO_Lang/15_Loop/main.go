package main

import "fmt"

func main() {
	fmt.Println("Loop notes......................")

	// method 1
	countrys := []string{"india", "usa", "uk", "koria", "china"}

	for d := 0; d < len(countrys); d++ {
		fmt.Println(countrys[d])
	}

	// method 2
	days := []string{"sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday"}

	for i := range days {
		fmt.Println(days[i])
	}

	// method 3
	students := []string{"Ram", "Joy", "Sam", "Ravi"}

	for index, name := range students {
		fmt.Printf("for index %v, name of student is %v\n", index, name)
	}

}
