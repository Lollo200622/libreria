#ifndef BOOK_HPP            
#define BOOK_HPP

#include <string>
#include <iostream>

class Libro {
private:
    // int quantita;
    //std::string titolo;
    //std::string autore;
    //std::string dataPubblicazione;
    //std::string tipoCopertina;
    //double prezzo;

   

public:
        Libro(const std::string& titolo, const std::string& autore, const std::string& dataPubblicazione, const std::string& tipoCopertina, int quantita, double prezzo );
        int getId() const;
        std::string getTitolo() const;
        std::string getAutore() const;
        std::string getDataPubblicazione() const;
        std::string getTipoCopertina() const;
        void setId(int newid);
        void setTipoCopertina(const std::string& tipo);
        void setTitolo(const std::string& newTitolo);
        void setAutore(const std::string& newAutore);
        void setDataPubblicazione(const std::string& newDataPubblicazione);
        friend std::ostream& operator<<(std::ostream& os, const Libro& libro);
        int id;
        double prezzo;
        std::string titolo;
        int quantita;
        //std::string titolo;
        std::string autore;
        std::string dataPubblicazione;
        std::string tipoCopertina;
        //double prezzo;

        void setQuantita(int quantita);
        int getQuantita() const; 
        double getPrezzo() const ;
        void setPrezzo(double nuovoPrezzo);
        void stampa() const;
};

#endif /* BOOK_HPP */
