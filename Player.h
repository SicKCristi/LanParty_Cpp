#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <fstream>
#include <limits.h>
#include <iomanip>
class Player
{
private:
    std::string firstName;
    std::string secondName;
    int points;
public:
    Player();
    Player(std::string,std::string,int);
    std::string get_firstName() const;
    std::string get_secondName() const;
    int get_points() const;
    friend std::ostream& operator<<(std::ostream&,const Player&);
};
#endif // PLAYER_H
