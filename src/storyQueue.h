#include <string>
#include <string.h>

struct storyBlock{ //This is a struct that holds all the story lines for the intro function
    std::string lines;
    bool hasChoice;
    std::string choice1;
    std::string choice2;
    int waitTime;
    storyBlock *next;

    storyBlock(string lineSet, bool hasChoice, string choice1, string choice2, int waitTime){
        this->lines = lineSet;
        this->hasChoice = hasChoice;
        this->waitTime = waitTime;
        this->choice1 = choice1;
        this->choice2 = choice2;
        next = nullptr;
    }
};