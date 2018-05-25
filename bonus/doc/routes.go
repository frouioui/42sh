package main

import (
	"log"
	"net/http"
)

func home(w http.ResponseWriter, r *http.Request) {

	log.Println("Home access ", r.RemoteAddr)
	tmpl.ExecuteTemplate(w, "home.html", nil)
}

func documentation(w http.ResponseWriter, r *http.Request) {

	log.Println("Doc access ", r.RemoteAddr)
	tmpl.ExecuteTemplate(w, "documentation.html", nil)
}

func download(w http.ResponseWriter, r *http.Request) {

	log.Println("Download from ", r.RemoteAddr)
	http.Redirect(w, r, "/", http.StatusSeeOther)
}

func about(w http.ResponseWriter, r *http.Request) {

	log.Println("About access ", r.RemoteAddr)
	tmpl.ExecuteTemplate(w, "about.html", nil)
}
