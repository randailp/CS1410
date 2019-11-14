// Randy Phan-Huynh
// This program will read files, put them into an array, and display them.
// 10/14/19
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int row = 10;
const int col = 3;
ifstream inn, ing;
ofstream out;

void avgBot(int sum[row], double avg[row])
{
	for (int r = 0; r < row; r++)
	{
		avg[r] = sum[r] / static_cast <double> (col);
	}
}

void gradetotalBot(int grade[row][col], int sum[row])
{
	for (int r = 0; r < row; r++)
		for (int c = 0; c < col; c++)
			sum[r] = sum[r] + grade[r][c];
}

void displayBot(string name[row], int grade[row][col], int sum[row], double avg[row])
{
	out.open("myrecords4.txt");
	
	for (int r= 0; r< row; r++)
	{
		out << setw(10) << left << name[r] << " " ;

		for(int c = 0; c < col; c++)
		{
			out << setw(4) << right << grade[r][c] << " ";
		}

		out << setw(4) << right << sum[r] << " ";
		out << setw(4) << right << avg[r] << " ";

		out << endl;
	}

	cout << "Display complete." << endl; 
}

void extractBot(string name[row], int grade[row][col])
{
	inn.open("name.txt");
	ing.open("grade.txt");

	for (int r = 0; r < row; r++)
	{
		inn >> name[r];

		for (int c = 0; c < col; c++)
		{
			ing >> grade[r][c];
		}
	}

	cout << "Extraction complete." << endl;
}

int main()
{
	string n[row] = {};
	int g[row][col] = { 0 };
	int s[row] = { 0 };
	double a[row] = { 0 };

	extractBot(n, g);
	gradetotalBot(g, s);
	avgBot(s, a);
	displayBot(n, g, s, a);

	inn.close();
	ing.close();
	out.close();

	return 0;
}