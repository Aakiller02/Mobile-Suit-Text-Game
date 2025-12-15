#include <string>
#include <string.h>

struct playerData{ //This is a struct that holds all the configuration settings for the game
    bool playerSide;

    std::string getplayerSide(){
        if (playerSide){
            return "Earth Alliance"; // Earth Alliance
        } else {
            return "Zeon Republic"; // Zeon Republic
        }
    }
};