#ifndef ADJCCITY_H
#define ADJCCITY_H

#include <iostream>
#include <string>

using namespace std;

class AdjcCity
{
	friend class FlightInfo;
private:
	string adjccityName;
	//City *d2s;
	AdjcCity *next;
public:
	AdjcCity(string);
};

AdjcCity::AdjcCity(string name):adjccityName(name),next(NULL)
{}

#endif