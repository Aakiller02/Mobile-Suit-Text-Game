#include <iostream>
#include <iomanip>
#include <istream>
#include <string>
#include <string.h>
#include <limits>

using namespace std;

struct suitStorageBase
{
    int entryNum;
    string name;
    int attackPoints;
    int speedPoints;
    int defencePoint;
    suitStorageBase *next;

    suitStorageBase(int entNum, string name, int att, int spe, int def){
        this->entryNum = entNum;
        this->name = name;
        this->attackPoints = att;
        this->speedPoints = spe;
        this->defencePoint = def;
        this->next = NULL;
    }
};

struct suitHangar
{
    int entryNum;
    string name;
    int attackPoints;
    int speedPoints;
    int defencePoint;
    suitHangar *next;

    suitHangar(int entNum, string name, int att, int spe, int def){
        this->entryNum = entNum;
        this->name = name;
        this->attackPoints = att;
        this->speedPoints = spe;
        this->defencePoint = def;
        this->next = NULL;
    }
};

class mobileSuit{
    suitStorageBase *first, *last; //declare pointer
    suitStorageBase *newptr;
    suitStorageBase *current;
    suitStorageBase *previous;
    suitStorageBase *delptr;

    suitHangar *SHfirst, *SHlast; //declare pointer
    suitHangar *SHnewptr;
    suitHangar *SHcurrent;
    suitHangar *SHprevious;
    suitHangar *SHdelptr;

    int suitinhangarCount;

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

    void addToHangar(int searchQuery){
        
        current = first;
        int found;

        while (current != NULL)
        {
            if(current->entryNum == searchQuery)
            {
                SHnewptr = new suitHangar(current->entryNum, current->name, current->attackPoints, current->speedPoints, current->defencePoint);

                found = 1;
                break;
            }else{
                current = current->next;
            }
        }
        
        if (found == 1 && suitinhangarCount < 3){
            suitinhangarCount++;
            
            if (SHfirst == NULL){
                SHfirst = SHnewptr;
                SHlast = SHnewptr;
            }else{
                if(SHfirst == SHlast){
                    if(SHnewptr->entryNum == SHfirst->entryNum){
                        SHnewptr = NULL;
                        cout << "\nEntry Number already registered. The newest data have been purged!\n";
                    }else if(SHnewptr->entryNum < SHfirst->entryNum){
                        //add new node at the front
                        SHnewptr->next = SHfirst;
                        SHfirst = SHnewptr;
                    }else{
                        //add new node at the rear
                        SHlast->next = SHnewptr;
                        SHlast = SHnewptr;
                    }
                }else{
                    if (SHnewptr->entryNum < SHfirst->entryNum){
                        SHnewptr->next = SHfirst;
                        SHfirst = SHnewptr;
                    }else if (SHnewptr->entryNum > SHlast->entryNum){
                        SHlast->next = SHnewptr;
                        SHlast = SHnewptr;
                    }else{
                        SHprevious = NULL;
                        SHcurrent = SHfirst;
                        while (SHcurrent != NULL)
                        {
                            if (SHnewptr->entryNum == SHcurrent->entryNum){
                                SHnewptr = NULL;
                                cout << "\nEntry Number already registered. The newest data have been purged!\n";
                                break;
                            }else if (SHnewptr->entryNum > SHcurrent->entryNum){
                                SHprevious = SHcurrent;
                                SHcurrent = SHcurrent->next;
                            }else{
                                SHprevious->next = SHnewptr;
                                SHnewptr->next = SHcurrent;
                                break;  
                            }
                        }

                    }
                }
            }
        } else cout << "No Data and the hangar is FULL!";
    }
};

int main (){

}

