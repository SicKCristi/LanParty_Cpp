#include "Arbore_echipe.h"
Arbore_echipe::Arbore_echipe()
{
}
Arbore_echipe::Arbore_echipe(std::multiset<Team> e)
:echipele(e)
{
}
Arbore_echipe::Arbore_echipe(const std::list<Team> &e)
{
    auto it=e.begin();
    while(it!=e.end())
    {
        echipele.insert(*it);
        it++;
    }
}
void Arbore_echipe::afisare_clasament_ultimele_opt_echipe(const std::string& nume_fisier) const
{
    std::ofstream g(nume_fisier,std::ios::app);
    if(!g)
    {
        std::cout<<"Fisierul nu a putut fi deschis!"<<std::endl;
        return;
    }
    g<<std::endl;

    g<<"TOP 8 TEAMS:"<<std::endl;
    auto it=echipele.end();
    while(it!=echipele.begin())
    {
        it--;
        g<<std::setw(33)<<std::left<<it->get_nume_echipa()<<" -  "<<std::fixed<<std::setprecision(2)<<it->get_medie_xp()<<std::endl;

    }
    g.close();
}
void Arbore_echipe::afisare_echipe_de_pe_nivelul_2(const std::string& nume_fisier) const
{
    std::ofstream g(nume_fisier,std::ios::app);
    if(!g)
    {
        std::cout<<"Fisierul nu a putut fi deschis!"<<std::endl;
        return;
    }
    g<<std::endl;

    g<<"THE LEVEL 2 TEAMS ARE:"<<std::endl;
    auto it=echipele.end();
    while(it!=echipele.begin())
    {
        it--;
        g<<it->get_nume_echipa()<<std::endl;
        it--;
    }
    g.close();
}
void Arbore_echipe::clear()
{
    echipele.clear();
}
