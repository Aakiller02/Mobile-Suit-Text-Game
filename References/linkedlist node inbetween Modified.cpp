#include <iostream>
#include <iomanip>
#include <istream>
#include <string>
#include <string.h>
#include <limits>

using namespace std;

struct kit
{
    int entryNum;
    string name;
    char type[20];
    int release_year;
    bool is_Favourite;
    kit *next;
};

void IntroGundam(){
    cout << R"(⢀⣀⡀                                  ⡠⠤⠤⠤⠤⠠⠤⠄⠤⠠⠄⠤⡀                                  ⢀⣀
⠘⢇⠊⢕⡢⢄⡀                             ⠊⢀ ⠠⠤⠤⠤⠤⠤⠤⠤ ⢀⠈⢢                             ⣀⠤⢒⠮⢋⠝
  ⠑⠢⡈⠐⠠⡑⠂⢄⡀                        ⠐ ⠈ ⣀⣀⣀⣀⣀⣀⣀⣀⡀  ⢸                         ⣀⠤⠒⡩⠔⠊⡠⠔⠁ 
    ⠈⠐⢄ ⠁⠢⢀⠁⠂⠄⡀                    ⠰   ⣿⣟⣿⣻⣟⣿⣻⢿⡇  ⢸                     ⣀⠤⠒⢉⠠ ⠁⢀⠴⠊    
       ⠙⠢⡀ ⠈⠐ ⡀⠁⠂⢄⡀                ⠨   ⢿⣞⣷⢿⣞⣷⢿⣻⡇  ⢸                 ⣀⠤⠒⠉⡀⠔⠂  ⣠⠔⠁      
         ⠈⠲⢄   ⠁⠢⢄ ⠑⠂⠄⡀         ⢀⡀⠤⠚⠆⡇ ⣻⣟⣾⢯⣿⢾⣻⣯⡇ ⡀⠞⠢⠄⣀          ⣀⠤⠒⠉⢀⠠⠐⠁  ⢀⡠⠊         
           ⠈⠢⣀   ⠈⠐⠠⡀ ⠑⠂⠄⡀    ⢀⠄⠊⠁   ⡇ ⢻⣽⣟⣾⣽⡾⣿⣽⡇ ⡇⢰  ⠉⠒⠄⡀    ⣀⠤⠒⠉ ⡀⠔⠊    ⡠⠚⠁          
             ⠈⠑⢄⡀    ⠁⠠⢀ ⠈⠁⠢⢤⠊     ⢸ ⡇ ⠼⠿⠞⠿⠾⠽⠷⢯⠇ ⡃⢸     ⠈⢒⠤⠒⠉ ⢀⠠ ⠁    ⢀⠔⠈             
                ⠉⠢⡀     ⠈⠐⠄⡀ ⠈⠐⠠⢀  ⠘⢄⠑ ⣀⣀⣀⣀⣀⣀⣀⣀⡀⡠⠃⠜   ⡀⠐⠈  ⡀⠔⠊⠁     ⡠⠐⠁               
                  ⠈⠑⢄       ⠑⠢⢀  ⠈⠂⠄⡀⠁⢀⣿⣟⣿⣻⣟⣿⣻⢿⡏⢠ ⡀⠄⠂⠁ ⢀⠠⠐⠁      ⢀⠤⠊                  
                     ⠑⠢⡀       ⠈⠐⠄⡀  ⢹⢸⡿⣞⣷⣟⡾⣷⣻⣯⣿⢸⠁  ⡀⠄⠊⠁       ⡠⠖⠁                    
                      ⠰⠋⠐⢄         ⠑⠠⢸⣾⡽⣟⣷⣯⢿⣯⣷⢯⣟⣿⠠⠐⠉        ⢀⠔⠊⠱⡀                     
                     ⢠⠃⢀⡴⠶⠷⢤⡀        ⣼⣿⣻⣟⣾⡽⣟⣾⣽⣻⢯⣿⡄        ⣠⣴⠿⠶⣄ ⢳                     
                  ⢀⠤⠒⠹ ⡞⢡⣾⣿⣦⢩⠐⢄     ⢠⣸⣟⣷⢯⡿⣽⢿⣽⢾⣻⣯⢿⣼      ⠠⢺⡻⣿⣿⣦⠘⡇⠸⠉⠂⢄⡀                 
                ⡠⠊   ⡆ ⢳⣄⠛⠛⣃⡎  ⡁⠤⡀  ⣾⡿⣿⣾⣟⡿⣯⣿⢾⡿⣽⣾⡿⣟⡆  ⢀⠔⡁ ⠈⢧⡙⠛⢋⣰⠇ ⡆  ⠈⠢⡀               
               ⣸⠁⠒⠒ ⠤⡇  ⠙⠛⠛⡉⠄⠂⠁  ⠈⠠⢠⣿⣽⢷⣻⢿⣻⣷⣯⣿⡿⣟⣷⢿⣻⣿⠠⠊   ⠁⠂⠄⡙⠛⠛⠁  ⡧⠄⠐⠒ ⢸⡄              
              ⢠⢹ ⣀⣀⣀ ⡇  ⢀⠔⠉        ⢸⣿⢾⣻⣯⢿⣯⢿⣽⢯⣟⣿⢾⣻⣷⣻⡄        ⠑⠠⡀  ⡇⢀⣀⣀⡀⠘⢱              
              ⡌⡌ ⣿⣿⣿ ⡇⠠⣊            ⠙⠻⣽⡾⣿⣽⣻⡾⣟⡿⣾⣻⡿⠞⠁           ⠈⡢ ⡇⢸⣿⣿⡇ ⡆⡆             
             ⢠⠁⠃ ⣿⣿⣿⠄⡇  ⠈ ⣶⣤⣄⣀⡀        ⠙⠷⣯⣷⢿⣻⣽⠗⠉        ⣀⣀⣤⣴⡆⠈⠁  ⡇⢸⣿⣿⡇ ⡇⢰             
             ⠘⠠  ⣤⣤⣤ ⡇    ⣿⣿⣿⣿⣿⡏⠁⠒⠂⠠⠤⢀⢀  ⠈⠙⠟⠋   ⣀⠠⠤ ⠒⠂⠉⣻⣿⣿⣿⣿⡇    ⡇⢠⣤⣤⡄ ⢠⠘⡄            
             ⡇⢰  ⣿⣿⣿ ⣇    ⣿⣯⡿⣿⣿⣧       ⢸⣿⣶⣶⣶⣶⣾⣿⠁      ⢠⣿⣿⣿⣿⣿⡇    ⡇⢸⣿⣿⡇ ⠰ ⡇            
            ⢀⡇⠘  ⠿⠿⠿ ⡏⢆   ⠑⠜⢿⣷⣻⢿⣿⣦⣄⣀⣤⣤⣴⣿⣿⣿⣿⣿⣿⣿⣿⣷⣤⣤⣄⣀⣤⣶⣿⣿⣻⣿⠟⡁⠁   ⠌⡇⠘⠿⠿⠇   ⠁            
            ⢸⠃⡀  ⣶⣶⣶ ⡇ ⢂   ⠈⢀⠙⢿⣯⣟⣿⣻⣟⣿⢿⣿⣿⡿⠿⠛⠉⠛⠿⣿⣿⡿⣿⢿⣻⣟⣿⣽⣾⠟⢁⠎    ⠌ ⡇⢰⣶⣶⡆  ⡇⢰            
            ⢸ ⡇  ⣿⣿⣿ ⡇  ⢂    ⣡ ⡏⠉⠉⠉⠉⠉⠛⠋⠁⢀⣠⣴⣶⣤⣀ ⠉⠛⠉⠉⠉⠉⠉⠉⡏⢠⡂   ⢀⠎  ⡇⢸⣿⣿⡇  ⡇⢸            
            ⠸⡅⡇  ⠛⠛⠛ ⡇   ⡖ ⠉   ⡇        ⠈⠋⣉⣦⡈⠉         ⠃⡆  ⠉⠐⡆   ⡃⠈⠛⠛⣃  ⡇⢸            
            ⢀⡇⡇  ⣿⣿⣿ ⡇   ⡇    ⠆⢰        ⠈⠟⠋⠉⠙⠟        ⢰ ⡇    ⡇   ⡇⢠⣿⣿⡇  ⡇⠈            
             ⡇⡇  ⣿⣿⣿ ⡇   ⡇    ⠆⠘          ⣠⣦⣀         ⢸ ⡇    ⡇   ⠂⠸⣿⣿⡇  ⡇⡇            
            ⠁⢇⡃  ⣉⣉⡉     ⡇    ⡇ ⡆      ⢠⣶⣿⡿⣿⢿⣷⣦⡀      ⡌ ⡇    ⡇   ⠅⠈⣉⣉⡉  ⣇⠇            
             ⢸⣇  ⣿⣿⣿ ⡇   ⡇    ⡷⡀⠘⡄     ⣾⣟⣾⡽⣟⡿⣾⣽⡇     ⠐ ⡰⡇    ⡇   ⡂⢸⣿⣿⡇  ⡽             
             ⠈⢿  ⣿⣿⣿ ⠃   ⡇    ⡿⠈⡄⠱⡀    ⣿⣻⣞⣿⣻⣽⣷⣻⡇    ⠠⠁⡐ ⡇    ⡇   ⡅⢸⣿⣿⡇ ⢠⡇             
              ⠸⡄ ⠛⠛⠻ ⠂   ⡇    ⡗ ⠑⡀⢣    ⣿⣟⡿⣽⣻⢯⣟⡿⡇   ⢀⠂⡰⠁⢰⡇    ⡇   ⡅⠘⠛⠛⠓ ⣸⠁             
               ⠉⠉⠉⠉ ⠐⡇   ⡇    ⣇⠦⠤⠈⢄⠣   ⣿⣯⣿⣻⣽⣟⣯⣿⡇  ⢀⢂⡔ ⠤⢮⡇    ⡇   ⡗⠂⠉⠉⠉⠉⠁              
                     ⢳ ⣀⠤⠓⠒⠒⠂ ⠃   ⠈⠑⠵⣀⢀⣿⣻⣽⢿⣻⣟⣯⡿⣇ ⣠⠅⠊    ⠉⠐⠒⠒⠒⠣⠄⣀⢠⠃                    
                      ⠁                ⢻⣯⣟⣯⡿⣞⣯⣿⡇                ⠁                     
                                       ⠸⠿⢾⢯⡟⡿⣳⠿⠁)";
}

int main()
{
    kit *first, *last; //declare pointer
    kit *newptr;
    kit *current;
    kit *previous;
    kit *delptr;

    string searchQueryChar;
    string isFav;
    int menuNum=0;

    //1. create list
    first = NULL;
    last  = NULL;
    int addOption=0;

    while (true)
    {
        IntroGundam();
        cout << "\nWelcome to your own Gundam database!!";
        cout << "\nPlease choose an option 1-3";
        cout << "\n1. Enter a model into the database ";
        cout << "\n2. Display MS kits Data";
        cout << "\n3. Search Entered Data function";
        cout << "\n4. Delete a Models' Data Entry";
        cout << "\n5. Exit";

        cout << "\n\nEnter your selection: ";
        cin >> menuNum;

        if (menuNum == 1){
            do
            {
                //2. create new node
                newptr = new kit;

                //get data and store into new node 
                cout << "\nEnter the Kits' Entry number: ";
                cin >> newptr->entryNum;

                cout << "Enter the Kits' Name: ";
                cin >> ws;
                getline(cin, newptr->name);

                cout << "Enter The Kits' Type: ";
                cin >> ws;
                cin.getline(newptr->type, sizeof(newptr->type));

                cout << "Enter the Kits' release year: ";
                cin >> newptr->release_year;

                cout << "Is the kit your favourite kit (Yes or No): ";
                cin >> isFav;

                if (isFav == "Yes"){
                    newptr->is_Favourite = true;
                } else if (isFav == "No")
                {
                    newptr->is_Favourite = false;
                }

                // newptr = first =  NULL;
                // newptr->next = NULL;

                //3. insert new node operation
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

                cout << "\nAdd more record? Press 1 for Yes or 0 for no: ";
                cin >> addOption;
            } while (addOption == 1);

            cout << "\nYour new entry has been added!!";

            cout << "\nPress enter to continue...";
            cin.ignore();
            cin.get();
        } else if (menuNum == 2)
        {
            //4. Traversal - to print the content of each node

            cout <<"\nEntry Number    Kit Name                                                Kit Model            Release Year      Is Favourite?\n";
            cout <<"------------------------------------------------------------------------------------------------------------------------------\n";
            current = first;
            while (current != NULL)
            {
                cout << left << setw(16) <<current->entryNum;
                cout << left << setw(56) << current->name;
                cout << setw(23)<<current->type;
                cout << setw(20)<<current->release_year;

                if (current->is_Favourite){
                    cout << setw(10)<<"Yes";
                } else if (!current->is_Favourite)
                {
                    cout << setw(10)<<"No";
                }
                
                cout << "\n";

                current = current->next;
            }
            cout << "\nPress enter to continue...";
            cin.ignore();
            cin.get();
        } else if(menuNum == 3){
            // Search Operation
            int found = 1;
            do
            {
                int searchOption;

                cout << "Please select a column to search";
                cout << "\n1. Search with Entry Number";
                cout << "\n2. Search with Name";

                cout << "\n\nEnter your selection: ";
                cin >> searchOption;

                switch(searchOption)
                {
                case 1:
                    current = first;
                    int searchQuery;
                    int found;

                    cout << "\nEnter a number to find: ";
                    cin >> searchQuery;

                    while (current != NULL)
                    {
                        if(current->entryNum == searchQuery)
                        {
                            cout <<"\nEntry Number    Kit Name                                                Kit Model            Release Year      Is Favourite?\n";
                            cout <<"------------------------------------------------------------------------------------------------------------------------------\n";
                            cout << left << setw(16) <<current->entryNum;
                            cout << left << setw(56) <<current->name;
                            cout << setw(23)<<current->type;
                            cout << setw(20)<<current->release_year;

                            if (current->is_Favourite){
                                cout << setw(10)<<"Yes";
                            } else if (!current->is_Favourite)
                            {
                                cout << setw(10)<<"No";
                            }
                            found = 1;
                            cout << "\n";
                            break;
                        }else{
                            current = current->next;
                        }
                        
                        if (found == 0){
                            cout << "No Data!";
                            break;
                        }
                    }
                    break;
                case 2:
                    current = first;
                    bool foundAny;

                    cout << "\n\nEnter a name to find: ";
                    cin >> ws;
                    getline(cin, searchQueryChar);

                    cout <<"\nEntry Number    Kit Name                                                Kit Model            Release Year      Is Favourite?\n";
                    cout <<"------------------------------------------------------------------------------------------------------------------------------\n";

                    while (current != NULL)
                    {   
                        string findingData = current->name;
                        if(findingData.find(searchQueryChar) != string::npos)
                        {
                            cout << left << setw(16) <<current->entryNum;
                            cout << left << setw(56) <<current->name;
                            cout << setw(23)<<current->type;
                            cout << setw(20)<<current->release_year;

                            if (current->is_Favourite){
                                cout << setw(10)<<"Yes";
                            } else if (!current->is_Favourite)
                            {
                                cout << setw(10)<<"No";
                            }
                            
                            cout << "\n";
                            foundAny = true;
                        } 

                        current = current->next;
                        
                    }

                    if (!foundAny){
                        cout << "No Data!";
                    }
                    foundAny = false;
                    break;
                default:
                    break;
                }

                cout << "\nDid you find the record? Enter 1 to go to the Main Menu, 0 to restart search: ";
                cin >> found;

            } while (found == 0);

            cout << "\nPress enter to continue...";
            cin.ignore();
            cin.get();

        } else if(menuNum == 4){
            current = first;
            previous = NULL;
            delptr = NULL;
            
            int delNum;

            cout << "\nPlease enter a Number to delete: ";
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

            cout << "\nThe Entry Has Been Scrapped!!";
            cout << "\nPress enter to continue...";
            cin.ignore();
            cin.get();
        } else if(menuNum == 5){
            cout << "\nThank you for using the Gundam Database! >.<\n";

            break;
        }else{
            cout << "\nError please enter number from 1-5 only...";
            cin.ignore();
            cin.get();
        }
    }
    

    return 0;
}