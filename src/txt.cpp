#include "txt.hpp"




bool SalvataggioTXT::salvaLibriSuFileTxt(const Libreria& libreria, const std::string& nomeFile) const {
    std::ofstream file(nomeFile);
    if (!file.is_open()) {
        //std::cerr << "Impossibile creare il file " << nomeFile << " per il salvataggio." << std::endl;
        return false ;
    }

    for (const auto& pair : libreria.getLibri()) {
        const Libro& libro = pair.second;
        file << "L " << libro.getId() << " " << libro.getTitolo() << " " << libro.getAutore() << " "
             << libro.getDataPubblicazione() << " " << libro.getTipoCopertina() << " " << libro.getQuantita()
             << " " << libro.getPrezzo() << std::endl;
    }

    for (const auto& pair : libreria.getVinili()) {
        const Vinile& vinile = pair.second;
        file << "V " << vinile.getId() << " " << vinile.getTitolo() << " " << vinile.getAutore() << " "
             << vinile.getDataPubblicazione() << " " << vinile.getDiametro() << " " << vinile.getQuantita()
             << " " << vinile.getPrezzo() << std::endl;
    }

    file.close();
}

bool SalvataggioTXT::caricaFileTxt(Libreria& libreria, const std::string& nomeFile) const {
    std::ifstream file(nomeFile);
    if (!file.is_open()) {
       // std::cerr << "Impossibile aprire il file " << nomeFile << " per il caricamento." << std::endl;
        return false ;
    }

    libreria.svuotaLibreria();

    char tipo;
    int id;
    std::string titolo, autore, dataPubblicazione, tipoCopertina;
    int quantita;
    float diametro;
    double prezzo;

    while (file >> tipo >> id >> titolo >> autore >> dataPubblicazione) {
        if (tipo == 'L') {
            file >> tipoCopertina >> quantita >> prezzo;
            Libro libro(titolo, autore, dataPubblicazione, tipoCopertina, quantita, prezzo);
            libro.setId(id);
            libreria.aggiungiLibro(libro);
        } else if (tipo == 'V') {
            file >> diametro >> quantita >> prezzo;
            Vinile vinile(titolo, autore, dataPubblicazione, diametro, quantita, prezzo);
            vinile.setId(id);
            libreria.aggiungiVinile(vinile);
        }
    }

    file.close();
}
