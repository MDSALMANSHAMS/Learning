package main

import "fmt"

func main() {
	fmt.Println("Loop note 2......................")

	series := 1
	for series < 10 {
		if series == 3 {
			series++
			continue
		} else if series == 8 {
			break
		} else if series == 7 {
			goto lco
		}
		fmt.Println(series)
		series++
	}

	// goto
lco:
	fmt.Println("goto will stop further iteration")

}
