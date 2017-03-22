#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
#include "City.h"
#include "FlightInfo.h"

using namespace std;

int main()
{
	FlightInfo test;
	
	ifstream ifile("requests.txt");
	if (ifile.is_open()) {
		string line;
		string origin, destination;
		int counter = 0;
		while (getline(ifile, line)) {
			istringstream sin(line);
			string field;

			while (getline(sin, field, ',')) {
				string newAdjac;
				if (counter % 2 == 0) {
					origin = field;
					counter++;
				}
				else {
					destination = field;
					counter++;
				}
			}
			cout << "Origin: " << origin << "\t" << "Destination: " << destination << endl;
			cout << "Recursive: " << endl;
			test.init();
			auto begin1 = std::chrono::high_resolution_clock::now();
			test.bt_recursive(origin, destination, origin, origin);
			auto end1 = std::chrono::high_resolution_clock::now();
			cout << std::chrono::duration_cast<std::chrono::microseconds>(end1 - begin1).count() << "ms" << endl;
			test.clear();
			cout << endl << "****************************" << endl;
			cout << "Stack: " << endl;
			test.init();
			auto begin2 = std::chrono::high_resolution_clock::now();
			test.bt_stack(origin, destination);
			auto end2 = std::chrono::high_resolution_clock::now();
			cout << std::chrono::duration_cast<std::chrono::microseconds>(end2 - begin2).count() << "ms" << endl;
			test.clear();
			cout << endl << endl;
		}
	}
	
	return 0;
}