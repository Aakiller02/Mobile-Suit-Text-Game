#include <string>
#include <string.h>

struct playerSuit // This is the data for the players current suit
{
    int entryNum;
    std::string name;
    float health;
    int attackPoints;
    int speedPoints;
    int defencePoint;

    playerSuit(){ // Once again Constructors and Default Constructurs for ease of use
        this->entryNum = 0;
        this->name = "No Entry";
        this->health = 0;
        this->attackPoints = 0;
        this->speedPoints = 0;
        this->defencePoint = 0;
    }

    playerSuit(int entNum, std::string name, int att, int spe, int def, int hp){
        this->entryNum = entNum;
        this->name = name;
        this->health = hp;
        this->attackPoints = att;
        this->speedPoints = spe;
        this->defencePoint = def;
    }
};