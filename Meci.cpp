#include "Meci.h"
Meci::Meci()
{
    echipa1=Team();
    echipa2=Team();
}
Meci::Meci(const Team& t1,const Team& t2)
:echipa1(t1),echipa2(t2)
{
}
Team Meci::get_echipa1() const
{
    return echipa1;
}
Team Meci::get_echipa2() const
{
    return echipa2;
}
std::ostream& operator<<(std::ostream& os,const Meci& m)
{
    os<<std::setw(32)<<std::left<<m.get_echipa1().get_nume_echipa();
    os<<" - ";
    os<<std::setw(32)<<std::right<<m.get_echipa2().get_nume_echipa();
    os<<std::endl;
    return os;
}