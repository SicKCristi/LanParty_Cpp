#ifndef TEAM_H
#define TEAM_H
#include "Player.h"
class Team
{
private:
    std::string nume_echipa;
    float medie_xp;
    int nr_membrii;
    std::list<Player> jucatori;
public:
    Team();
    Team(std::string,int,std::list<Player>);
    Team(std::string,float,int,std::list<Player>);
    std::string get_nume_echipa() const;
    float calcul_medie() const;
    float get_medie_xp() const;
    int get_nr_membrii() const;
    std::list<Player> get_jucatori() const;
    friend std::ostream& operator<<(std::ostream&, const Team&);
    friend bool operator<=(const Team&,const Team&);
    friend bool operator<(const Team&,const Team&);
    friend bool operator>(const Team&,const Team&);
};
#endif // TEAM_H
