package main

import "fmt"

func main() {
	fmt.Println("Maps notes")

	Languages := make(map[string]string)

	Languages["py"] = "Python"
	Languages["rb"] = "Ruby"
	Languages["js"] = "JavaScript"

	fmt.Println("Map list", Languages)
	fmt.Println("Map index", Languages["js"])

	delete(Languages, "rb")
	fmt.Println("New map list", Languages)

	// Loop for iterating map elements
	for key, value := range Languages {
		fmt.Printf("Key for %v, value is %v\n", key, value)
	}

}
