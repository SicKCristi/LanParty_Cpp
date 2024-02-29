#include "Coada_meciuri.h"
Coada_meciuri::Coada_meciuri()
{
}
Coada_meciuri::Coada_meciuri(const std::queue<Meci>& m)
:meciuri(m)
{
}
void Coada_meciuri::clear()
{
    while(!meciuri.empty())
    {
        meciuri.pop();
    }
}
void Coada_meciuri::creare_runda_curenta(const Stiva_echipe& stiva)
{
    std::stack<Team> aux(stiva.get_echipe());
    while(!aux.empty())
    {
        Team aux2(aux.top());
        aux.pop();
        meciuri.push(Meci(aux2,aux.top()));
        aux.pop();
    }
}
void Coada_meciuri::invingatori_si_pierzatori(Stiva_echipe& castigatori,Stiva_echipe& invinsi)
{
    std::queue<Meci> aux=meciuri;
    Team castigatoarea;
    while(!aux.empty())
    {
        Meci aux2(aux.front());
        if(aux2.get_echipa1()>aux2.get_echipa2())
        {
            castigatoarea=aux2.get_echipa1();
            castigatori.insert(Team(castigatoarea.get_nume_echipa(),castigatoarea.get_medie_xp()+1,castigatoarea.get_nr_membrii(),castigatoarea.get_jucatori()));
            invinsi.insert(aux2.get_echipa2());
        }
        else
        {
            castigatoarea=aux2.get_echipa2();
            castigatori.insert(Team(castigatoarea.get_nume_echipa(),castigatoarea.get_medie_xp()+1,castigatoarea.get_nr_membrii(),castigatoarea.get_jucatori()));
            invinsi.insert(aux2.get_echipa1());
        }
        aux.pop();
    }
}
std::list<Team> Coada_meciuri::concurs(Stiva_echipe& stiva,const std::string& nume_fisier)
{
    std::list<Team> ultimele_opt;

    std::ofstream g(nume_fisier,std::ios::app);
    if(!g)
    {
        std::cout<<"Fisierul nu a putut fi deschis!"<<std::endl;
        return ultimele_opt;
    }
    g<<std::endl;

    creare_runda_curenta(stiva);

    stiva.clear();

    Stiva_echipe castigatori;
    Stiva_echipe invinsi;

    int nr_runda=1;
    while(meciuri.size()>=1)
    {
        if(meciuri.size()==4)
        {
            std::queue<Meci> aux(meciuri);
            while(!aux.empty())
            {
                ultimele_opt.push_front(aux.front().get_echipa1());
                ultimele_opt.push_front(aux.front().get_echipa2());
                aux.pop();
            }
        }

        g<<"--- ROUND NO:"<<nr_runda++<<std::endl;
        std::queue<Meci> aux(meciuri);
        while(!aux.empty())
        {
            g<<aux.front();
            aux.pop();
        }
        g<<std::endl;

        invingatori_si_pierzatori(castigatori,invinsi);

        invinsi.clear();

        g<<"WINNERS OF ROUND NO:"<<nr_runda-1<<std::endl;
        std::stack<Team> echipe_castigatoare(castigatori.get_echipe());
        while(!echipe_castigatoare.empty())
        {
            g<<std::setw(33)<<std::left<<echipe_castigatoare.top().get_nume_echipa()<<" -  "<<std::fixed<<std::setprecision(2)<<echipe_castigatoare.top().get_medie_xp()<<std::endl;
            echipe_castigatoare.pop();
        }
        if(meciuri.size()>1)
            g<<std::endl;
        while(!meciuri.empty())
        {
            meciuri.pop();
        }

        if(castigatori.size()>1)
            creare_runda_curenta(castigatori);
        else
            break;
        castigatori.clear();
    }
    return ultimele_opt;
 }