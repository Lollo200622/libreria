#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "csv.hpp"



bool SalvataggioCSV::salvaLibriSuFileCSV(const Libreria& libreria, const std::string& nomeFile) const {
    std::ofstream file(nomeFile);
    if (!file.is_open()) {
        return false ;
    }

    file << "Tipo,id,titolo,autore,data_pubblicazione,tipo_copertina,diametro,quantita,prezzo" << std::endl;

    for (const auto& pair : libreria.getLibri()) {
        const Libro& libro = pair.second;
        file << "Libro," << libro.getId() << "," << libro.getTitolo() << "," << libro.getAutore() << ","
             << libro.getDataPubblicazione() << "," << libro.getTipoCopertina() << ","
             << ","
             << libro.getQuantita() << "," << libro.getPrezzo() << std::endl;
    }

    for (const auto& pair : libreria.getVinili()) {
        const Vinile& vinile = pair.second;
        file << "Vinile," << vinile.getId() << "," << vinile.getTitolo() << "," << vinile.getAutore() << ","
             << vinile.getDataPubblicazione() << ","
             << ","
             << vinile.getDiametro() << ","
             << vinile.getQuantita() << "," << vinile.getPrezzo() << std::endl;
    }

    file.close();
    return true;
}

bool SalvataggioCSV::caricaFileCSV(Libreria& libreria, const std::string& nomeFile) const {
    std::ifstream file(nomeFile);
    if (!file.is_open()) {
        return false ;
    }
    libreria.svuotaLibreria();
    std::string line;
    bool headerSkipped = false;

    while (std::getline(file, line)) {
        if (line.empty()) continue;

        if (!headerSkipped) {
            headerSkipped = true;
            continue;
        }

        std::istringstream ss(line);
        std::string tipo, idStr, titolo, autore, dataPubblicazione, tipoCopertina, diametroStr, quantitaStr, prezzoStr;

        std::getline(ss, tipo, ',');
        std::getline(ss, idStr, ',');
        std::getline(ss, titolo, ',');
        std::getline(ss, autore, ',');
        std::getline(ss, dataPubblicazione, ',');
        std::getline(ss, tipoCopertina, ',');
        std::getline(ss, diametroStr, ',');
        std::getline(ss, quantitaStr, ',');
        std::getline(ss, prezzoStr, ',');

        idStr.erase(std::remove_if(idStr.begin(), idStr.end(), ::isspace), idStr.end());
        quantitaStr.erase(std::remove_if(quantitaStr.begin(), quantitaStr.end(), ::isspace), quantitaStr.end());
        prezzoStr.erase(std::remove_if(prezzoStr.begin(), prezzoStr.end(), ::isspace), prezzoStr.end());
        tipoCopertina.erase(std::remove_if(tipoCopertina.begin(), tipoCopertina.end(), ::isspace), tipoCopertina.end());
        diametroStr.erase(std::remove_if(diametroStr.begin(), diametroStr.end(), ::isspace), diametroStr.end());

        if (tipo == "Libro") {
            int id, quantita;
            double prezzo;
            try {
                id = std::stoi(idStr);
                quantita = std::stoi(quantitaStr);
                prezzo = std::stod(prezzoStr);
            } catch (const std::invalid_argument& e) {
                continue;
            } catch (const std::out_of_range& e) {
                continue;
            }

            Libro libro(titolo, autore, dataPubblicazione, tipoCopertina, quantita, prezzo);
            libro.setId(id);
            libreria.aggiungiLibro(libro);

        } else if (tipo == "Vinile") {
            int id, quantita;
            float diametro;
            double prezzo;
            try {
                id = std::stoi(idStr);
                diametro = std::stof(diametroStr);
                quantita = std::stoi(quantitaStr);
                prezzo = std::stod(prezzoStr);
            } catch (const std::invalid_argument& e) {
                continue;
            } catch (const std::out_of_range& e) {
                continue;
            }

            Vinile vinile(titolo, autore, dataPubblicazione, diametro, quantita, prezzo);
            vinile.setId(id);
            libreria.aggiungiVinile(vinile);
        } else {
            continue;
        }
    }

    file.close();
    return true;
}

