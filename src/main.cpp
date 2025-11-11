#include <iostream>
#include <iomanip>
#include <istream>
#include <string>
#include <string.h>
#include <limits>
#include <thread>
#include <chrono> //Don't wanna mess with any of these, they're required for the code to even remotely function
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/color.hpp>

using namespace std;//So that i won't need to std over and over again
using namespace this_thread; //Apparently this is apart of a function that let me do delays
using namespace chrono; //This part is the how many seconds/minutes to wait
using namespace ftxui;

struct suitStorageBase //This is the data for storage system that will let the player the ability to choose,edit,scrap and etc
{
    int entryNum;
    string name;
    int attackPoints;
    int speedPoints;
    int defencePoint;
    suitStorageBase *next;

    suitStorageBase(int entNum, string name, int att, int spe, int def){//Constructor to ease data inputting
        this->entryNum = entNum;
        this->name = name;
        this->attackPoints = att;
        this->speedPoints = spe;
        this->defencePoint = def;
        this->next = NULL;
    }
};

struct playerSuit // This is the data for the players current suit
{
    int entryNum;
    string name;
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

    playerSuit(int entNum, string name, int att, int spe, int def, int hp){
        this->entryNum = entNum;
        this->name = name;
        this->health = hp;
        this->attackPoints = att;
        this->speedPoints = spe;
        this->defencePoint = def;
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

class suitHangar{ // This is the main bread and butter of this Systems function. This is where the player can add, edit, remove or etc for the Suits
    suitStorageBase *first, *last; //declare pointer
    suitStorageBase *newptr;
    suitStorageBase *current;
    suitStorageBase *previous;
    suitStorageBase *delptr;

    public:
        suitHangar(){
            first = nullptr;
            last = nullptr;
        }
        playerSuit player;

        void addToStorage(int entNum, string name, int att, int spe, int def){
            newptr = new suitStorageBase(entNum, name, att, spe, def);
            
            if (first == NULL){
                first = newptr;
                last = newptr;
            }else{
                if(first == last){
                    if(newptr->entryNum == first->entryNum){
                        newptr = NULL;
                        cout << "\nEntry Number already registered. The newest data have been purged!\n";
                    }else if(newptr->entryNum < first->entryNum){
                        //add new node at the front
                        newptr->next = first;
                        first = newptr;
                    }else{
                        //add new node at the rear
                        last->next = newptr;
                        last = newptr;
                    }
                }else{
                    if (newptr->entryNum < first->entryNum){
                        newptr->next = first;
                        first = newptr;
                    }else if (newptr->entryNum > last->entryNum){
                        last->next = newptr;
                        last = newptr;
                    }else{
                        previous = NULL;
                        current = first;
                        while (current != NULL)
                        {
                            if (newptr->entryNum == current->entryNum){
                                newptr = NULL;
                                cout << "\nEntry Number already registered. The newest data have been purged!\n";
                                break;
                            }else if (newptr->entryNum > current->entryNum){
                                previous = current;
                                current = current->next;
                            }else{
                                previous->next = newptr;
                                newptr->next = current;
                                break;  
                            }
                        }

                    }
                }
            }
        }

        void displaySuit(){
            cout << left << setw(16) << "\nEntry Number" << setw(56) << "Mobile Suit Name" << setw(23) << "Suit Attack LVL" << setw(20) << "Suit Speed LVL" << setw(20) << "Suit Defense LVL" << endl;
            cout << left << setfill('-') << setw(135) << "" << endl;
            current = first;
            while (current != NULL)
            {
                cout << setfill(' ') << left << setw(16) <<current->entryNum;
                cout << left << setw(56) << current->name;
                cout << setw(23)<<stats(current->attackPoints);
                cout << setw(20)<<stats(current->speedPoints);
                cout << setw(20)<<stats(current->defencePoint);

                cout << "\n";

                current = current->next;
            }
        }
        
        void searchSuitEntry(int searchQuery){
            int found;
            cout << left << setw(16) << "\nEntry Number" << setw(56) << "Mobile Suit Name" << setw(23) << "Suit Attack LVL" << setw(20) << "Suit Speed LVL" << setw(20) << "Suit Defense LVL" << endl;
            cout << left << setfill('-') << setw(135) << "" << endl;
            current = first;
            while (current != NULL)
            {
                if (current->entryNum == searchQuery){
                    cout << setfill(' ') << left << setw(16) <<current->entryNum;
                    cout << left << setw(56) << current->name;
                    cout << setw(23)<<stats(current->attackPoints);
                    cout << setw(20)<<stats(current->speedPoints);
                    cout << setw(20)<<stats(current->defencePoint);

                    found = 1;
                    cout << "\n";
                    break;
                } else{
                    current = current->next;
                }

                if (found == 0){
                    cout << "No Data!";
                    break;
                }
                found = 0;
            }
        }

        void searchSuitName(string searchName){
            int found;
            cout << left << setw(16) << "\nEntry Number" << setw(56) << "Mobile Suit Name" << setw(23) << "Suit Attack LVL" << setw(20) << "Suit Speed LVL" << setw(20) << "Suit Defense LVL" << endl;
            cout << left << setfill('-') << setw(135) << "" << endl;
            current = first;
            while (current != NULL)
            {   
                string findingData = current->name;
                if(findingData.find(searchName) != string::npos)
                {
                    cout << setfill(' ') << left << setw(16) <<current->entryNum;
                    cout << left << setw(56) << current->name;
                    cout << setw(23)<<stats(current->attackPoints);
                    cout << setw(20)<<stats(current->speedPoints);
                    cout << setw(20)<<stats(current->defencePoint);
                    
                    cout << "\n";
                    found = 1;
                } 

                current = current->next;
                
            }

            if (found == 0){
                cout << "No Data!";
            }
            found = 0;
        }

        void deleteSuit(){
            current = first;
            previous = NULL;
            delptr = NULL;
            
            int delNum;

            cout << "\nPlease enter an Entry Number to delete: ";
            cin >> delNum;
            
            while (current != NULL){
                if (current->entryNum == delNum){
                    //check if the list in front or back or middle
                    if (current == first){//
                        delptr = first;
                        if (first->next != NULL){
                            first = first->next;
                            delete delptr;
                        }else{
                            first = NULL;
                            last = NULL;
                        }
                    } else if (current == last)
                    {
                        delptr = current;

                        if (first->next = NULL){
                            first = NULL;
                            last = NULL;
                            delete delptr;
                        }else{
                            previous = first;
                            while (previous->next != last)
                            {
                                previous = previous->next;
                            }
                            last = previous;
                            previous->next = NULL;
                            delete delptr;
                        }
                        
                    } else{
                        delptr = current;
                        previous = first;
                        while (previous->next != current)
                        {
                            previous = previous->next;
                        }
                        previous->next = current->next;
                        delete delptr;
                        
                    }
                    
                }

                current = current->next;
            }
        }

        void modifySuit(int suitNum, string name, int att, int spe, int def){
            int foundToEdit;
            current = first;
            while (current != NULL)
            {
                if (current->entryNum == suitNum){
                    current->name = name;
                    current->attackPoints = att;
                    current->speedPoints = spe;
                    current->defencePoint = def;

                    foundToEdit = 1;
                    cout << "\nThe entry data has been modified!";
                    cout << "\n";
                    break;
                }
                
                current = current->next;
            }


            if (foundToEdit == 0){
                cout << "\nNo Data!";
            }
            foundToEdit = 0;
        }

        void chooseSuit(){
            incorrectsuitloop:
            int choice;
            bool found;
            displaySuit();
            
            cout << "\nChoose which suit you want to use!\n";
            cout << "Please enter its' Entry Number: ";
            cin >> choice;

            cout << "\nPlease wait while we're preparing the Mobile Suit";

            current = first;
            while (current != NULL)
            {
                if(current->entryNum == choice)
                {
                    player = playerSuit(current->entryNum, current->name, current->attackPoints, current->speedPoints, current->defencePoint, hpInit(current->defencePoint));
                    found = true;
                    break;
                }else{
                    current = current->next;
                }
            }

            if (!found){
                cout << "\nEntry Number is not Found!\n";

                cout << "\nPress enter to continue...";
                cin.ignore();
                cin.get();

                goto incorrectsuitloop;
            }

            cout << "\n\nThank you for waiting. Your suit is ready to be boarded!";
            sleep_for(seconds(2));
            cout << "\nPress enter to continue...";
            cin.ignore();
            cin.get();
        }

};

void intro(){ // This is a function that was put in just for fun
    system("clear");

    cout << "\nIn the year 0025...";
    cout << "\nHumanity has moved its burgening population to space...";
    sleep_for(seconds(2));
    cout << "\nCreating a massive divide between people of space and those who still inhabit the earth.";
    sleep_for(seconds(3));
    cout << "\nConflict Arises between both faction...";
    sleep_for(seconds(4));
    cout << "\nAs days passed by... the tension kept rising and rising...";
    sleep_for(seconds(3));
    cout << "\nUntil eventually...";
    sleep_for(seconds(4));
    cout << "\nA colony sector within site 7, annouced an independance from the Earth Alliance.";
    sleep_for(seconds(2));
    cout << "\nCalling themselves as the Principality of Zeon with it they pulled the trigger and prepare themselves...";
    sleep_for(seconds(6));
    cout << "\nfor war.\n";
    sleep_for(seconds(6));

    cout << "\nPress enter to continue...";
    cin.ignore();
    cin.get();

    system("clear");
}

void game (suitHangar hangar){ //Other than the class suitHangar this is also the main fuction of the overall system
    innerloop:
    while (true){
        system("clear");

        int menuNum;
        int addOption;

        cout << "MAIN MENU\n";
        cout << "-----------------\n";
        cout << "PLAYER STATS\n";
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
        cin >> menuNum;
        
        if (menuNum == 1){
            system("clear");
            cout << "\n'WRRRYYYYYYYY'";
            cout << "\nWarning sounds blarring from all over the hangar.";
            sleep_for(seconds(3));
            cout << "\n'Enemy Sighted!'";
            sleep_for(seconds(4));
            cout << "\n'Everyone prepare to launch!', said the operator.";
            sleep_for(seconds(2));
            cout << "\nWith terrified steps...";
            sleep_for(seconds(3));
            cout << "\nYou walked wobbly towards your Mobile Suits cockpit; terrified.";
            sleep_for(seconds(2));
            cout << "\nKnowing that once you enter it...";
            sleep_for(seconds(6));
            cout << "\nIt might as well be a walking coffin.";
            sleep_for(seconds(3));
            cout << "\nTaking a deep breath...";
            sleep_for(seconds(6));
            cout << "\nYou recounted the reason why you even entered this war.";
            sleep_for(seconds(3));
            cout << "\nBe it for the sake of someone special or the glory of returning home with victory...";
            sleep_for(seconds(6));
            cout << "\nWhatever it is, That's the only thing you can think about in the moment.";
            sleep_for(seconds(8));
            cout << "\nYou closed your eyes.";
            sleep_for(seconds(6));

            cout << "\n\n'" << hangar.player.name << " get ready!'";
            sleep_for(seconds(8));
            cout << "\nUnleashing your breath...";
            sleep_for(seconds(6));
            cout << "\nYou push your suits' thrusters to the max.";
            sleep_for(seconds(3));
            cout << "\n'" << hangar.player.name << " Launch!', you screamed.";
            sleep_for(seconds(5));
            cout << "\nWith this new found bravery you sortied to battlefield at full force.";
            sleep_for(seconds(3));

            cout << "\n\nSOORRRRRYYYYYYY IT HAS TO END HERE!!!!..... FOR NOW";
            sleep_for(seconds(8));
            cout << "\nThe Game function hasn't been implemented yet!\n";

            cout << "\nPress enter to continue...";
            cin.ignore();
            cin.get();
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
                    cout << "\nSUIT SEACHER\n";
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
    auto screen = ScreenInteractive::Fullscreen();
    suitHangar hangar;
    int playTheGame;

    hangar.addToStorage(10, "GMass Unit Type Heavy Weapons", 8,3,8);
    hangar.addToStorage(20, "GMass Unit Type High Mobility", 5,9,3);
    hangar.addToStorage(30, "GMass Unit Type Full Armor", 4,2,10); // Predefine list to ease the debugging process and also a game feature
    while (true){
        auto renderer = Renderer([&] {
            Elements lines = {
                text("Welccome to Mecha Wars!") | bold | center,
                separator(),
                text("\n\n\nPress Enter to Play"),
                separator(),
                text("Press Q to Exit"),
            };

            return vbox(lines) | border | size(WIDTH, GREATER_THAN, 50) |
                center | bgcolor(Color::Black);
        });

        auto main_component = CatchEvent(renderer, [&](Event event) {
            if (event == Event::Character('q') || event == Event::Character('Q')) {
                screen.ExitLoopClosure()();
                return true;
            }

            if (event == Event::Character('2')) {
                hangar.chooseSuit();
                game(hangar);
            }

            if (event == Event::Return){
                intro();
                hangar.chooseSuit();
                game(hangar);
            }

            return true;
        });

        screen.Loop(main_component);
        return 0;
        // cout << "\nWELCOME TO MECH WARS\n";
        // cout << "\nEnter 1 to Play\n";
        // // cout << "Enter 2 to Skip the story\n";
        // cout << "Enter 0 to Exit\n";
        // cout << "\nChoice: ";
        // cin >> playTheGame;

        // if (playTheGame == 1){
        //     intro();
        //     hangar.chooseSuit();
        //     game(hangar);
        // } else if (playTheGame == 2){
        //     hangar.chooseSuit();
        //     game(hangar);
        // } else return 0;
    }
    
}