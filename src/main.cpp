#include <iostream>
#include <iomanip>
#include <istream>
#include <ostream>
#include <cstdlib>
#include <string>
#include <string.h>
#include <limits>
#include <thread>
#include <vector>
#include <chrono> //Don't wanna mess with any of these, they're required for the code to even remotely function
#include "header/suitHangar.h"

using namespace std;//So that i won't need to std over and over again
using namespace this_thread; //Apparently this is apart of a function that let me do delays
using namespace chrono; //This part is the how many seconds/minutes to wait

struct storyBlock{ //This is a struct that holds all the story lines for the intro function
    string lines;
    bool hasChoice;
    string choice1;
    string choice2;
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

struct storyQueue{ //This is the main story queue that holds all the story lines together
    storyBlock *front;
    storyBlock *rear;
    storyBlock *newptr;
    storyBlock *tempptr;

    int choiceResult;
    int waitTime;

    storyQueue(){
        front = nullptr;
        rear = nullptr;
        newptr = nullptr;
    }

    void enqueue(string lineSet, bool hasChoice, string choice1, string choice2, int waitTime){
        newptr = new storyBlock(lineSet, hasChoice, choice1, choice2, waitTime);

        if (front == nullptr){
            front = newptr;
            rear = newptr;
        } else {
            rear->next = newptr;
            rear = newptr;
        }
    }

    string dequeue(){
        if (front == nullptr){
            cout << "No more story lines!";
            return "";
        } else {
            tempptr = front;
            front = front->next;
            string storyText = tempptr->lines;
            if (front == nullptr){
                front = nullptr;
            }
            delete tempptr;
            return storyText;
        }
    };

    void dislayStoryLine(){
        while (front != nullptr){
            if (front->hasChoice == true){
                string choice1 = front->choice1;
                string choice2 = front->choice2;
                cout << dequeue() << endl;
                sleep_for(seconds(waitTime));
                cout << "1. " << choice1 << endl;
                cout << "2. " << choice2 << endl;
                cout << "Enter your choice: ";
                cin >> ws;
                cin >> choiceResult;
                break;
            } else {
                waitTime = front->waitTime;
                cout << dequeue() << endl;
                if (front != nullptr){
                    sleep_for(seconds(waitTime));
                } else {
                    cout << "Press enter to continue..." << endl;
                    sleep_for(seconds(2));
                    cin.ignore();
                    cin.get();
                    system("clear");
                }
            }

            if (front == nullptr){
                break;
            }
        }
    }
};

string stats(int stat){ // This function returns string for the stats number...Basically converts the points to understandable level of sort
    if (stat < 5){
        return "Low";
    } else if (stat < 10 && stat > 4){
        return "Medium";
    } else if (stat < 15 && stat > 9){
        return "High";
    } else return 0;
}

int hpInit(int defStat){ // THis function return integer base on the amount of defences a suit have
    if (defStat < 5){
        return 80;
    } else if (defStat < 10 && defStat > 4){
        return 100;
    } else if (defStat < 15 && defStat > 9){
        return 150;
    } else return 0;
}

void intro(suitHangar player){ // This function is where the queue entry is called
    storyQueue introStory;
    system("clear");
    // To use this function, just call introStory.enqueue("A Story Line Text that you want", hasChoice(true/false), "Choice 1", "Choice 2", waitTimeInSeconds);
    // If hasChoice is false, just put empty string for choice 1 and choice 2; also has choice just like its name mean if your text want to have any kind of choices
    // The wait time is basically how many seconds you want the text to stay before moving on to the next one
    introStory.enqueue("In the year 0025...", false, "", "", 2);
    introStory.enqueue("Humanity has moved its burgening population to space...", false, "", "", 3);
    introStory.enqueue("Creating a massive divide between people of space and those who still inhabit the earth.", false, "", "", 3);
    introStory.enqueue("Conflict Arises between both faction...", false, "", "", 4);
    introStory.enqueue("As days passed by... the tension kept rising and rising...", false, "", "", 3);
    introStory.enqueue("Until eventually...", false, "", "", 2);
    introStory.enqueue("A colony sector within site 7, annouced an independance from the Earth Alliance.", false, "", "", 3);
    introStory.enqueue("Calling themselves as the Principality of Zeon with it they pulled the trigger and prepare themselves...", false, "", "", 4);
    introStory.enqueue("for war.", false, "", "", 2);
    // If you want to segment or end the story line, just put the introStory.dislayStoryLine(); function
    introStory.dislayStoryLine();
    // then it will dequeue the queue and also diplay and do some logic afterwards
    introStory.enqueue("A couple of months have past since the first attack was launch...", false, "", "", 4);
    introStory.enqueue("The Earth Alliance have been struggling to keep up with Zeon's relentless assault...", false, "", "", 4);
    introStory.enqueue("Especially after the colony drop that hit the Earth Alliance's australia base.", false, "", "", 3);
    introStory.enqueue("With their backs against the wall, The Earth Alliance have resorted to developing new weapon technology...", false, "", "", 4);
    introStory.enqueue("Mobile Suits...", false, "", "", 3);
    introStory.enqueue("Giant Mechs that can match the Zeon's own Mobile Suits in combat...", false, "", "", 4);
    introStory.enqueue("But Zeon on the other hand, has been improving their own Mobile Suits to match against the Earth Aliances infinite amount of resources...", false, "", "", 4);
    introStory.enqueue("The war between both faction has reached a stalemate...", false, "", "", 3);
    introStory.enqueue("Both side suffering heavy losses...", false, "", "", 3);
    introStory.enqueue("And now, it's your time to step up and change the tide of the war...", false, "", "",4);
    introStory.enqueue("Choose which side you want to fight for.", true, "The Earth Alliance", "The Zeon Republic", 1);
    // If you want to make a hasChoice true story line, just put true for hasChoice and importantly displayStoryLine after enqueuing it.
    introStory.dislayStoryLine();
    // And only then you can make the logic for the choices
    while (true){
        if (introStory.choiceResult == 1 || introStory.choiceResult == 2){
            break;
        } else {
            cout << "\nInvalid Choice! Please choose again.\n";
            introStory.enqueue("Choose which side you want to fight for.", true, "The Earth Alliance", "The Zeon Republic", 0);
            introStory.dislayStoryLine();
        }
    }
    if (introStory.choiceResult == 1){
        player.setPlayerSide(true);
        introStory.enqueue("\nYou have chosen to fight for the Earth Alliance.", false, "", "", 3);
    } else {
        player.setPlayerSide(false);
        introStory.enqueue("\nYou have chosen to fight for the Zeon Republic.", false, "", "", 3);
    }
    introStory.enqueue("", false, "", "",2);

    introStory.dislayStoryLine();
}

void main_storyline(suitHangar hangar){ // Placeholder for future main storyline function
    storyQueue mainStory;
    system("clear");
    mainStory.enqueue("'WRRRYYYYYYYY'", false, "", "", 3);
    mainStory.enqueue("Warning sounds blaring from all over the hangar.", false, "", "", 3);
    mainStory.enqueue("'Enemy Sighted!'", false, "", "", 4);
    mainStory.enqueue("'Everyone prepare to launch!', said the operator.", false, "", "", 2);
    mainStory.enqueue("With terrified steps...", false, "", "", 3);
    mainStory.enqueue("You walked wobbly towards your Mobile Suit's cockpit; terrified.", false, "", "", 2);
    mainStory.enqueue("Knowing that once you enter it...", false, "", "", 6);
    mainStory.enqueue("It might as well be a walking coffin.", false, "", "", 3);
    mainStory.enqueue("Taking a deep breath...", false, "", "", 6);
    mainStory.enqueue("You recounted the reason why you even entered this war.", false, "", "", 3);
    mainStory.enqueue("Be it for the sake of someone special or the glory of returning home with victory...", false, "", "", 6);
    mainStory.enqueue("Whatever it is, that's the only thing you can think about in the moment.", false, "", "", 8);
    mainStory.enqueue("You closed your eyes.", false, "", "", 6);
    mainStory.enqueue("'" + hangar.player.name + " get ready!'", false, "", "", 8);
    mainStory.enqueue("Unleashing your breath...", false, "", "", 6);
    mainStory.enqueue("You push your suit's thrusters to the max.", false, "", "", 3);
    mainStory.enqueue("'" + hangar.player.name + " Launch!', you screamed.", false, "", "", 5);
    mainStory.enqueue("With this newfound bravery, you sortied to the battlefield at full force.", false, "", "", 3);
    mainStory.enqueue("SOORRRRRYYYYYYY IT HAS TO END HERE!!!!..... FOR NOW", false, "", "", 6);
    mainStory.enqueue("The Game function hasn't been implemented yet!", false, "", "", 1);

    mainStory.dislayStoryLine();
}

void game_menu (suitHangar hangar, int enterGameOpt){ //Other than the class suitHangar this is also the main fuction of the overall system
    if (enterGameOpt == 1){
        intro(hangar);
    } else if (enterGameOpt == 2){
        cout << "\nSkipping Story...\n";
        sleep_for(seconds(2));
    }
    hangar.chooseSuit();
    
    innerloop:
    while (true){
        system("clear");

        int menuNum;
        int addOption;

        cout << "MAIN MENU\n";
        cout << "-----------------\n";
        cout << "PLAYER STATS"<<"\n";
        cout << "-----------------\n";
        cout << "Suit Name    = " << hangar.player.name;
        cout << "\nSuit Health  = " << hangar.player.health;
        cout << "\nSuit Attack  = " << stats(hangar.player.attackPoints);
        cout << "\nSuit Speed   = " << stats(hangar.player.speedPoints);
        cout << "\nSuit Defence = " << stats(hangar.player.defencePoint);
        cout << "\n-----------------\n";
        cout << "Please Choose an option from any of the ones below.";
        cout << setw(30) << "\n1. SORTIE";
        cout << "2. CHANGE SUIT";
        cout << setw(30) << "\n3. SUIT STORAGE MANAGEMENT";
        cout << "4. EXIT";

        cout << "\n\nEnter your selection: ";
        cin >> ws;
        cin >> menuNum;
        
        if (menuNum == 1){
            main_storyline(hangar);
            goto innerloop;
        } else if (menuNum == 2)
        {
            hangar.chooseSuit();
            goto innerloop;
        } else if (menuNum == 3)
        {
            extramenuloop:
            system("clear");
            cout << setw(30) << "\n1. ADD MORE SUIT";
            cout << "2. DISPLAY SUITS";
            cout << setw(30) << "\n3. SEARCH AVAILABLE SUIT";
            cout << "4. SCRAP A SUIT";
            cout << setw(30) << "\n5. EDIT ENTRY";
            cout << "6. RETURN";
            
            cout << "\n\nEnter your selection: ";
            cin >> menuNum;

            if (menuNum == 1){
                do
                {
                    int inEntNum;
                    string inName;
                    int inAttNum;
                    int inSpeNum;
                    int inDefNum;

                    cout << "\nEnter the Mobile Suits' Entry number: ";
                    cin >> inEntNum;
                    cout << "Enter the Mobile Suits' Name: ";
                    cin >> ws;
                    getline(cin, inName);
                    cout << "Enter the Mobile Suits' Attack points(15 max): ";
                    cin >> inAttNum;
                    cout << "Enter the Mobile Suits' Speed points(15 max): ";
                    cin >> inSpeNum;
                    cout << "Enter the Mobile Suits' Defence points(15 max): ";
                    cin >> inDefNum;

                    hangar.addToStorage(inEntNum,inName,inAttNum,inSpeNum,inDefNum);

                    cout << "\nAdd more record? Press 1 for Yes or 0 for no: ";
                    cin >> addOption;
                } while (addOption == 1);
                
                cout << "\nYour new entry has been added!!";

                cout << "\nPress enter to continue...";
                cin.ignore();
                cin.get();
                goto extramenuloop;
            } else if (menuNum == 2){
                system("clear");
                hangar.displaySuit();
                
                cout << "\nPress enter to continue...";
                cin.ignore();
                cin.get();
                
                goto extramenuloop;
            } else if (menuNum == 3){
                int found;
                do{
                    string searchQueryString;
                    int searchOption;
                    cout << "\nSUIT SEARCHER\n";
                    cout << "-----------------\n";
                    cout << "\n1. Search with Entry Number";
                    cout << "\n2. Search with Name";

                    cout << "\n\nEnter your selection: ";
                    cin >> searchOption;

                    switch (searchOption)
                    {
                    case 1:
                        int searchQuery; 
                        cout << "\nEnter the Entry Number to find: ";
                        cin >> searchQuery;

                        hangar.searchSuitEntry(searchQuery);
                        break;
                    case 2:
                        bool foundAny;
                        cout << "\nEnter a name to find: ";
                        cin >> ws;
                        getline(cin, searchQueryString);

                        hangar.searchSuitName(searchQueryString);
                        break;
                    default:
                        cout << "INVALID NUMBER!!";
                        break;
                    }

                    cout << "\nDid you find the record? Enter 0 to restart search, Enter 1 to continue: ";
                    cin >> found;
                } while (found == 0);

                cout << "\nPress enter to continue...";
                cin.ignore();
                cin.get();

                goto extramenuloop;
            } else if (menuNum == 4){
                hangar.deleteSuit();
                cout << "\nThe Entry Has Been Scrapped!!";
                cout << "\nPress enter to continue...";
                cin.ignore();
                cin.get();
                goto extramenuloop;
            } else if (menuNum == 5){
                int toEdit;
                int inEntNum;
                string inName;
                int inAttNum;
                int inSpeNum;
                int inDefNum;
                hangar.displaySuit();
                cout << "\nPlease Enter the Entry Number you want to edit: ";
                cin >> toEdit;

                cout << "Enter the new Mobile Suits' Name for Entry Number "<< toEdit << ": ";
                cin >> ws;
                getline(cin, inName);
                cout << "Enter the Mobile Suits' Attack points for Entry Number "<< toEdit << "(15 max): ";
                cin >> inAttNum;
                cout << "Enter the Mobile Suits' Speed points for Entry Number "<< toEdit << "(15 max): ";
                cin >> inSpeNum;
                cout << "Enter the Mobile Suits' Defence points for Entry Number "<< toEdit << "(15 max): ";
                cin >> inDefNum;

                hangar.modifySuit(toEdit,inName,inAttNum,inSpeNum,inDefNum);

                cout << "\nPress enter to continue...";
                cin.ignore();
                cin.get();

                goto extramenuloop;
            } else if (menuNum == 6){
                goto innerloop;
            } else {
                cout << "\nInvalid Option";

                cout << "\nPress enter to continue...";
                cin.ignore();
                cin.get();

                goto extramenuloop;
            }
            goto innerloop;
        } else if (menuNum == 4)
        {
            system("clear");
            cout << "\nSee ya again! We still need your help to win the war...\n";
            
            cout << "\nPress enter to continue...";
            cin.ignore();
            cin.get();
            system("clear");
            break;
        } else{
            cout << "\nInvalid Option";

            cout << "\nPress enter to continue...";
            cin.ignore();
            cin.get();

            goto innerloop;
        }
    }
}

int main (){ // Kinda obvious without this. You can't run anything
    // system("gnome-terminal &");
    suitHangar hangar;
    int playTheGame;

    hangar.addToStorage(10, "GMass Unit Type Heavy Weapons", 8,3,8);
    hangar.addToStorage(20, "GMass Unit Type High Mobility", 5,9,3);
    hangar.addToStorage(30, "GMass Unit Type Full Armor", 4,2,10); // Predefine list to ease the debugging process and also a game feature
    while (true){
        cout << "\nWELCOME TO MECH WARS\n";
        cout << "\nEnter 1 to Play\n";
        // cout << "Enter 2 to Skip the story\n";
        cout << "Enter 0 to Exit\n";
        cout << "\nChoice: ";
        cin >> playTheGame;

        if (playTheGame == 1){
            game_menu(hangar, 1);
        } else if (playTheGame == 2){
            game_menu(hangar, 2);
        } else return 0;
    }
    
}