#ifndef ARBORE_ECHIPE_H
#define ARBORE_ECHIPE_H
#include "Team.h"
class Arbore_echipe
{
private:
    std::multiset<Team> echipele;
public:
    Arbore_echipe();
    Arbore_echipe(std::multiset<Team>);
    Arbore_echipe(const std::list<Team>&);
    void afisare_clasament_ultimele_opt_echipe(const std::string&) const;
    void afisare_echipe_de_pe_nivelul_2(const std::string&) const;
    void clear();
};
#endif /// ARBORE_ECHIPE_H
