#include "cassa.hpp"

Cassa::Cassa() {
    banconote[50.0] = 0;
    banconote[20.0] = 0;
    banconote[10.0] = 0;
    banconote[5.0] = 0;
    banconote[2.0] = 0;
    banconote[1.0] = 0;
}

void Cassa::aggiungiBanconote(const Banconota& banconota, int quantita) {
    double valore = banconota.getValore();
    auto it = banconote.find(valore);
    if (it != banconote.end()) {
        it->second += quantita;
    } else {
        banconote[valore] = quantita;
    }
}

const std::map<double, int>& Cassa::getBanconote() const {
    return banconote;
}

double Cassa::sommaTotale() const {
    double totale = 0.0;
    for (const auto& pair : banconote) {
        double valore = pair.first;
        int quantita = pair.second;
        totale += valore * quantita;
    }
    return totale;
}

bool Cassa::rimuoviBanconote(const Banconota& banconota, int quantita) {
    double valore = banconota.getValore();
    auto it = banconote.find(valore);
    if (it != banconote.end() && it->second >= quantita) {
        it->second -= quantita;
        if (it->second == 0) {
            banconote.erase(it);
        }
        return true;
    }
    return false;
}

bool Cassa::controllaResto(int resto) {
    std::map<int, int> banconoteUtilizzate;

    for (auto it = banconote.rbegin(); it != banconote.rend(); ++it) {
        int valoreBanconota = it->first;
        int quantitaDisponibile = it->second;
        
        while (resto >= valoreBanconota && quantitaDisponibile > 0) {
            resto -= valoreBanconota;
            quantitaDisponibile--;
            banconoteUtilizzate[valoreBanconota]++;
        }
        
        if (resto == 0) {
            break;
        }
    }
    
    if (resto != 0) {
        return false; 
   }

    for (auto& pair : banconoteUtilizzate) {
        banconote[pair.first] -= pair.second;
    }
    
    return true;
}
