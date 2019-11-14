// Randy Phan-Huynh
// This program will read files, put them into an array, sort them, and display them.
// 10/14/19
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int row = 10;
const int col = 3;
ifstream inn, ing;
ofstream out;

void sortBot(char letter[row], double avg[row], int sum[row], string name[row], int grade[row][col])
{
	char templ;
	double tempa;
	int temps, tempg;
	string tempn;

	for (int r = 0; r < row; r++)
	{
		for (int s = 0; s < row - 1; s++)
		{
			if (letter[s] > letter[s + 1])
			{
				templ = letter[s];
				letter[s] = letter[s + 1];
				letter[s + 1] = templ;

				tempa = avg[s];
				avg[s] = avg[s + 1];
				avg[s + 1] = tempa;

				temps = sum[s];
				sum[s] = sum[s + 1];
				sum[s + 1] = temps;

				tempn = name[s];
				name[s] = name[s + 1];
				name[s + 1] = tempn;

				for (int c = 0; c < col; c++)
				{
					tempg = grade[s][c];
					grade[s][c] = grade[s + 1][c];
					grade[s + 1][c] = tempg;
				}
			}
		}
	}

	cout << "Sort complete." << endl;
}

void letterBot(double avg[row], char letter[row])
{
	for (int r = 0; r < row; r++)
	{
		if (avg[r] >= 90)
			letter[r] = 'A';
		else if (avg[r] >= 80 && avg[r] < 90)
			letter[r] = 'B';
		else if (avg[r] >= 70 && avg[r] < 80)
			letter[r] = 'C';
		else if (avg[r] >= 60 && avg[r] < 70)
			letter[r] = 'D';
		else
			letter[r] = 'F';

	}
}

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

void displayBot(string name[row], int grade[row][col], int sum[row], double avg[row], char letter[row])
{
	out.open("myrecords6.txt");
	
	out << setw(11) << left << "|NAMES  |" << " ";
	out << setw(10) << right << "|GRADES      |" << " ";
	out << setw(8) << right << "|TOTAL|" << " ";
	out << setw(4) << right << "|AVERAGE|" << " ";
	out << setw(4) << right << "|LETTER GRADE|" << " " << endl;
	out << "------------------------------------------------------------" << endl;


	for (int r= 0; r< row; r++)
	{
		out << setw(10) << left << name[r] << " " ;

		for(int c = 0; c < col; c++)
		{
			out << setw(4) << right << grade[r][c] << " ";
		}

		out << setw(7) << right << sum[r] << " ";
		out << setw(8) << right << avg[r] << " ";
		out << setw(10) << right << letter[r] << " ";

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
	char l[row] = {};

	extractBot(n, g);
	gradetotalBot(g, s);
	avgBot(s, a);
	letterBot(a, l);
	sortBot(l, a, s, n, g);
	displayBot(n, g, s, a, l);

	inn.close();
	ing.close();
	out.close();

	return 0;
}