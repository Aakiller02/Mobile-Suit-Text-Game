#include <iostream>
#include <thread>
#include <chrono>
#include "storyQueue.h"

using namespace std;
using namespace this_thread;
using namespace chrono;

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
                string tempText = front->lines;
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