#ifndef CITY_H
#define CITY_H

#include <iostream>
#include <string>

using namespace std;

class City
{
	friend class FlightInfo;
private:
	string cityName;
	string adjc;
	City *next;
public:
	City(string);
};

#endif
