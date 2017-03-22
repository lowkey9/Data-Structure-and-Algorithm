#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int endPre(string s, int first, int last)
{
	if (first < 0 || first > last)
		return -1;
	else if (s[first] >= 'a' && s[first] <= 'z')
		return first;
	else if (!(s[first] == '+' || s[first] == '-' || s[first] == '*' || s[first] == '/'))
		return - 1;
	else {
		int firstEnd = endPre(s, first + 1, last);

		if (firstEnd >= 0)
			return endPre(s, firstEnd + 1, last);

		return -1;
	}
}

int main()
{
	string s;
	ifstream ifile("../Data/input.txt");
	if (ifile.is_open()) {
		while (!ifile.eof()) {
			getline(ifile, s);
			cout << "The expression is: " << s << endl;
			//the end of string in linux is null/empty
			//it ought to be omit by OS i suppose
			//but during the test it is not
			//so s.length() - 2 is used
			int index = endPre(s, 0, s.length() - 2);
			if (index == -1)
				cout << "Error" << endl;
			else if(index == 0)
				cout << "This expression is not a prefix expression." << endl;
			else {
				if(index==s.length()-2)
					cout << "The end of this expression is: " << index << endl;
				else
					cout << "This expression is not a prefix expression." << endl;
			}
			cout << endl << endl;
		}
	}
    return 0;
}
