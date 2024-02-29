#ifndef COADA_MECIURI_H
#define COADA_MECIURI_H
#include "Meci.h"
#include "Stiva_echipe.h"
class Coada_meciuri
{
private:
    std::queue<Meci> meciuri;
public:
    Coada_meciuri();
    Coada_meciuri(const std::queue<Meci>&);
    void clear();
    void creare_runda_curenta(const Stiva_echipe&);
    void invingatori_si_pierzatori(Stiva_echipe&,Stiva_echipe&);
    std::list<Team> concurs(Stiva_echipe&,const std::string&);
};
#endif 