Develop a Library class that contains a collection of books (Book objects). Implement methods to add a book, remove a book, and display all books.

Sviluppare una classe Library che contenga una raccolta di libri (oggetti Book). Implementare metodi per aggiungere un libro, rimuovere un libro e visualizzare tutti i libri.

- classe Libro:
  * getter e setter per i vari campi
    - id univoco
    - titolo
    - autore
    - data pubblicazione
  * costruttore
  * stampa (operator<<)


- classe Libreria:
  * possibilità di stampare tutti i libri presenti
  * possibilità di ricercare i libri in base ad un campo (e.g., autore, titolo, anche con sottostringhe)
  * possibilità di registrare un nuovo libro
  * possibilità di modificare un libro (dato l'id)
  * possibilità di eliminare un libro
  - salvare libri usando std::map<int, Libro> 