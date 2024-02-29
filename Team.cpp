#include "Team.h"
Team::Team()
{
    nume_echipa="";
    medie_xp=-1;
    nr_membrii=0;
}
Team::Team(std::string ne,int nj,std::list<Player> j)
:nume_echipa(ne),nr_membrii(nj),jucatori(j)
{
    medie_xp=calcul_medie();
}
Team::Team(std::string ne,float mx,int nj,std::list<Player> j)
:nume_echipa(ne),medie_xp(mx),nr_membrii(nj),jucatori(j)
{
}
std::string Team::get_nume_echipa() const
{
    return nume_echipa;
}
float Team::calcul_medie() const
{
    float ma=0;
    auto it=jucatori.begin();
    while(it!=jucatori.end())
    {
        ma+=it->get_points();
        it++;
    }
    return ma/nr_membrii;
}
float Team::get_medie_xp() const
{
    return medie_xp;
}
int Team::get_nr_membrii() const
{
    return nr_membrii;
}
std::list<Player> Team::get_jucatori() const
{
    return jucatori;
}
std::ostream& operator<<(std::ostream& os, const Team& t)
{
    os<<"Informatii despre echipa:"<<std::endl;
    os<<"Numele echipei:"<<t.nume_echipa<<std::endl;
    os<<"Media de puncte a echipei:"<<t.medie_xp<<std::endl;
    os<<"Numarul de jucatori din echipa:"<<t.nr_membrii<<std::endl;
    os<<"Jucatorii din echipa:"<<std::endl<<std::endl;
    std::list<Player> aux(t.jucatori);
    int cont=0;
    auto it=aux.begin();
    while(it!=aux.end())
    {
        os<<"Jucatorul "<<++cont<<":"<<std::endl;
        os<<(*it)<<std::endl;
        it++;
    }
    os<<std::endl;
    return os;
}
bool operator<=(const Team& t1,const Team& t2)
{
    return (t1.medie_xp<=t2.medie_xp);
}
bool operator<(const Team& t1,const Team& t2)
{
    if(t1.medie_xp==t2.medie_xp)
        return t1.nume_echipa<t2.nume_echipa;
    else
        return t1.medie_xp<t2.medie_xp;
}
bool operator>(const Team& t1,const Team& t2)
{
    return !(t1<=t2);
}