#include "Stiva_echipe.h"
Stiva_echipe::Stiva_echipe()
{
}
Stiva_echipe::Stiva_echipe(std::stack<Team> e)
:echipe(e)
{
}
int Stiva_echipe::size() const
{
    int nr=0;
    std::stack<Team> aux(echipe);
    while(!aux.empty())
    {
        nr++;
        aux.pop();
    }
    return nr;
}
std::stack<Team> Stiva_echipe::get_echipe() const
{
    return echipe;
}
float Stiva_echipe::media_xp_cea_mai_mica() const
{
    float media_minima=INT_MAX;
    std::stack<Team> aux(echipe);
    while(!aux.empty())
    {
        Team aux2=aux.top();
        if(aux2.get_medie_xp()<media_minima)
            media_minima=aux2.get_medie_xp();
        aux.pop();
    }
    return media_minima;
}
std::ostream& operator<<(std::ostream& os,const Stiva_echipe& s)
{
    os<<"Informatii despre stiva de echipe:"<<std::endl;
    int cont=0;
    std::stack<Team> aux(s.echipe);
    while(!aux.empty())
    {
        os<<"Echipa "<<++cont<<":"<<std::endl;
        os<<aux.top()<<std::endl;
        aux.pop();
    }
    os<<std::endl;
    return os;
}
void Stiva_echipe::citire_date_din_fisier(const std::string& nume_fisier)
{
    std::fstream f(nume_fisier);
    if(!f)
    {
        std::cout<<"Fisierul nu a putut fi deschis!"<<std::endl<<std::endl;
        return;
    }

    char buffer[256];
    f.getline(buffer,256,'\n');
    int nr_echipe=atoi(buffer);

    int cont=0;

    int nr_membrii;
    std::string nume_echipa;
    std::list<Player> jucatori;
    char *p;

    while(cont<nr_echipe)
    {
        f.getline(buffer,256,'\n');
        p=strtok(buffer," ");
        nr_membrii=atoi(p);
        p=strtok(NULL," ");
        while(p!=NULL)
        {
            nume_echipa+=p;
            p=strtok(NULL," ");
            if(p!=NULL)
             nume_echipa+=" ";
        }
        for(int i=0;i<nr_membrii;i++)
        {
            std::string firstName;
            std::string secondName;
            int points;

            f.getline(buffer,256,'\n');
            p=strtok(buffer," ");
            firstName=p;
            p=strtok(NULL," ");
            secondName=p;
            p=strtok(NULL," ");
            points=atoi(p);
            jucatori.push_front(Player(firstName,secondName,points));
        }
        cont++;
        echipe.push(Team(nume_echipa,nr_membrii,jucatori));
        jucatori.clear();
        nume_echipa.clear();
        f.getline(buffer,256,'\n');
    }
    f.close();
}
void Stiva_echipe::afisare_echipe_in_fisier(const std::string& nume_fisier)
{
    std::ofstream f(nume_fisier);
    if(!f)
    {
        std::cout<<"Fisierul nu a putut fi deschis!"<<std::endl;
        return;
    }
    std::stack<Team> aux(echipe);
    while(!aux.empty())
    {
        std::string aux2=aux.top().get_nume_echipa();
        f<<aux2;
        aux.pop();
        if(!aux.empty())
            f<<std::endl;
    }
    f<<std::endl;
}
void Stiva_echipe::eliminare_echipe_necesare(int echipe_de_eliminat)
{
    bool gasit;
    while(echipe_de_eliminat)
    {
        gasit=0;
        float medie_xp_minima=media_xp_cea_mai_mica();
        std::stack<Team> aux_eliminare;
        while(!echipe.empty())
        {
            Team aux2(echipe.top());
            if(abs(medie_xp_minima-aux2.get_medie_xp())>=0.000001 || (abs(medie_xp_minima-aux2.get_medie_xp())<0.000001 && gasit==1))
                aux_eliminare.push(aux2);
            else
                if(abs(medie_xp_minima-aux2.get_medie_xp())<0.000001)
                    gasit=1;
            echipe.pop();
        }
        while(!aux_eliminare.empty())
        {
            Team aux2(aux_eliminare.top());
            echipe.push(aux2);
            aux_eliminare.pop();
        }
        echipe_de_eliminat--;
    }
}
void Stiva_echipe::clear()
{
    while(!echipe.empty())
    {
        echipe.pop();
    }
}
void Stiva_echipe::insert(const Team& t)
{
    echipe.push(t);
}