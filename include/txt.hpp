#ifndef TXT_HPP
#define TXT_HPP

#include "library.hpp"
#include <fstream>
#include <iostream>


class SalvataggioTXT {
public:
    bool salvaLibriSuFileTxt(const Libreria& libreria, const std::string& nomeFile) const;
    bool caricaFileTxt(Libreria& libreria, const std::string& nomeFile) const;
};

#endif // SALVATAGGIOTXT_HPP