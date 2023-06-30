#pragma once
// CS 2250 Project 3 - Horse Race - Terry Ford
// Specification File for Horse Class

#include <iostream>
#include <string>
using namespace std;
#ifndef HORSE_H
#define HORSE_H

class Horse
{
private:
	string name,
		rider;
	int maxRunningDistPerSecond,
		distanceTraveled = 0,
		racesWon = 0;
public:
	Horse();
	Horse(string, string);                // Constructor   info on PG 786		
	void runASecond();
	void sendToGate()
	{
		distanceTraveled = 0;
	}
	void displayHorse(int, bool&);
	void displayRecord(int);
};
#endif