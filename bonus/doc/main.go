package main

import (
	"html/template"
	"log"
	"net/http"
)

var tmpl = template.Must(template.ParseGlob("./*.html"))

func home(w http.ResponseWriter, r *http.Request) {

	tmpl.ExecuteTemplate(w, "home.html", nil)
}

func documentation(w http.ResponseWriter, r *http.Request) {

	tmpl.ExecuteTemplate(w, "documentation.html", nil)
}

func download(w http.ResponseWriter, r *http.Request) {

	log.Println("Download [42sh].")
	http.Redirect(w, r, "/", http.StatusSeeOther)
}

func about(w http.ResponseWriter, r *http.Request) {

	tmpl.ExecuteTemplate(w, "about.html", nil)
}

func main() {

	log.SetFlags(log.LstdFlags)

	http.HandleFunc("/", home)
	http.HandleFunc("/download", download)
	http.HandleFunc("/documentation", documentation)
	http.HandleFunc("/about", about)

	http.Handle("/static/", http.StripPrefix("/static/", http.FileServer(http.Dir("static"))))

	http.ListenAndServe(":8080", nil)
}
