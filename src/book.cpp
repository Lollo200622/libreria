#include "book.hpp"



Libro::Libro(const std::string& titolo, const std::string& autore, const std::string& dataPubblicazione, const std::string& tipoCopertina, int quantita,double prezzo )
    : titolo(titolo), autore(autore), dataPubblicazione(dataPubblicazione), tipoCopertina(tipoCopertina), quantita(quantita), prezzo(prezzo) {
  
}

int Libro::getId() const {
    return id;
}

std::string Libro::getTitolo() const {
    return titolo;
}

std::string Libro::getAutore() const {
    return autore;
}

std::string Libro::getDataPubblicazione() const {
    return dataPubblicazione;
}

std::string Libro::getTipoCopertina() const {
    return tipoCopertina;
}

void Libro::setTipoCopertina(const std::string& tipo) {
    tipoCopertina = tipo;
}

void Libro::setId(int newid){
    id = newid;
}

void Libro::setTitolo(const std::string& newTitolo) {
    titolo = newTitolo;
}

void Libro::setAutore(const std::string& newAutore) {
    autore = newAutore;
}

void Libro::setDataPubblicazione(const std::string& newDataPubblicazione) {
    dataPubblicazione = newDataPubblicazione;
}
int Libro::getQuantita() const {
    return quantita;
}

void Libro::setQuantita(int quantita) {
    this->quantita = quantita;
}

    double Libro::getPrezzo() const {
        return prezzo;
    }

    void Libro::setPrezzo(double nuovoPrezzo) {
        prezzo = nuovoPrezzo;
    }




void Libro::stampa() const {
    std::cout<< "ID: " << id << ", Titolo: " << titolo << ", Autore: " << autore << ", Data Pubblicazione: " << dataPubblicazione << ", Tipo copertina: " << tipoCopertina << ", quantita:"<<quantita << ", prezzo :"<< prezzo;

}
std::ostream& operator<<(std::ostream& os, const Libro& libro) {
    os << "ID: " << libro.id << ", Titolo: " << libro.titolo << ", Autore: " << libro.autore << ", Data Pubblicazione: " << libro.dataPubblicazione << ", Tipo copertina: " << libro.tipoCopertina << ", quantita:"<<libro.quantita << ", prezzo :"<< libro.prezzo;
    return os;
}

