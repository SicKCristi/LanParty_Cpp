#ifndef MECI_H
#define MECI_H
#include "Team.h"
class Meci
{
private:
    Team echipa1;
    Team echipa2;
public:
    Meci();
    Meci(const Team&,const Team&);
    Team get_echipa1() const;
    Team get_echipa2() const;
    friend std::ostream& operator<<(std::ostream&,const Meci&);
};
#endif /// MECI_H