#include "Player.h"
Player::Player()
{
    firstName="";
    secondName="";
    points=-1;
}
Player::Player(std::string fn,std::string sn,int p)
:firstName(fn),secondName(sn),points(p)
{
}
std::string Player::get_firstName() const
{
    return firstName;
}
std::string Player::get_secondName() const
{
    return secondName;
}
int Player::get_points() const
{
    return points;
}
std::ostream& operator<<(std::ostream& os,const Player& p)
{
    os<<"Informatii despre jucatori:"<<std::endl;
    os<<"Numele:"<<p.firstName<<std::endl;
    os<<"Prenumele:"<<p.secondName<<std::endl;
    os<<"Punctele de experienta:"<<p.points<<std::endl;
    os<<std::endl;
    return os;
}

