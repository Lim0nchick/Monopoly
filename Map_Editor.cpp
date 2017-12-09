#include <fstream>
#include "field.h"
using namespace std;


int main()
{
	unsigned short int n;
	cin >> n;
	unsigned short int* field = new unsigned short int[n];
	fstream Map;
	Map.open("Map.dat", ios::out);
	Map << n;
	for (int i=0; i<n; i++)
	{
		field[i]=rand()%1+0;
		Map << field[i];
	}
	Map.close("Map.dat");
	return 0;
}