// CS 2250 Project 3 - Horse Race - Terry Ford
// Implementation file for the Horse Class

#include "Horse.h"
#include <ctime>
#include <iomanip>

Horse::Horse(string n, string r)               // Constructor sets up each horse with a name and speed
{
	name = n;
	rider = r;
    unsigned seed = time(0);
    srand(seed);
    maxRunningDistPerSecond = 1 + (rand() % 99);
    sendToGate();
}

Horse::Horse()                                // Default Constructor
{}

void Horse::runASecond()
{
    unsigned seed = time(0);
    srand(seed);
    distanceTraveled += 1 + (rand() % maxRunningDistPerSecond);        
}

void Horse::displayHorse(int goalLength, bool &raceOver)             
{
    if ((goalLength / 20 - distanceTraveled / 5) <= 0)                           // If horse has won display
    {
        int maxDist = (distanceTraveled / 5 + (goalLength / 20 - distanceTraveled / 5));
        cout << "|";
        for (int i = 0; i <= maxDist; i++)
        {
            cout << "-";
        }       
        cout << "|>\t" << name << ", ridden by " << rider << " has won the Race!!" << endl;
        racesWon++;
        raceOver = true;
    }
    else                                                                     // else horse hasn't won
    {
        cout << "|";
        for (int i = 0; i < distanceTraveled / 5; i++)
        {
            cout << "-";
        }
        cout << ">";
        for (int i = 0; i < (goalLength / 20 - distanceTraveled / 5); i++)
        {
            cout << " ";
        }
        cout << "|\t" << name << ", ridden by " << rider << endl;
    }    
}

void Horse::displayRecord(int races)
{
    cout << setw(10) << left << name << " ridden by " << setw(10) << left << rider << "\t" << racesWon << "/" << races << " races won" << endl;
}
