    #include "library.hpp"
    #include <fstream>
    #include <iostream>
    #include <sstream>
#include "carrello.hpp"
//MONKEY MART
    //csv salvare il data base con csv  prima linea i titoli 
    // primo campo id secondo campo titolo...
    //possibilità di salvare su un altro file 
    // caricare quale libreria e aggiungere uno step che cambia la libreria, appena compili deve vemire fuori quale libreria caricare

    //scegliere il formato di uscita 
    // la libretia deve sapere come salvare in csv txt  
    //controllo data
    // xontrollo che non ci possono essere spazi 
    // json

    //--controllo data non può essere negativa --
    //--id automatico e controllare se ci sono libri uguali --
    //--comprare vinili creare libreria book store non solo libri ma anche vinile 
    // --aggiungi libri vinili separati invece cerca autore uniti
    //  --titolo autore data 
    // --aggiungere se la copertina è dura o morbida --
    // --invece per i vinili dimensione dimensione diametro 
    // --modifica libro e vinile insieme 
//--stock quantita vinili e libri  quante copie ci sono  la libreria è proprietario dello stoke e inseriamo noim quante copie ci sono
// se voglio comprare vinile 
// --prezzo libro  agiungere nel menu compra libro e quanti soldi devo mettere e quanto costa 
// --aggiungere nel menu aggiungi libro e vinile quanto costa 
//due modalità una modalità amministrazione  e l'altra vendita  
// comprare libro 
// aggiungere libro o vinile 
//  creare un carello costo totale e ogni singolo libro o vinile 
// modifica carrello 
// creare classe carrello elenco libri e vnili da comprare
//  mettere anche il resto

//controllo id esistente 
// unire in un solo prodotto
// ogni volta che aggiungoun prodotto deve dirmi il totale e quale prodotto abbiamo comprato e 
// nel carrello mettere il prezzo unitario e il costo tatale
//compra aggiungere la banconota euro e centesimi
// verificare banconote valide e monete 
//parte amminstrazione aggiungere quantità iniziale monete e anconote 
//creare stock, quando finisce l'acquisto memorizzare i soldi presi della macchina 
//exception
// per il resto se ci sono le bancote 


const Cassa& Libreria::getCassa() const {
    return cassa;
}

// Implementazione del metodo getCassa() non costante
Cassa& Libreria::getCassa() {
    return cassa;
}const std::map<double, int>& Libreria::getBanconote() const {
    return cassa.getBanconote();
}




bool Libreria::controllaDuplicato(const Libro& libro) const {
    for (const auto& pair : libri) {
        const Libro& libroCorrente = pair.second;
        if (libroCorrente.getTitolo() == libro.getTitolo() &&
            libroCorrente.getAutore() == libro.getAutore() &&
            libroCorrente.getDataPubblicazione() == libro.getDataPubblicazione() &&
            libroCorrente.getTipoCopertina() == libro.getTipoCopertina()) {
            return true;
        }
    }
    return false;
}

bool Libreria::controllaDuplicatovinili(const Vinile& vinile) const {
    for (const auto& pair : vinili) {
        const Vinile& vinileCorrente = pair.second;
        if (vinileCorrente.getTitolo() == vinile.getTitolo() &&
            vinileCorrente.getAutore() == vinile.getAutore() &&
            vinileCorrente.getDataPubblicazione() == vinile.getDataPubblicazione() &&
            vinileCorrente.getDiametro() == vinile.getDiametro()) {
            return true;
        }
    }
    return false;
}

bool Libreria::controllaDuplicatiID(int id) const {
    for (const auto& pair : libri) {
        if (pair.second.getId() == id) {
            return true;
        }
    }
    return false;
}

bool Libreria::controllaDuplicatiIDVinile(int id) const {
    for (const auto& pair : vinili) {
        if (pair.second.getId() == id) {
            return true;
        }
    }
    return false;
}

void Libreria::aggiungiLibro(const Libro& libro, int quantita) {

       int newId = prossimoId;
        while (libri.find(newId) != libri.end()) {
            newId++;
        }

        Libro libroConId = libro;
        libroConId.setId(newId);

        libri.insert(std::make_pair(newId, libroConId));
        prossimoId = newId + 1;
    }



void Libreria::aggiungiVinile(const Vinile& vinile, int quantita) {
 
        

        int newId = prossimoId;
        while (vinili.find(newId) != vinili.end()) {
            newId++;
        }

        Vinile vinileConId = vinile;
        vinileConId.setId(newId);
    
        vinili.insert(std::make_pair(newId, vinileConId));
        prossimoId = newId + 1;
   }

bool Libreria::eliminaLibro(int id, int quantita) {
    auto libroIt = libri.find(id);
    if (libroIt != libri.end()) {
        Libro& libro = libroIt->second;
        if (quantita >= libro.getQuantita()) {
            libri.erase(libroIt);
        } else {
            libro.setQuantita(libro.getQuantita() - quantita);
        }
        return true; 
    }
      auto vinileIt = vinili.find(id);
    if (vinileIt != vinili.end()) {
        Vinile& vinile = vinileIt->second;
        if (quantita >= vinile.getQuantita()) {
            vinili.erase(vinileIt);
        } else {
            vinile.setQuantita(vinile.getQuantita() - quantita);
        }
        return true;
    }
    return false;
}



 bool Libreria::eliminaTutteLeQuantita(int id) {
    
    auto libroIt = libri.find(id);
    if (libroIt != libri.end()) {
        libri.erase(libroIt);
       ;
        return true;
    }


    auto vinileIt = vinili.find(id);
    if (vinileIt != vinili.end()) {
        vinili.erase(vinileIt);
    
        return true;
    }

    return false;
}

void Libreria::svuotaLibreria() {
    libri.clear();
    vinili.clear();
}




void Libreria::stampaLibri() const {
    std::cout << "Libri:" << std::endl;
    for (const auto& pair : libri) {
        std::cout << pair.second << std::endl;
    }

    std::cout << "Vinili:" << std::endl;
    for (const auto& pair : vinili) {
        std::cout << pair.second << std::endl;
    }
}

std::vector<Libro> Libreria::cercaLibriPerAutore(const std::string& autore) const {
    std::vector<Libro> risultati;
    for (const auto& pair : libri) {
        if (pair.second.getAutore() == autore) {
            risultati.push_back(pair.second);
        }
    }
    return risultati;
}

std::vector<Vinile> Libreria::cercaViniliPerAutore(const std::string& autore) const {
    std::vector<Vinile> risultati;
    for (const auto& pair : vinili) {
        if (pair.second.getAutore() == autore) {
            risultati.push_back(pair.second);
        }
    }
    return risultati;
}


std::vector<Libro> Libreria::cercaLibriPerTitolo(const std::string& titolo) const {
    std::vector<Libro> risultati;
    for (const auto& pair : libri) {
        if (pair.second.getTitolo() == titolo) {
            risultati.push_back(pair.second);
        }
    }
    return risultati;
}

std::vector<Vinile> Libreria::cercaViniliPerTitolo(const std::string& titolo) const {
    std::vector<Vinile> risultati;
    for (const auto& pair : vinili) {
        if (pair.second.getTitolo() == titolo) {
            risultati.push_back(pair.second);
        }
    }
    return risultati;
}

bool Libreria::modificaLibro(int id, const Libro& nuovoLibro) {
    auto it = libri.find(id);
    if (it != libri.end()) {
        it->second = nuovoLibro;
        it->second.setId(id);
        return true;
    }
    return false;
}

bool Libreria::modificaVinile(int id, const Vinile& nuovoVinile) {
    auto it = vinili.find(id);
    if (it != vinili.end()) {
        it->second = nuovoVinile;
        it->second.setId(id);
        return true;
    }
    return false;
}

bool Libreria::controllaEsistenzaLibro(int id) {
    return libri.find(id) != libri.end();
}

bool Libreria::controllaEsistenzaVinile(int id) {
    return vinili.find(id) != vinili.end();
}

const std::map<int, Libro>& Libreria::getLibri() const {
    return libri;
}

const std::map<int, Vinile>& Libreria::getVinili() const {
    return vinili;
}
