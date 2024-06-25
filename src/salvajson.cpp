#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "library.hpp"
#include "salvajson.hpp"

using namespace nlohmann;





bool SalvataggioJSON::caricaFileJSON(Libreria& libreria, const std::string& nomeFile) const {
    std::ifstream file(nomeFile);
    if (!file.is_open()) {
        std::cerr << "Impossibile aprire il file " << nomeFile << " per il caricamento." << std::endl;
        return false ;
    }

    libreria.svuotaLibreria(); 

    json j;
    try {
        file >> j;
    } catch (const json::parse_error& e) {
        std::cerr << "Errore di parsing JSON: " << e.what() << std::endl;
        file.close();
        return false ;
    }

    file.close();

    if (j.empty()) {
        std::cerr << "Il file JSON è vuoto. Nessun elemento da caricare." << std::endl;
        return false;
    }

    std::vector<json> elementi;
    for (const auto& elemento_json : j) {
        elementi.push_back(elemento_json);
    }

    std::sort(elementi.begin(), elementi.end(), [](const json& a, const json& b) {
        return a["id"] < b["id"];
    });

    for (const auto& elemento_json : elementi) {
        std::string tipo = elemento_json["tipo"];
        int id = elemento_json["id"];
        std::string titolo = elemento_json["titolo"];
        std::string autore = elemento_json["autore"];
        std::string dataPubblicazione = elemento_json["data_pubblicazione"];
        double prezzo = elemento_json["prezzo"];

        std::string tipoCopertina = "Sconosciuto"; 
        if (elemento_json.find("tipo_copertina") != elemento_json.end()) {
            tipoCopertina = elemento_json["tipo_copertina"];
        }

        if (tipo == "libro") {
            int quantita = elemento_json["quantita"];
            Libro libro(titolo, autore, dataPubblicazione, tipoCopertina, quantita, prezzo);
            libro.setId(id);
            libreria.aggiungiLibro(libro);
        } else if (tipo == "vinile") {
            float diametro = elemento_json["diametro"];
            int quantita = elemento_json["quantita"];
            Vinile vinile(titolo, autore, dataPubblicazione, diametro, quantita, prezzo);
            vinile.setId(id);
            libreria.aggiungiVinile(vinile);
        }
    }
}

bool SalvataggioJSON::salvaLibriSuFileJSON(const Libreria& libreria, const std::string& nomeFile) const {
    std::ofstream file(nomeFile);
    if (!file.is_open()) {
        std::cerr << "Impossibile creare il file " << nomeFile << " per il salvataggio." << std::endl;
        return false ;
    }

    json j = json::array();

    // Salvataggio dei libri
    for (const auto& pair : libreria.getLibri()) {
        const Libro& libro = pair.second;
        j.push_back({
            {"tipo", "libro"},
            {"id", libro.getId()},
            {"titolo", libro.getTitolo()},
            {"autore", libro.getAutore()},
            {"data_pubblicazione", libro.getDataPubblicazione()},
            {"tipo_copertina", libro.getTipoCopertina()},
            {"quantita", libro.getQuantita()},
            {"prezzo", libro.getPrezzo()}
        });
    }

    // Salvataggio dei vinili
    for (const auto& pair : libreria.getVinili()) {
        const Vinile& vinile = pair.second;
        j.push_back({
            {"tipo", "vinile"},
            {"id", vinile.getId()},
            {"titolo", vinile.getTitolo()},
            {"autore", vinile.getAutore()},
            {"data_pubblicazione", vinile.getDataPubblicazione()},
            {"diametro", vinile.getDiametro()},
            {"quantita", vinile.getQuantita()},
            {"prezzo", vinile.getPrezzo()}
        });
    }

    std::sort(j.begin(), j.end(), [](const json& a, const json& b) {
        return a["id"] < b["id"];
    });

    file << std::setw(4) << j << std::endl;
    file.close();
}
