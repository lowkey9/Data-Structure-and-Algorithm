#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "FlightInfo.h"

using namespace std;

FlightInfo::FlightInfo():cityHead(0),cityTail(0),num(0)
{}

void FlightInfo::clear()
{
	City *curPtr = cityHead;
	while (curPtr->next!=NULL) {
		curPtr->adjc.clear();
		curPtr = curPtr->next;
	}
	curPtr->adjc.clear();
}

void FlightInfo::init()
{
	/* initial cities */
	//declear new City node
	City *newCity;
	//operations on file cities.txt
	ifstream ifile1("cities.txt");
	if (ifile1.is_open()) {
		string line;
		while (getline(ifile1, line)) {
			istringstream sin(line);
			string field;

			while (getline(sin, field, ',')) {
				newCity = new City(field);
				addCity(newCity);
			}
		}
	}
	ifile1.close();

	/* initial adjacent cities */
	//operations on file flights.txt
	ifstream ifile2("flights.txt");
	if (ifile2.is_open()) {
		string line;
		int counter = 0;
		int index = 0;
		City *tmpPtr = NULL;		//pointer points to node corresponding to origin
		while (getline(ifile2, line)) {
			istringstream sin(line);
			string field;

			while (getline(sin, field, ',')) {
				string newAdjac;
				if (counter % 2 == 0) {
					//finding the City node corresponding to origin 
					tmpPtr = search(field);
					counter++;
				}
				else {
					//newAdjac = new AdjcCity(field);
					newAdjac.push_back(field.front());
					addAdjcCity(tmpPtr, newAdjac);
					counter++;
				}
			}
		}
	}
	ifile2.close();
}

void FlightInfo::addCity(City *newCity)
{
	/* add city as a new node in linked list */
	if (!num) {
		cityHead = cityTail = newCity;
	}
	else {
		cityTail->next = newCity;
		cityTail = newCity;
	}
	num++;
}

void FlightInfo::addAdjcCity(City *origin, string newAdjac)
{
	/* add new adjacent city at the end of the string */
	if (origin->adjc.empty())
		origin->adjc = newAdjac;
	else {
		origin->adjc.push_back(newAdjac.front());
	}
}

City* FlightInfo::search(string name)
{
	/* search given city in linked list */
	City *currentPtr = cityHead;
	City *tmpPtr;
	bool flag = false;
	if (currentPtr == NULL)
		flag = false;
	if (currentPtr->cityName == name) {
		tmpPtr = currentPtr;
		flag = true;
	}
	else {
		while (1) {
			if (currentPtr->next != NULL) {
				if (currentPtr->next->cityName == name) {
					tmpPtr = currentPtr->next;
					flag = true;
					break;
				}
				currentPtr = currentPtr->next;
			}
			else {
				if (currentPtr->cityName == name) {
					tmpPtr = currentPtr;
					flag = true;
					break;
				}
				break;
			}
		}
	}
	if (!flag) {
		return NULL;
	}
	else {
		return tmpPtr;
	}
}

void FlightInfo::display()
{
	cout << "Relations: " << endl;
	City *curPtr = cityHead;
	int counter = 0;
	//AdjcCity *curAdjCity;
	while (counter<9) {
		cout << curPtr->cityName << ": ";
		if (!(curPtr->adjc.empty())) {
			cout << "adjc cities: ";
			cout << curPtr->adjc << endl;
		}
		else
			cout << endl;
		curPtr = curPtr->next;
		counter++;
	}
}

void FlightInfo::bt_recursive(string o, string d, string c, string c_old)
{
	/* o = origin; d = destination; c = adjacent city; c_old = previous adjacent city*/
	cout << c << " ";
	City *curPtr = NULL;
	curPtr = search(c);
	
	if (c == d) {
		//terminate if the destination is reached
		return;
	}
	else{
		if (curPtr == NULL) {
			//terminate if there is no required city in the list
			cout << "Error with city name." << endl;
			return;
		}
		else if (c == c_old && curPtr->adjc.empty()) {
			//terminate if there is no required airlines
			cout << "No airlines meet requirement." << endl;
			return;
		}
		else {
			//if current choice cannot go further to the destination
			//go back and pick up another adjacent cith
			if (curPtr->adjc.empty())
				return bt_recursive(o, d, c_old, c_old);
			else {
				string tmp = curPtr->adjc.substr(0, 1);
				curPtr->adjc.erase(0, 1);
				//if current city only has one adjacent city
				if (curPtr->adjc.empty())
					return bt_recursive(o, d, tmp, c_old);
				//if current city has more than one adjacent cities
				else
					return bt_recursive(o, d, tmp, c);
			}
		}
	}
}

void FlightInfo::bt_stack(string o, string d)
{
	cout << o << " ";

	//using a string as the stack
	//push_back() and pop_back() will be the push and pop operation of stack
	string stack;
	stack.push_back(o.front());

	City *curPtr = NULL;
	string tmp;
	curPtr = search(stack.substr(stack.length()-1,1));
	if (curPtr == NULL) {
		//terminate if there is no required city in the list
		cout << "Error with city name." << endl;
		return;
	}
	else {
		while (stack.length() != 0) {
			curPtr = search(stack.substr(stack.length() - 1, 1));
			if (curPtr->adjc.empty())
				stack.pop_back();
			else {
				tmp = curPtr->adjc.substr(0, 1);
				cout << tmp << " ";
				if (tmp == d)
					return;
				curPtr->adjc.erase(0, 1);
				stack.push_back(tmp.front());
			}
		}
		if (stack.length() == 0) {
			//terminate if there is no required airlines
			cout << "No airlines meet requirement." << endl;
			return;
		}
	}
}