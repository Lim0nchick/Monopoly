#include <fstream>
#include "field.h"
#include <iostream>
#include <ctime>
using namespace std;


int main()
{
	srand(time(0));
	unsigned short int MapSize;
	cin >> MapSize;
	unsigned short int* field = new unsigned short int[MapSize];
	fstream Map;
	Map.open("Map.dat", ios::out);
	Map << MapSize;
	Map << endl;
	for (unsigned short i=0; i<MapSize; i++)
	{
		field[i]=rand()%2+0;
		Map << field[i] << endl;
	}

	unsigned short ChanceStackSize;
	cin >> ChanceStackSize;
	Map << ChanceStackSize;
	Map << endl;
	unsigned short int* ChanceStack = new unsigned short int[ChanceStackSize];
	for (unsigned short i=0; i<ChanceStackSize; i++)
	{
		ChanceStack[i]=rand()%2+0;
		Map << ChanceStack[i] << endl;
	}

	Map.close();
	return 0;
}