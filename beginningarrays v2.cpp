// Randy Phan-Huynh
// This program will read files, put them into an array, and display them.
// 10/14/19
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int row = 10;
ifstream in;
ofstream out;

void extractBot(string name[row])
{
	in.open("name.txt");
	
	for (int i = 0; i < 10; i++)
	{
		in >> name[i];
	}

	cout << "Extract complete." << endl;
}

void displayBot(string name[row])
{
	out.open("myrecords1.txt");

	for (int i = 0; i < 10; i++)
	{
		out << name[i] << endl;
	}

	cout << "Display complete." << endl;
}
int main()
{
	string n[row];

	extractBot(n);
	displayBot(n);

	in.close();
	out.close();

	return 0;
}