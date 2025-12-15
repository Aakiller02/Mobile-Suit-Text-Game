#include <iostream>
#include <iomanip>
#include <istream>
#include <thread>
#include <chrono>
#include "playerSuit.h"
#include "suitStorageBase.h"
#include "playerData.h"

struct suitHangar{ // This is the main bread and butter of this Systems function. This is where the player can add, edit, remove or etc for the Suits
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
        playerData playersData;

        std::string stats(int stat){ // This function returns string for the stats number...Basically converts the points to understandable level of sort
            if (stat < 5){
                return "Low";
            } else if (stat < 10 && stat > 4){
                return "Medium";
            } else if (stat < 15 && stat > 9){
                return "High";
            } else return 0;
        }

        void setPlayerSide(bool side){
            if (side = true){
                playersData.playerSide = true;
            } else {
                playersData.playerSide = false;
            }
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

        void addToStorage(int entNum, std::string name, int att, int spe, int def){
            newptr = new suitStorageBase(entNum, name, att, spe, def);
            
            if (first == NULL){
                first = newptr;
                last = newptr;
            }else{
                if(first == last){
                    if(newptr->entryNum == first->entryNum){
                        newptr = NULL;
                        std::cout << "\nEntry Number already registered. The newest data have been purged!\n";
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
                                std::cout << "\nEntry Number already registered. The newest data have been purged!\n";
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
            std::cout << std::left << std::setw(16) << "\nEntry Number" << std::setw(56) << "Mobile Suit Name" << std::setw(23) << "Suit Attack LVL" << std::setw(20) << "Suit Speed LVL" << std::setw(20) << "Suit Defense LVL" << std::endl;
            std::cout << std::left << std::setfill('-') << std::setw(135) << "" << std::endl;
            current = first;
            while (current != NULL)
            {
                std::cout << std::setfill(' ') << std::left << std::setw(16) <<current->entryNum;
                std::cout << std::left << std::setw(56) << current->name;
                std::cout << std::setw(23)<<stats(current->attackPoints);
                std::cout << std::setw(20)<<stats(current->speedPoints);
                std::cout << std::setw(20)<<stats(current->defencePoint);

                std::cout << "\n";

                current = current->next;
            }
        }
        
        void searchSuitEntry(int searchQuery){
            int found;
            std::cout << std::left << std::setw(16) << "\nEntry Number" << std::setw(56) << "Mobile Suit Name" << std::setw(23) << "Suit Attack LVL" << std::setw(20) << "Suit Speed LVL" << std::setw(20) << "Suit Defense LVL" << std::endl;
            std::cout << std::left << std::setfill('-') << std::setw(135) << "" << std::endl;
            current = first;
            while (current != NULL)
            {
                if (current->entryNum = searchQuery){
                    std::cout << std::setfill(' ') << std::left << std::setw(16) <<current->entryNum;
                    std::cout << std::left << std::setw(56) << current->name;
                    std::cout << std::setw(23)<<stats(current->attackPoints);
                    std::cout << std::setw(20)<<stats(current->speedPoints);
                    std::cout << std::setw(20)<<stats(current->defencePoint);

                    found = 1;
                    std::cout << "\n";
                    break;
                } 
                current = current->next;

                if (found == 0){
                    std::cout << std::setfill(' ') << "No Data!";
                    break;
                }
                found = 0;
            }
        }

        void searchSuitName(std::string searchName){
            int found;
            std::cout << std::left << std::setw(16) << "\nEntry Number" << std::setw(56) << "Mobile Suit Name" << std::setw(23) << "Suit Attack LVL" << std::setw(20) << "Suit Speed LVL" << std::setw(20) << "Suit Defense LVL" << std::endl;
            std::cout << std::left << std::setfill('-') << std::setw(135) << "" << std::endl;
            current = first;
            while (current != NULL)
            {   
                std::string findingData = current->name;
                if(findingData.find(searchName) != std::string::npos)
                {
                    std::cout << std::setfill(' ') << std::left << std::setw(16) <<current->entryNum;
                    std::cout << std::left << std::setw(56) << current->name;
                    std::cout << std::setw(23)<<stats(current->attackPoints);
                    std::cout << std::setw(20)<<stats(current->speedPoints);
                    std::cout << std::setw(20)<<stats(current->defencePoint);
                    
                    std::cout << "\n";
                    found = 1;
                } 

                current = current->next;
                
            }

            if (found == 0){
                std::cout << "No Data!";
            }
            found = 0;
        }

        void deleteSuit(){
            current = first;
            previous = NULL;
            delptr = NULL;
            
            int delNum;

            std::cout << "\nPlease enter an Entry Number to delete: ";
            std::cin >> delNum;
            
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

        void modifySuit(int suitNum, std::string name, int att, int spe, int def){
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
                    std::cout << "\nThe entry data has been modified!";
                    std::cout << "\n";
                    break;
                }
                
                current = current->next;
            }


            if (foundToEdit == 0){
                std::cout << "\nNo Data!";
            }
            foundToEdit = 0;
        }

        void chooseSuit(){
            incorrectsuitloop:
            int choice;
            bool found;
            displaySuit();
            
            std::cout << "\nChoose which suit you want to use!\n";
            std::cout << "Please enter its' Entry Number: ";
            std::cin >> choice;

            std::cout << "\nPlease wait while we're preparing the Mobile Suit";

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
                std::cout << "\nEntry Number is not Found!\n";

                std::cout << "\nPress enter to continue...";
                std::cin.ignore();
                std::cin.get();

                goto incorrectsuitloop;
            }

            std::cout << "\n\nThank you for waiting. Your suit is ready to be boarded!";
            std::this_thread::sleep_for(std::chrono::seconds(2));
            std::cout << "\nPress enter to continue...";
            std::cin.ignore();
            std::cin.get();
        }

};