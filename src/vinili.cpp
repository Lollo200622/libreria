#include "vinili.hpp"



Vinile::Vinile(const std::string& titolo, const std::string& autore, const std::string& dataPubblicazione, double diametro, int quantita,double prezzo )
    : titolo(titolo), autore(autore), dataPubblicazione(dataPubblicazione), diametro(diametro),  quantita(quantita),  prezzo(prezzo) {
  
}

int Vinile::getId() const {
    return id;
}

std::string Vinile::getTitolo() const {
    return titolo;
}

std::string Vinile::getAutore() const {
    return autore;
}

std::string Vinile::getDataPubblicazione() const {
    return dataPubblicazione;
}

double Vinile::getDiametro() const {
    return diametro;
}

void Vinile::setDiametro(double newDiametro) {
    diametro = newDiametro;
}

void Vinile::setId(int newid){
	id = newid;
}

int Vinile::getQuantita() const {
    return quantita;
}
void Vinile::setQuantita(int quantita) {
    this->quantita = quantita;
}

    double Vinile::getPrezzo() const {
        return prezzo;
    }

    void Vinile::setPrezzo(double nuovoPrezzo) {
        prezzo = nuovoPrezzo;
    }

    void Vinile::stampa() const {
    std::cout  << "ID: " << getId() << ", Titolo: " << getTitolo() << ", Autore: " << getAutore() << ", Data Pubblicazione: " << getDataPubblicazione() << ", Diametro: " << getDiametro() << ", quantita:"<< quantita<< ", prezzo :"<< prezzo;
}

std::ostream& operator<<(std::ostream& os, const Vinile& vinile) {
    os << "ID: " << vinile.getId() << ", Titolo: " << vinile.getTitolo() << ", Autore: " << vinile.getAutore() << ", Data Pubblicazione: " << vinile.getDataPubblicazione() << ", Diametro: " << vinile.getDiametro() << ", quantita:"<< vinile.quantita<< ", prezzo :"<< vinile.prezzo;
    return os;
}

