#ifndef STIVA_ECHIPE_H
#define STIVA_ECHIPE_H
#include "Team.h"
class Stiva_echipe
{
private:
    std::stack<Team> echipe;
public:
    Stiva_echipe();
    Stiva_echipe(std::stack<Team>);
    int size() const;
    void insert(const Team&);
    std::stack<Team> get_echipe() const;
    float media_xp_cea_mai_mica() const;
    friend std::ostream& operator<<(std::ostream&,const Stiva_echipe&);
    void citire_date_din_fisier(const std::string&);
    void afisare_echipe_in_fisier(const std::string&);
    void eliminare_echipe_necesare(int);
    void clear();
};
#endif