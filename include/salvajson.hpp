#ifndef SALVAJSON_HPP
#define SALVAJSON_HPP

#include "library.hpp"
#include "json.hpp"
#include <fstream>
#include <iostream>


class SalvataggioJSON {
public:
    bool caricaFileJSON(Libreria& libreria, const std::string& nomeFile) const;
    bool salvaLibriSuFileJSON(const Libreria& libreria, const std::string& nomeFile) const;
};
#endif // JSON_HPP
