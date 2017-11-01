#include "field.h"
#include "Cages.h"
#include <iostream>
using namespace std;
int main()
{
	srand(time(0));
	bool Player;
	unsigned int points1, points2;
	cout << "Input first player name:";
	string pl1;
	cin << pl1;
	cout << "Input second player name:";
	string pl2;
	cin << pl2;
	unsigned int dice1, dice2, d;
	dice1 = rand()%6+1; cout << "dice1 = " << dice1 << endl; 
	dice2 = rand()%6+1; cout << "dice2 = " << dice2 << endl;
	if 	(dice1>dice2) cout << pl1 << " go first" << endl;
	else cout << pl2 << " go first" << endl;
	do
	{

	} while (points1<10 || points2<10);

}