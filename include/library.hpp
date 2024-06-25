#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include <map>
#include <vector>
#include <string>
#include "book.hpp"
#include "vinili.hpp" 
#include "cassa.hpp"

class Libreria {
private:
     

  int prossimoId = 1;
  int ID;
  
  Cassa cassa;
    
    
  

public:
    const std::map<double, int>& getBanconote() const ;


     const Cassa& getCassa() const;
    Cassa& getCassa();
    void svuotaLibreria();
        bool controllaDuplicato(const Libro& libro) const;
    bool controllaDuplicatovinili(const Vinile& vinile) const; 

    bool controllaDuplicatiID(int id) const;

    std::map<int, Libro> libri;
    std::map<int, Vinile> vinili; 
      void aggiungiLibro(const Libro& libro, int quantita = 1);
    void aggiungiVinile(const Vinile& vinile, int quantita = 1);
    bool eliminaLibro(int id, int quantita = 1);
    void stampaLibri() const;
    std::vector<Libro> cercaLibriPerAutore(const std::string& autore) const;
    std::vector<Libro> cercaLibriPerTitolo(const std::string& titolo) const;
    std::vector<Vinile> cercaViniliPerAutore(const std::string& autore) const;
    std::vector<Vinile> cercaViniliPerTitolo(const std::string& titolo) const;
    const std::map<int, Libro>& getLibri() const;
    const std::map<int, Vinile>& getVinili() const;

    bool decrementaQuantita(int id, int quantita) ;

    bool modificaLibro(int id, const Libro& nuovoLibro);
    bool modificaVinile(int id,  const Vinile& nuovoVinile);
    bool controllaEsistenzaLibro(int id);
    bool controllaEsistenzaVinile(int id);
    bool eliminaTutteLeQuantita(int id);



    bool controllaDuplicatiIDVinile(int id) const ;
    int getQuantitaLibro(const Libro& libro) const;
    int getQuantitaVinile(const Vinile& vinile) const;

};

#endif // LIBRARY_HPP
