// package main

// import (
// 	"fmt"
// 	"log"
// 	"net/http"

// 	"github.com/gorilla/mux"
// )

// func main() {
// 	fmt.Println("Hi")
// 	greeting()

// 	r := mux.NewRouter()
// 	r.HandleFunc("/", webHome).Methods("GET")

// 	log.Fatal(http.ListenAndServe(":4000", r))
// }

// func greeting() {
// 	fmt.Println("welcom to golang")
// }

// func webHome(w http.ResponseWriter, r *http.Request) {
// 	w.Write([]byte("<h1>good luck</h1>"))

// }

package main

import (
	"encoding/json"
	"fmt"
	"log"
	"net/http"

	"github.com/gorilla/mux"
)

func main() {
	fmt.Println("Module")

	greeting()

	r := mux.NewRouter()
	r.HandleFunc("/", server).Methods("GET")
	r.HandleFunc("/", addWord).Methods("POST")

	log.Fatal(http.ListenAndServe(":4444", r))

}

var course = []string{}

func greeting() {
	fmt.Println("welcome")
}

func server(w http.ResponseWriter, r *http.Request) {
	w.Write([]byte("<h1>How u doing</h1>"))

}

func addWord(w http.ResponseWriter, r *http.Request) {
	fmt.Println("write any word")

	w.Header().Set("Content-Type", "applicatioan/json")
	_ = json.NewDecoder(r.Body).Decode(&course)

	//rand.Seed(time.Now().UnixNano())
	//course.courseId = strconv.Itoa(rand.Intn(100))
	//course = append(course)
	json.NewEncoder(w).Encode(course)
	return

}
