#include "carrello.hpp"

void Carrello::aggiungiProdotto(int id, int quant) {
    prodotti.push_back({id, quant});
}

void Carrello::rimuoviProdotto(int id) {
    for (auto it = prodotti.begin(); it != prodotti.end(); ++it) {
        if (it->id == id) {
            prodotti.erase(it);
            return; 
        }
    }
}


double Carrello::totale(const std::map<int, Libro>& libriDB, const std::map<int, Vinile>& viniliDB) const {
    double totale = 0.0;
    for (const auto& prodotto : prodotti) {
        auto libroIt = libriDB.find(prodotto.id);
        if (libroIt != libriDB.end()) {
            totale += libroIt->second.getPrezzo() * prodotto.quant;
        } else {
            auto vinileIt = viniliDB.find(prodotto.id);
            if (vinileIt != viniliDB.end()) {
                totale += vinileIt->second.getPrezzo() * prodotto.quant;
            }
        }
    }
    return totale;
    
}

const std::vector<Prodotto>& Carrello::getProdotti() const {
    return prodotti;
}

void Carrello::svuotaCarrello() {
    prodotti.clear();
}

bool Carrello::contieneProdotto(int id) const {
    for (const auto& prodotto : prodotti) {
        if (prodotto.id == id) {
            return true;
        }
    }
    return false;
}

int Carrello::getQuant(int id) const {
    for (const auto& prodotto : prodotti) {
        if (prodotto.id == id) {
            return prodotto.quant;
        }
    }
    return 0;  
}

int Carrello::getQuantita(int id) const {
    for (const auto& prodotto : prodotti) {
        if (prodotto.id == id) {
            return prodotto.quant;
        }
    }
    return 0;  
}
