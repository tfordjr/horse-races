// CS 2250 Project 3 - Horse Race - Terry Ford
// Main Project File

#include "Horse.h"
#include "Horse.cpp"
using namespace std;

int main()
{
    int numHorses, goal;   
    Horse* horsePtr = nullptr;

    cout << "How many horses are in the race?  ";    
    cin >> numHorses;
    while (numHorses < 1 || numHorses > 5)                // numHorses user input validation
    {
        cout << "Please choose a number of horses between 1 and 5   ";
        cin >> numHorses;                 
    }
    cin.ignore();                                         // cin.ignore lets use use getline later on without issues

    horsePtr = new Horse[numHorses];                                  

    for (int i = 0; i < numHorses; i++)                   // horse and rider names user input
    {                                       
        string n, r;                                     
        cout << "Please give me the name of horse " << i + 1 << ": ";
        getline(cin, n);
        cout << "Please give me the name of rider " << i + 1 << ": ";
        getline(cin, r);
    
        horsePtr[i] = Horse(n, r);         
    }
    
    cout << "Please enter the distance of the race: ";                   
    cin >> goal; 
    while (goal < 100 || goal > 1500)                               // goal distance user input validation
    {
        cout << "Please choose a distance between 100 and 1500:   ";
        cin >> goal;
    }

    bool raceOver = false;
    char next;
    int totalRaces = 0;
    cout << "\n\nPop Pop Pop! And we're off to the races!!!\n";
    do
    {        
        do
        {
            raceOver = false;
            cout << "\n\nThe Crowd is roaring!!! They're neck and neck!\n";
            for (int i = 0; i < numHorses; i++)
            {
                horsePtr[i].runASecond();                            // Main race loop
                horsePtr[i].displayHorse(goal, raceOver);
            }
            
            if (raceOver)               // exit while loop if raceOver
                break;

            cout << "\n\nReady for the next second? (y/n) :  ";
            cin >> next; 
            while (next != 'y' && next != 'n')            // next second ? user input validation
            {
                cout << "Please answer y or n  ";          
                cin >> next;
            }

        } while (next == 'y');
        
        totalRaces++;
        cout << endl;

        for (int i = 0; i < numHorses; i++)
        {
            horsePtr[i].displayRecord(totalRaces);
            horsePtr[i].sendToGate();
        }

        cout << "Would you like to race again?  ";         
        cin >> next;
        while (next != 'y' && next != 'n')        // race again ? user input validation
        {
            cout << "Please answer y or n  ";
            cin >> next;
        }

    } while (next == 'y');
    cout << "\nThanks for playing!";

    delete[] horsePtr;                // delete allocated memory
    return 0;
}

