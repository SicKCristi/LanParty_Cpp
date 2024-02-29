#include "Stiva_echipe.cpp"
#include "Coada_meciuri.cpp"
#include "Arbore_echipe.cpp"
#include "Player.cpp"
#include "Meci.cpp"
#include "Team.cpp"
#define NR_TASKURI 5
void citire_taskuri(const std::string& nume_fisier,std::vector<bool> &taskuri)
{
    std::ifstream f(nume_fisier);
    if(!f)
    {
        std::cout<<"Fisierul nu a putut fi deschis!"<<std::endl;
        return;
    }
    bool aux;
    for(int i=0;i<NR_TASKURI;i++)
    {
        f>>aux;
        taskuri[i]=aux;
    }
    f.close();
}
int cea_mai_mare_putere_a_lui_2(int n)
{
    int nr=1;
    while(nr*2<=n)
        nr*=2;
    return nr;
}
int main(int argc,char* argv[])
{
    std::vector<bool> taskuri(NR_TASKURI);
    citire_taskuri(argv[1],taskuri);

    Stiva_echipe stiva;
    Coada_meciuri meciuri;
    std::list<Team> lista_ultimele_opt_echipe;
    Arbore_echipe arbore;

    if(taskuri[0]==1)
    {
        stiva.citire_date_din_fisier(argv[2]);
        stiva.afisare_echipe_in_fisier(argv[3]);
    }
    if(taskuri[1]==1)
    {
        stiva.eliminare_echipe_necesare(stiva.size()-cea_mai_mare_putere_a_lui_2(stiva.size()));
        stiva.afisare_echipe_in_fisier(argv[3]);
    }
    if(taskuri[2]==1)
    {
        lista_ultimele_opt_echipe=meciuri.concurs(stiva,argv[3]);
        meciuri.clear();
    }
    if(taskuri[3]==1)
    {
        arbore=Arbore_echipe(lista_ultimele_opt_echipe);
        arbore.afisare_clasament_ultimele_opt_echipe(argv[3]);
        arbore.clear();
    }
    if(taskuri[4]==1)
    {
        arbore=Arbore_echipe(lista_ultimele_opt_echipe);
        arbore.afisare_echipe_de_pe_nivelul_2(argv[3]);
        arbore.clear();
        lista_ultimele_opt_echipe.clear();
    }
    taskuri.clear();
    return 0;
}