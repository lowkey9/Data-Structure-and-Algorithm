#ifndef FLIGHTINFO_H
#define FLIGHTINFO_H

#include <iostream>
#include <string>
#include "City.h"

using namespace std;

class FlightInfo
{
public:
	FlightInfo();
	void clear();
	void init();
	void addCity(City *);
	void addAdjcCity(City *, string);
	City* search(string);
	void bt_recursive(string, string, string, string);
	void bt_stack(string, string);
	void display();
private:
	City *cityHead;
	City *cityTail;
	int num;
};

#endif