#ifndef VINILI_HPP
#define VINILI_HPP

#include <string>
#include <iostream>



class Vinile {
private:
   //int id;
   /* int quantita;
    std::string titolo;
    std::string autore;
    std::string dataPubblicazione;
    double diametro; 
    static int viniliCounter;*/  
   // double prezzo;

public:
    Vinile(const std::string& titolo, const std::string& autore, const std::string& dataPubblicazione, double diametro, int quantita, double prezzo );

    int getId() const;
    std::string getTitolo() const;
    std::string getAutore() const;
    std::string getDataPubblicazione() const;
    double getDiametro() const;
    void setId(int newid);
    void setDiametro(double newDiametro);
    double getPrezzo() const ;
    void setPrezzo(double nuovoPrezzo);

    int getQuantita() const;
    void setQuantita(int quantita);
    int quantita;
    std::string titolo;
    std::string autore;
    std::string dataPubblicazione;
    double diametro; 
    static int viniliCounter; 
     friend std::ostream& operator<<(std::ostream& os, const Vinile& Vinile);
    int id;
    double prezzo;
    void stampa() const;
     
};

#endif // VINILI_HPP
