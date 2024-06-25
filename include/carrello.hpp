#ifndef CARRELLO_HPP
#define CARRELLO_HPP

#include <iostream>
#include <vector>
#include <map>
#include "book.hpp"
#include "vinili.hpp"

struct Prodotto {
    int id;
    int quant;
};

class Carrello {
private:
    std::vector<Prodotto> prodotti;  

public:
  
    void aggiungiProdotto(int id, int quant);
    void rimuoviProdotto(int id);
   
    double totale(const std::map<int, Libro>& libriDB, const std::map<int, Vinile>& viniliDB) const;
    const std::vector<Prodotto>& getProdotti() const;
    void svuotaCarrello();
    int getQuantita(int id) const;
    bool contieneProdotto(int id) const;


    int getQuant(int id) const;
};

#endif // CARRELLO_HPP
