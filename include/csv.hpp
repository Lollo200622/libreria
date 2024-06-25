#ifndef CSV_HPP
#define CSV_HPP

#include "library.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

class SalvataggioCSV {
public:
    bool salvaLibriSuFileCSV(const Libreria& libreria, const std::string& nomeFile) const;
    bool caricaFileCSV(Libreria& libreria, const std::string& nomeFile) const;
  
};

#endif