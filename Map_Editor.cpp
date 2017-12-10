#include <fstream>
#include "field.h"
#include <iostream>
#include <ctime>
using namespace std;


int main()
{
	unsigned short int n;
	cin >> n;
	unsigned short int* field = new unsigned short int[n];
	fstream Map;
	Map.open("Map.dat", ios::out);
	Map << n;
	Map << endl;
	for (unsigned short i=0; i<n; i++)
	{
		field[i]=rand()%2+0;
		Map << field[i] << endl;
	}
	Map.close();
	return 0;
}