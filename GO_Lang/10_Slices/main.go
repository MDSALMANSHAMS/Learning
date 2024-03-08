package main

import (
	"fmt"
	"sort"
)

func main() {
	fmt.Println("Slices Notes")

	var Students = []string{"Ram", "Joy", "Sam", "Ravi"}
	fmt.Println("Student list", Students)
	fmt.Printf("Type of the list is %T\n", Students)

	Students = append(Students, "Ali", "Max")
	fmt.Println("New student list", Students)

	// Slicing
	Students = append(Students[2:4])
	fmt.Println("Sliced student list", Students)

	// 2nd method of creating a Slice
	Grades := make([]int, 4)

	Grades[0] = 76
	Grades[1] = 98
	Grades[2] = 84
	Grades[3] = 71
	fmt.Println("Grades list", Grades)

	Grades = append(Grades, 55, 94)
	fmt.Println("New grades list", Grades)
	fmt.Println(sort.IntsAreSorted(Grades))

	sort.Ints(Grades)
	fmt.Println("Sorted grades list", Grades)
	fmt.Println(sort.IntsAreSorted(Grades))

	// Removing value from Slices, based on index
	var Subjects = []string{"Science", "Maths", "English", "Hindi", "S.S.T", "Computer"}
	index := 2
	fmt.Println("Subject List", Subjects)

	Subjects = append(Subjects[:index], Subjects[index+1:]...)
	fmt.Println("New Subject List", Subjects)
}
