// Randy Phan-Huynh
// This program will read files, put them into an array, and display them.
// 10/14/19
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream in;
	string name[10] = {};

	in.open("name.txt");

	for (int i = 0; i < 10; i++)
	{
		in >> name[i];
	}

	for (int i = 0; i < 10; i++)
	{
		cout << name[i] << endl;
	}

	in.close();

	return 0;
}