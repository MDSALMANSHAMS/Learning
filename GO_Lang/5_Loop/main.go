// package main

// import "fmt"

// func main() {
// 	numbers := []int{7, 9, 1, 2, 4, 5}

// 	for i := 0; i < len(numbers); i++ {
// 		fmt.Println(numbers[i])

// 	}
// }

package main

import "fmt"

func main() {
	num := []int{2, 4, 5, 6, 7}

	for i := range num {
		value := num[i]
		fmt.Println(value)
	}
}
