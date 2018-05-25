package main

import (
	"html/template"
	"log"
	"net/http"
)

var tmpl = template.Must(template.ParseGlob("./*.html"))

func main() {

	log.SetFlags(log.LstdFlags)

	http.HandleFunc("/", home)
	http.HandleFunc("/download", download)
	http.HandleFunc("/documentation", documentation)
	http.HandleFunc("/about", about)

	http.Handle("/static/", http.StripPrefix("/static/", http.FileServer(http.Dir("static"))))

	err := http.ListenAndServe(":8080", nil)
	if err != nil {
		log.Fatal(err.Error())
	}
}
