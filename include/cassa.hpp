#ifndef CASSA_HPP
#define CASSA_HPP

#include "banconote.hpp"
#include <map>

class Cassa {
private:
    std::map<double, int> banconote;

public:
    Cassa();

    void aggiungiBanconote(const Banconota& banconota, int quantita);
    const std::map<double, int>& getBanconote() const;
    double sommaTotale() const;
    bool rimuoviBanconote(const Banconota& banconota, int quantita);
  
    bool controllaResto(int resto);
};

#endif
