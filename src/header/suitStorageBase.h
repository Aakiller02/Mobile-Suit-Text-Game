#include <string>
#include <string.h>

struct suitStorageBase //This is the data for storage system that will let the player the ability to choose,edit,scrap and etc
{
    int entryNum;
    std::string name;
    int attackPoints;
    int speedPoints;
    int defencePoint;
    suitStorageBase *next;

    suitStorageBase(int entNum, std::string name, int att, int spe, int def){//Constructor to ease data inputting
        this->entryNum = entNum;
        this->name = name;
        this->attackPoints = att;
        this->speedPoints = spe;
        this->defencePoint = def;
        this->next = NULL;
    }
};