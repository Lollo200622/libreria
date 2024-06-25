#include <iostream>
#include <sstream>
#include "library.hpp"
#include "salvajson.hpp"
#include "txt.hpp"
#include "csv.hpp"
#include "vinili.hpp"
#include "carrello.hpp"
#include "cassa.hpp"
#include "banconote.hpp"

    void mostraMenu() {
        std::cout << "\nMenu:\n";
        std::cout << "A. Vuoi aggiungere soldi alla cassa\n";
        std::cout << "B. Aggiungi libro\n";
        std::cout << "C. Aggiungi vinile\n";
        std::cout << "D. Cerca libri per autore\n";
        std::cout << "E. Cerca libri per titolo\n";
        std::cout << "F. Modifica libro\n";
        std::cout << "G. Elimina libro\n";
        std::cout << "H. Mostra tutti i libri\n";
        std::cout << "I. Salva libri su file\n";
        std::cout << "J. Carica il file che desideri\n";
        std::cout << "L. Stampa tutti i soldi\n";
        std::cout << "M. Esci\n";
        
        std::cout << "Scegli un'opzione: ";

    }

    void stampaMenu() {
        std::cout << "\nMenu:" << std::endl;
        std::cout << "A. Aggiungi prodotto al carrello " << std::endl;
        std::cout << "B. Rimuovi prodotto dal carrello" << std::endl;
        std::cout << "C. Visualizza carrello" << std::endl;
        std::cout << "D. Finisci acquisto" << std::endl;
        std::cout << "E. stampa " << std::endl;
        std::cout << "F. Esci " << std::endl;
        
        std::cout << "Scelta :";
      
    }

    void stampaBanconoteCassa(const Cassa& cassa) {
    std::cout << "Quantità di banconote nella cassa:" << std::endl;
    for (const auto& pair : cassa.getBanconote()) {
        std::cout << "Valore banconote " << pair.first << ": " << pair.second << std::endl;
    }
}




    bool controllaData(const std::string& dataPubblicazione) {
        std::istringstream iss(dataPubblicazione);
        int anno;
        if(iss >> anno){
           return anno > 2024;
        }
        return false;
    }

    bool controllaDatanegativo(const std::string& dataPubblicazione) {
        std::istringstream iss(dataPubblicazione);
        int anno;
        if(iss >> anno){
           return anno < 0;
        }
        return false;
    }

int main() {
    Libreria libreria;
    SalvataggioTXT txt;
    SalvataggioCSV csv;
    SalvataggioJSON json;
    Cassa cassa;

    char f;
    std::cout << "Scegli il formato del file (c = CSV, t = TXT, j = JSON): ";
    std::cin >> f;
    std::cin.ignore();
        if (f == 'c') {
           
                std::string nomeFileCaricamento;

                std::cout << "Inserisci il percorso del file CSV da cui desideri caricare i libri e i vinili: ";
                std::getline(std::cin, nomeFileCaricamento);
                if (nomeFileCaricamento.find(".csv") == std::string::npos) {
                nomeFileCaricamento += ".csv";
            }
                 if (csv.caricaFileCSV(libreria, nomeFileCaricamento)) {
                        std::cout << "Elementi caricati con successo dal file CSV: " << nomeFileCaricamento << std::endl;
                    } else {
                        std::cerr << "Errore durante il caricamento degli elementi dal file CSV: " << nomeFileCaricamento << std::endl;
                    }

              } else if (f == 't') {
                std::string nomeFile;
                std::cout << "Inserisci il percorso del file TXT da cui desideri caricare i libri e i vinili: ";
                std::getline(std::cin, nomeFile);

            if (nomeFile.find(".txt") == std::string::npos) {
                  nomeFile += ".txt";
            }
                if (txt.caricaFileTxt(libreria, nomeFile)) {
                    std::cout << "Elementi caricati con successo dal file TXT: " << nomeFile << std::endl;
                } else {
                    std::cerr << "Errore durante il caricamento degli elementi dal file TXT: " << nomeFile << std::endl;
                }
        } else if (f == 'j') {
                std::string nomeFileCaricamento;
                std::cout << "Inserisci il percorso del file JSON da cui desideri caricare i libri e i vinili: ";
                std::getline(std::cin, nomeFileCaricamento);
                if (nomeFileCaricamento.find(".json") == std::string::npos) {
                nomeFileCaricamento += ".json";
            }
            if (json.caricaFileJSON(libreria, nomeFileCaricamento)) {
                std::cout << "Elementi caricati con successo dal file JSON: " << nomeFileCaricamento << std::endl;
            } else {
                std::cerr << "Errore durante il caricamento degli elementi dal file JSON: " << nomeFileCaricamento << std::endl;
            }
        } else {
            std::cout << "Formato non valido." << std::endl;
            return 1;
        }

    while(true){
    char scelta;
    char Tipo;


    std::cout << "\nCosa desideri fare?" << std::endl;
            std::cout << "1. Modalità amministrativa" << std::endl;
            std::cout << "2. Acquistare" << std::endl;
            std::cout << "3. Esci dal programma" << std::endl;

            std::cout << "Scelta: ";
            std::cin >> Tipo;
            std::cin.ignore(); 
            
          
if (Tipo == '1'){

                        
    while (true) {
     
        mostraMenu();
        std::cin >> scelta;
        char s; 
        std::cin.ignore();
        if (scelta == 'A' ||scelta == 'a' ){
                     int quantita_50, quantita_20, quantita_10, quantita_5, quantita_2, quantita_1;
            std::cout << "Inserisci il numero di banconote da 50: ";
            std::cin >> quantita_50;
            std::cout << "Inserisci il numero di banconote da 20: ";
            std::cin >> quantita_20;
            std::cout << "Inserisci il numero di banconote da 10: ";
            std::cin >> quantita_10;
            std::cout << "Inserisci il numero di banconote da 5: ";
            std::cin >> quantita_5;
            std::cout << "Inserisci il numero di monete da 2: ";
            std::cin >> quantita_2;
            std::cout << "Inserisci il numero di monete da 1: ";
            std::cin >> quantita_1;

            cassa.aggiungiBanconote(50, quantita_50);
            cassa.aggiungiBanconote(20, quantita_20);
            cassa.aggiungiBanconote(10, quantita_10);
            cassa.aggiungiBanconote(5, quantita_5);
            cassa.aggiungiBanconote(2, quantita_2);
            cassa.aggiungiBanconote(1, quantita_1);

            
            std::cout << "Quantità di banconote nella cassa:" << std::endl;
            for (const auto& pair : cassa.getBanconote()) {
                std::cout << "Valore banconote" << pair.first << ": " << pair.second << std::endl;
            }

           
            std::cout << "\nValore totale del denaro in cassa: " << cassa.sommaTotale() << " euro" << std::endl;

   
          }
         else if (scelta == 'B' || scelta == 'b') {
            std::string titolo, autore, dataPubblicazione, tipoCopertina;
            int quantita;
            double prezzo;
            std::cout << "Inserisci Titolo: ";
            std::getline(std::cin, titolo);
            if (titolo.empty()) {
                std::cout << "Il titolo non può essere vuoto." << std::endl;
                continue;
            }
            std::cout << "Inserisci Autore: ";
            std::getline(std::cin, autore);
            if (autore.empty()) {
                std::cout << "L'autore non può essere vuoto." << std::endl;
                continue;
            }
            while (true) {
                std::cout << "Inserisci Data di Pubblicazione (formato AAAA): ";
                std::getline(std::cin, dataPubblicazione);
                if (controllaData(dataPubblicazione) || controllaDatanegativo(dataPubblicazione)) {
                    std::cout << "La data di pubblicazione non può essere nel futuro o negativa. Riprova." << std::endl;
                    continue;
                }
                if (dataPubblicazione.empty()) {
                    std::cout << "La data non può essere vuota." << std::endl;
                    continue;
                }
                break;
            }
            std::cout << "Inserisci tipo di copertina (Dura/Morbida): ";
            std::getline(std::cin, tipoCopertina);
            if (tipoCopertina != "Dura" && tipoCopertina != "Morbida" && tipoCopertina != "dura" && tipoCopertina != "morbida") {
                std::cout << "Tipo di copertina non valido. Deve essere 'Dura' o 'Morbida'." << std::endl;
                continue;
            }
            std::cout << "Inserisci quantità: ";
            std::cin >> quantita;
            if (quantita <= 0) {
                std::cout << "La quantità deve essere un numero positivo." << std::endl;
                continue;
            }
            std::cin.ignore();
            std::cout << "Inserisci il prezzo del libro: ";
            std::cin >> prezzo;
            std::cin.ignore();
            
            Libro libro(titolo, autore, dataPubblicazione, tipoCopertina, quantita, prezzo);
            if (libreria.controllaDuplicato(libro)){
                 std::cout << "Il libro è già presente nella libreria o i dati non sono validi." << std::endl;
            
        }else{
            libreria.aggiungiLibro(libro);
            std::cout << "Libro aggiunto con successo." << std::endl;
        }

        } else if (scelta == 'C' ||scelta == 'c') {
            std::string titolo, autore, dataPubblicazione;
            double diametro, prezzo;
            int quantita;
        
            std::cout << "Inserisci Titolo del Vinile: ";
            std::getline(std::cin, titolo);
            if (titolo.empty()) {
                std::cout << "Il titolo non può essere vuoto." << std::endl;
                continue;
            }
            std::cout << "Inserisci Autore del Vinile: ";
            std::getline(std::cin, autore);
            if (autore.empty()) {
                std::cout << "L'autore non può essere vuoto." << std::endl;
                continue;
            }
            while (true) {
                std::cout << "Inserisci Data di Pubblicazione del Vinile (formato AAAA): ";
                std::getline(std::cin, dataPubblicazione);
                if (controllaData(dataPubblicazione) || controllaDatanegativo(dataPubblicazione)) {
                    std::cout << "La data di pubblicazione non può essere nel futuro o negativa. Riprova." << std::endl;
                    continue;
                }
                if (dataPubblicazione.empty()) {
                    std::cout << "La data non può essere vuota." << std::endl;
                    continue;
                }
                break;
            }
            std::cout << "Inserisci Diametro del Vinile: ";
            std::cin >> diametro;
            if (diametro <= 0) {
                std::cout << "Il diametro del vinile deve essere un numero positivo." << std::endl;
                continue;
            }
            std::cout << "Inserisci quantità: ";
            std::cin >> quantita;
            if (quantita <= 0) {
                std::cout << "La quantità deve essere un numero positivo." << std::endl;
                continue;
            }
            std::cin.ignore();
            std::cout << "Inserisci il prezzo del vinile: ";
            std::cin >> prezzo;
            std::cin.ignore();

            Vinile vinile(titolo, autore, dataPubblicazione, diametro, quantita, prezzo);
            if (libreria.controllaDuplicatovinili(vinile)) {
            std::cout << "Il vinile è già presente nella libreria o i dati non sono validi." << std::endl;
         
        }else{
            libreria.aggiungiVinile(vinile);
            std::cout << "Vinile aggiunto con successo." << std::endl;
        }

        } else if (scelta == 'D' ||  scelta == 'd') {
            std::string autoreCercato;
            std::cout << "Inserisci autore da cercare: ";
            std::getline(std::cin, autoreCercato);
            std::vector<Libro> libriAutore = libreria.cercaLibriPerAutore(autoreCercato);
            std::vector<Vinile> viniliAutore = libreria.cercaViniliPerAutore(autoreCercato);

            if (libriAutore.empty() && viniliAutore.empty()) {
                std::cout << "Nessun libro o vinile trovato con l'autore: " << autoreCercato << std::endl;
            } else {
                std::cout << "\nLibri con l'autore " << autoreCercato << ":" << std::endl;
                for (const auto& libro : libriAutore) {
                    std::cout << libro << std::endl;
                }

                std::cout << "\nVinili con l'autore " << autoreCercato << ":" << std::endl;
                for (const auto& vinile : viniliAutore) {
                    std::cout << vinile << std::endl;
                }
            }
        } else if (scelta == 'E' ||scelta == 'e') {
            std::string titoloCercato;
            std::cout << "Inserisci titolo da cercare: ";
            std::getline(std::cin, titoloCercato);
            std::vector<Libro> libriTitolo = libreria.cercaLibriPerTitolo(titoloCercato);
            std::vector<Vinile> viniliTitolo = libreria.cercaViniliPerTitolo(titoloCercato);

            if (libriTitolo.empty() && viniliTitolo.empty()) {
                std::cout << "Nessun libro o vinile trovato con il titolo: " << titoloCercato << std::endl;
            } else {
                std::cout << "\nLibri con il titolo " << titoloCercato << ":" << std::endl;
                for (const auto& libro : libriTitolo) {
                    std::cout << libro << std::endl;
                }

                std::cout << "\nVinili con il titolo "<< titoloCercato << ":" << std::endl;
                for (const auto& vinile : viniliTitolo) {
                    std::cout << vinile << std::endl;
                }
            }
        } else if (scelta == 'F' || scelta == 'f') {
            int idModifica;
            std::cout << "Inserisci ID da modificare: ";
            std::cin >> idModifica;
            std::cin.ignore();

            char sce;
            std::cout << "Inserisci di che tipo è l'ID (v = vinile, l = libro): ";
            std::cin >> sce;
            std::cin.ignore();

            if (std::tolower(sce) == 'l') {
                std::string nuovoTitolo, nuovoAutore, nuovaDataPubblicazione, nuovoTipoCopertina;
                int nuovaQuantita;
                double prezzo;

                std::cout << "Inserisci nuovo Titolo: ";
                std::getline(std::cin, nuovoTitolo);
                if (nuovoTitolo.empty()) {
                    std::cout << "Il titolo non può essere vuoto. Modifica annullata." << std::endl;
                    continue;
                }

                std::cout << "Inserisci nuovo Autore: ";
                std::getline(std::cin, nuovoAutore);
                if (nuovoAutore.empty()) {
                    std::cout << "L'autore non può essere vuoto. Modifica annullata." << std::endl;
                    continue;
                }

                std::cout << "Inserisci nuova Data di Pubblicazione (formato AAAA): ";
                std::getline(std::cin, nuovaDataPubblicazione);
                if (controllaData(nuovaDataPubblicazione) || controllaDatanegativo(nuovaDataPubblicazione)) {
                    std::cout << "La data di pubblicazione non può essere nel futuro o negativa. Modifica annullata." << std::endl;
                    continue;
                }

                std::cout << "Inserisci nuovo tipo di copertina (Dura/Morbida): ";
                std::getline(std::cin, nuovoTipoCopertina);
                if (nuovoTipoCopertina != "Dura" && nuovoTipoCopertina != "Morbida" && nuovoTipoCopertina != "dura" && nuovoTipoCopertina != "morbida") {
                    std::cout << "Tipo di copertina non valido. Deve essere 'Dura' o 'Morbida'. Modifica annullata." << std::endl;
                    continue;
                }

                std::cout << "Inserisci nuova quantità: ";
                std::cin >> nuovaQuantita;
                if (nuovaQuantita <= 0) {
                    std::cout << "La quantità deve essere un numero positivo. Modifica annullata." << std::endl;
                    continue;
                }
                std::cin.ignore();

                std::cout << "Inserisci il nuovo prezzo del libro: ";
                std::cin >> prezzo;
                std::cin.ignore();

                Libro libroModificato(nuovoTitolo, nuovoAutore, nuovaDataPubblicazione, nuovoTipoCopertina, nuovaQuantita, prezzo);
               if (libreria.modificaLibro(idModifica, libroModificato)) {
                std::cout << "Libro con ID " << idModifica << " modificato con successo." << std::endl;
            } else {
                std::cout << "Libro con ID " << idModifica << " non trovato." << std::endl;
            }

            } else if (std::tolower(sce) == 'v') {
                std::string nuovoTitolo, nuovoAutore, nuovaDataPubblicazione;
                double nuovoDiametro, prezzo;
                int nuovaQuantita;

                std::cout << "Inserisci nuovo Titolo: ";
                std::getline(std::cin, nuovoTitolo);
                if (nuovoTitolo.empty()) {
                    std::cout << "Il titolo non può essere vuoto. Modifica annullata." << std::endl;
                    continue;
                }

                std::cout << "Inserisci nuovo Autore: ";
                std::getline(std::cin, nuovoAutore);
                if (nuovoAutore.empty()) {
                    std::cout << "L'autore non può essere vuoto. Modifica annullata." << std::endl;
                    continue;
                }

                std::cout << "Inserisci nuova Data di Pubblicazione (formato AAAA): ";
                std::getline(std::cin, nuovaDataPubblicazione);
                if (controllaData(nuovaDataPubblicazione) || controllaDatanegativo(nuovaDataPubblicazione)) {
                    std::cout << "La data di pubblicazione non può essere nel futuro o negativa. Modifica annullata." << std::endl;
                    continue;
                }

                std::cout << "Inserisci nuovo Diametro: ";
                std::cin >> nuovoDiametro;
                if (nuovoDiametro <= 0) {
                    std::cout << "Il diametro del vinile deve essere un numero positivo. Modifica annullata." << std::endl;
                    continue;
                }

                std::cout << "Inserisci nuova quantità: ";
                std::cin >> nuovaQuantita;
                if (nuovaQuantita <= 0) {
                    std::cout << "La quantità deve essere un numero positivo. Modifica annullata." << std::endl;
                    continue;
                }
                std::cin.ignore();

                std::cout << "Inserisci il nuovo prezzo del vinile: ";
                std::cin >> prezzo;
                std::cin.ignore();

                Vinile vinileModificato(nuovoTitolo, nuovoAutore, nuovaDataPubblicazione, nuovoDiametro, nuovaQuantita, prezzo);
                 if (libreria.modificaVinile(idModifica, vinileModificato)) {
                std::cout << "Vinile con ID " << idModifica << " modificato con successo." << std::endl;
            } else {
                std::cout << "Vinile con ID " << idModifica << " non trovato." << std::endl;
            }

            } else {
                std::cout << "Tipo di ID non valido. Modifica annullata." << std::endl;
            }

            } else if (scelta == 'G' || scelta == 'g') {
                int idEliminazione;
                std::cout << "Inserisci ID del libro da eliminare: ";
                std::cin >> idEliminazione;
                              
            if (libreria.eliminaTutteLeQuantita(idEliminazione)) {
                std::cout << "Articolo elimainato con successo." << std::endl;
            } else {
                 std::cout << "Articolo con ID " << idEliminazione  << " non trovato nella libreria." << std::endl;
            }
        } else if (scelta == 'H' || scelta == 'h') {
            libreria.stampaLibri();
        } else if (scelta == 'I' || scelta == 'i') {

            if (f == 'c') {
                std::string nomeFileSalvataggio;
                std::cout << "Inserisci il percorso del file in cui desideri salvare i libri e i vinili: ";
                std::getline(std::cin, nomeFileSalvataggio);

              if (csv.salvaLibriSuFileCSV(libreria, nomeFileSalvataggio)) {
                std::cout << "Elementi salvati con successo nel file CSV: " << nomeFileSalvataggio << std::endl;
            } else {
                std::cerr << "Errore durante il salvataggio degli elementi nel file CSV: " << nomeFileSalvataggio << std::endl;
            }
      
              } else if (f == 't') {
                std::string nomeFile;
                std::cout << "Inserisci il percorso del file in cui desideri salvare i libri e i vinili: ";
                std::getline(std::cin, nomeFile);

            if (txt.salvaLibriSuFileTxt(libreria, nomeFile)) {
                std::cout << "Elementi salvati con successo nel file TXT: " << nomeFile << std::endl;
            } else {
                std::cerr << "Errore durante il salvataggio degli elementi nel file TXT: " << nomeFile << std::endl;
            }
            } else if (f == 'j') {
                std::string nomeFileSalvataggio;
                std::cout << "Inserisci il percorso del file in cui desideri salvare i libri e i vinili: ";
                std::getline(std::cin, nomeFileSalvataggio);
               if (json.salvaLibriSuFileJSON(libreria, nomeFileSalvataggio)) {
                    std::cout << "Elementi salvati con successo nel file JSON: " << nomeFileSalvataggio << std::endl;
                } else {
                    std::cerr << "Errore durante il salvataggio degli elementi nel file JSON: " << nomeFileSalvataggio << std::endl;
                }
        } }else if (scelta == 'j' || scelta == 'J') {
            if (f == 'c') {

                std::string nomeFileCaricamento;
                std::cout << "Inserisci il percorso del file CSV da cui desideri caricare i libri e i vinili: ";
                std::getline(std::cin, nomeFileCaricamento);
             
              
                 if (csv.caricaFileCSV(libreria, nomeFileCaricamento)) {
                    std::cout << "Elementi caricati con successo dal file CSV: " << nomeFileCaricamento << std::endl;
                } else {
                    std::cerr << "Errore durante il caricamento degli elementi dal file CSV: " << nomeFileCaricamento << std::endl;
                }
            } else if (f == 't') {
                std::string nomeFile;
                std::cout << "Inserisci il percorso del file TXT da cui desideri caricare i libri e i vinili: ";
                std::getline(std::cin, nomeFile);
                if (txt.caricaFileTxt(libreria, nomeFile)) {
                std::cout << "Elementi caricati con successo dal file TXT: " << nomeFile << std::endl;
            } else {
                std::cerr << "Errore durante il caricamento degli elementi dal file TXT: " << nomeFile << std::endl;
            }
            } else if (f == 'j') {
                std::string nomeFileCaricamento;
                std::cout << "Inserisci il percorso del file JSON da cui desideri caricare i libri e i vinili: ";
                std::getline(std::cin, nomeFileCaricamento);
                if (json.caricaFileJSON(libreria, nomeFileCaricamento)) {
                    std::cout << "Elementi caricati con successo dal file JSON: " << nomeFileCaricamento << std::endl;
            } else {
                    std::cerr << "Errore durante il caricamento degli elementi dal file JSON: " << nomeFileCaricamento << std::endl;
            }
                    } 
        }else if(scelta == 'L' || scelta == 'l'){
            stampaBanconoteCassa(cassa);
        }
       else if (scelta == 'M' || scelta == 'm') {
            std::cout << "Esci." << std::endl;
            break;
            
        } else {
            std::cout << "Scelta non valida. Riprova." << std::endl;
        }
    }
       } else if (Tipo == '2'){
            Carrello carrello;
       
            char sceltaCarrello;
            int quantitaDaAcquistare;
             

              char formato;
    while (true) {
        stampaMenu();
        
        std::cin >> sceltaCarrello;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        
             
     if (sceltaCarrello == 'A' || sceltaCarrello == 'a') {
    const std::map<int, Libro>& libriDB = libreria.getLibri();
    const std::map<int, Vinile>& viniliDB = libreria.getVinili();
    int idProdotto, quantita;
    bool idValido = false;

    while (!idValido) {
        std::cout << "\nInserisci l'ID del prodotto da aggiungere al carrello: ";
        std::cin >> idProdotto;
        std::cin.ignore();

        if (libriDB.find(idProdotto) != libriDB.end() || viniliDB.find(idProdotto) != viniliDB.end()) {
            idValido = true;
        } else {
            std::cout << "ID non valido. Riprova." << std::endl;
        }
    }

    std::cout << "Inserisci la quantità da aggiungere: ";
    std::cin >> quantita;
    std::cin.ignore();

    
    if (carrello.contieneProdotto(idProdotto)) {
        std::cout << "Il prodotto è già presente nel carrello." << std::endl;
    } else {
      
        bool disponibile = false;
        auto libroIt = libriDB.find(idProdotto);
        auto vinileIt = viniliDB.find(idProdotto);

       
        if (libroIt != libriDB.end()) {
            if (libroIt->second.getQuantita() >= quantita) {
                disponibile = true;
                std::cout << "ID Prodotto: " << idProdotto << ", Titolo: " << libroIt->second.titolo  << ", Autore: " << libroIt->second.autore << ", Data Pubblicazione:: " << libroIt->second.dataPubblicazione << ", Tipo copertina: " << libroIt->second.getTipoCopertina() << ", Quantità Disponibile: " << libroIt->second.getQuantita() << ", Prezzo :" << libroIt->second.prezzo << std::endl;
            }
        } else if (vinileIt != viniliDB.end()) {
            if (vinileIt->second.getQuantita() >= quantita) {
                disponibile = true;
                std::cout << "ID Prodotto: " << idProdotto  << ", Titolo: " << vinileIt->second.titolo << ", Artista: " << vinileIt->second.autore << ", Data Pubblicazione: " << vinileIt->second.dataPubblicazione  << ", Diametro " << vinileIt->second.getDiametro()  << ", Quantità Disponibile: " << vinileIt->second.getQuantita()  << ", Prezzo :" << vinileIt->second.prezzo << std::endl;
            }
        }

        if (disponibile) {
            carrello.aggiungiProdotto(idProdotto, quantita);
            std::cout << "Prodotto aggiunto al carrello." << std::endl;
        } else {
            std::cout << "Quantità non disponibile in magazzino per il prodotto selezionato." << std::endl;
        }
    }
}
else if (sceltaCarrello == 'B' || sceltaCarrello == 'b') {
        int idProdotto;
        std::cout << "\nInserisci l'ID del prodotto da rimuovere dal carrello: ";
        std::cin >> idProdotto;
        std::cin.ignore();
        if (carrello.getProdotti().empty()) {
            std::cout << "Il carrello è vuoto." << std::endl;
        } else {
            carrello.rimuoviProdotto(idProdotto);
            std::cout << "Prodotto rimosso dal carrello." << std::endl;
        }

    } else if (sceltaCarrello == 'C' || sceltaCarrello == 'c') {
        std::cout << "\nContenuto del carrello:" << std::endl;

        const std::map<int, Libro>& libriDB = libreria.getLibri();
        const std::map<int, Vinile>& viniliDB = libreria.getVinili();

        if (carrello.getProdotti().empty()) {
            std::cout << "Il carrello è vuoto." << std::endl;
        } else {
            for (const auto& prodotto : carrello.getProdotti()) {
                auto libroIt = libriDB.find(prodotto.id);
                
                if (libroIt != libriDB.end()) {
                    int quantitaLibro = carrello.getQuantita(prodotto.id);
                    std::cout << "Libro :"<< "ID: " << libroIt->second.getId()   << ", Titolo: " << libroIt->second.getTitolo()  << ", Autore: " << libroIt->second.getAutore()   << ", Tipo copertina: " << libroIt->second.getTipoCopertina() << ", Data pubblicazione: " << libroIt->second.getDataPubblicazione() <<", quantità : " << quantitaLibro <<  ", Prezzo: " << libroIt->second.getPrezzo() << " euro." << std::endl;
                } else {
                    auto vinileIt = viniliDB.find(prodotto.id);
                    if (vinileIt != viniliDB.end()) {
                        int quantitaVinile = carrello.getQuantita(prodotto.id);
                        std::cout << "Vinile :"<< "ID: " << vinileIt->second.getId()   << ", Titolo: " << vinileIt->second.getTitolo()  << ", Autore: " << vinileIt->second.getAutore()   << ", Diametro " << vinileIt->second.getDiametro() << ", Data pubblicazione: " << vinileIt->second.getDataPubblicazione() <<", quantità : " << quantitaVinile <<  ", Prezzo: " << vinileIt->second.getPrezzo() << " euro." << std::endl;
                    }
                }
            }
        }

        double totale = carrello.totale(libriDB, viniliDB);
        std::cout << "\nIl totale del carrello è: " << std::fixed << std::setprecision(2) << totale << " euro." << std::endl;

    } 
    else if (sceltaCarrello == 'D' || sceltaCarrello == 'd') {
    if (carrello.getProdotti().empty()) {
        std::cout << "Il carrello è vuoto." << std::endl;
    } else {
        double totale = carrello.totale(libreria.getLibri(), libreria.getVinili());
        std::cout << "\nIl totale del carrello è: " << std::fixed << std::setprecision(2) << totale << " euro." << std::endl;

        int banconote50, banconote20, banconote10, banconote5, banconote2, banconote1;
        std::cout << "Inserisci il numero di banconote da 50 euro: ";
        std::cin >> banconote50;
        std::cout << "Inserisci il numero di banconote da 20 euro: ";
        std::cin >> banconote20;
        std::cout << "Inserisci il numero di banconote da 10 euro: ";
        std::cin >> banconote10;
        std::cout << "Inserisci il numero di banconote da 5 euro: ";
        std::cin >> banconote5;
        std::cout << "Inserisci il numero di monete da 2 euro: ";
        std::cin >> banconote2;
        std::cout << "Inserisci il numero di monete da 1 euro: ";
        std::cin >> banconote1;

        int importoInserito = banconote50 * 5000 + banconote20 * 2000 +
                              banconote10 * 1000 + banconote5 * 500 +
                              banconote2 * 200 + banconote1 * 100;

        int totaleCentesimi = static_cast<int>(totale * 100);

        if (importoInserito >= totaleCentesimi) {

            int restoCentesimi = importoInserito - totaleCentesimi;

            double restoEuro = static_cast<double>(restoCentesimi) / 100;

             if (cassa.controllaResto(restoEuro)) {
            std::cout << "Pagamento accettato. Il tuo resto è: " << std::fixed << std::setprecision(2) << restoEuro << " euro." << std::endl;

            int banc50 = restoCentesimi / 5000;
            restoCentesimi %= 5000;
          
            int banc20 = restoCentesimi / 2000;
            restoCentesimi %= 2000;

            int banc10 = restoCentesimi / 1000;
            restoCentesimi %= 1000;

            int banc5 = restoCentesimi / 500;
            restoCentesimi %= 500;

            int mone2 = restoCentesimi / 200;
            restoCentesimi %= 200;

            int mone1 = restoCentesimi / 100;
      
            std::cout << "Banconote da 50 euro: " << banc50 << std::endl;
            std::cout << "Banconote da 20 euro: " << banc20 << std::endl;
            std::cout << "Banconote da 10 euro: " << banc10 << std::endl;
            std::cout << "Banconote da 5 euro: " << banc10 << std::endl;
            std::cout << "Monete da 2 euro: " << mone2 << std::endl;
            std::cout << "Monete da 1 euro: " << mone1 << std::endl;



            std::cout << "Resto restituito correttamente." << std::endl;
            cassa.aggiungiBanconote(Banconota(50), banconote50);
            cassa.aggiungiBanconote(Banconota(20), banconote20);
            cassa.aggiungiBanconote(Banconota(10), banconote10);
            cassa.aggiungiBanconote(Banconota(5), banconote5);
            cassa.aggiungiBanconote(Banconota(2), banconote2);
            cassa.aggiungiBanconote(Banconota(1), banconote1);


            cassa.rimuoviBanconote(Banconota(50), banc50);
            cassa.rimuoviBanconote(Banconota(20), banc20);
            cassa.rimuoviBanconote(Banconota(10), banc10);
            cassa.rimuoviBanconote(Banconota(5), banc5);
            cassa.rimuoviBanconote(Banconota(2), mone2);
            cassa.rimuoviBanconote(Banconota(1), mone1);

            } else {
                std::cout << "Errore: banconote insufficienti in cassa per restituire il resto." << std::endl;
            }

            const auto& prodottiCarrello = carrello.getProdotti();
            for (const auto& prodotto : prodottiCarrello) {
                int idProdotto = prodotto.id;
                int quantitaAcquistata = prodotto.quant;

                auto libroIt = libreria.getLibri().find(idProdotto);
                if (libroIt != libreria.getLibri().end()) {
                    libreria.eliminaLibro(idProdotto, quantitaAcquistata);
                } else {
                    auto vinileIt = libreria.getVinili().find(idProdotto);
                    if (vinileIt != libreria.getVinili().end()) {
                        libreria.eliminaLibro(idProdotto, quantitaAcquistata);
                    }
                }
            }

          
            carrello.svuotaCarrello();

            
        } else {
            std::cout << "Denaro insufficiente. Mancano le seguenti banconote e monete per completare il pagamento:" << std::endl;
            std::cout << "Banconote da 50 euro: " << (totaleCentesimi - importoInserito) / 5000 << std::endl;
            std::cout << "Banconote da 20 euro: " << ((totaleCentesimi - importoInserito) % 5000) / 2000 << std::endl;
            std::cout << "Banconote da 10 euro: " << (((totaleCentesimi - importoInserito) % 5000) % 2000) / 1000 << std::endl;
            std::cout << "Banconote da 5 euro: " << ((((totaleCentesimi - importoInserito) % 5000) % 2000) % 1000) / 500 << std::endl;
            std::cout << "Monete da 2 euro: " << (((((totaleCentesimi - importoInserito) % 5000) % 2000) % 1000) % 500) / 200 << std::endl;
            std::cout << "Monete da 1 euro: " << (((((totaleCentesimi - importoInserito) % 5000) % 2000) % 1000) % 500) % 200 / 100 << std::endl;
        }

        if(f == 'c'){
        csv.salvaLibriSuFileCSV(libreria, "salvalibri.csv");
        }else if(f == 'j'){
            json.salvaLibriSuFileJSON(libreria, "salvalibri.json");
        }else if(f == 't'){
            txt.salvaLibriSuFileTxt(libreria, "salvalibri.txt");
        }
        }
}
        else if (sceltaCarrello == 'E' || sceltaCarrello == 'e') {
            libreria.stampaLibri();

     
        } 
          

        else if (sceltaCarrello == 'F' || sceltaCarrello == 'f') {
            std::cout << "Uscita dal programma." << std::endl;
            
            break;
        }


        } 
    }else if(Tipo == '3'){
           std::cout << "Uscita dal programma." << std::endl;
           return 0; 
        }
        
}
}
    
