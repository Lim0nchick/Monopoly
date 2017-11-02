#include "field.h"
#include "Cages.h"
#include <iostream>
using namespace std;
int main()
{
	srand(time(0));
	bool Player;
	unsigned int points1=0;
	unsigned int points2=0;
	
	string pl1;
	cout << "Input first player name:";
	cin << pl1;
	
	string pl2;
	cout << "Input second player name:";
	cin << pl2;
	ReadMap(); // Function for get Monopoly map from file, UNDERFINED!
	Field *p1=start;
	Field *p2=start;

	unsigned int dice1, dice2, d;
	dice1 = rand()%6+1; cout << "dice1 = " << dice1 << endl; 
	dice2 = rand()%6+1; cout << "dice2 = " << dice2 << endl;
	if 	(dice1>dice2) 
	{
		cout << pl1 << " go first" << endl;
		Player=true;
	}
	else 
	{
		cout << pl2 << " go first" << endl;
		Player=false;
	}

	do
	{
		dice1 = rand()%6+1; cout << "dice1 = " << dice1 << endl; 
		dice2 = rand()%6+1; cout << "dice2 = " << dice2 << endl;
		d = dice1 + dice2;
		cout << d << endl;
		if (Player)
		{
			p1=forward(d, p1);
			points1+=d;
			Player=false;
			cout << pl1 << "has " << points1 << " points" << endl;
			switch (p1)
			{
				case chance:
				{
					cout << pl1 << " on Chance, give and read a Chance-card" << endl;
					chance(points1, p1);
					break;
				}
				case start:
				{
					cout << pl1 << " on Start, get 5 points" < endl;
					points1+=5;
					break;
				}
				case fate:
				{
					cout << pl1 << " on Fate, give and read a Fate-card" << endl;
					fate(); // FUCTION UNDERFINED!!!
					break;
				}
				case penalty:
				{
					cout << pl1 << " on Penalty, " << pl1 << " lose 2 points" << endl;
					points1-=2;
					break;
				}
				case bonus:
				{
					cout << pl1 << " on Bonus, " << pl1 << " get 2 points" << endl;
					points1+=2;
					break;
				}
				default:
				{
					cout << pl2 << " on Empty cage" << endl; 
					break;
				}
			}
			cout << pl1 << "has " << points1 << " points" << endl;
		}
		else
		{
			p2=forward(d, p2);
			points2+=d;
			Player=false;
			cout << pl2 << "has " << points2 << " points" << endl;
			switch (p1)
			{
				case chance:
				{
					cout << pl2 << " on Chance, give and read a Chance-card" << endl;
					chance(points2, p2);
					break;
				}
				case start:
				{
					points2+=5;
					cout << pl2 << " on Start, get 5 points" < endl;
					break;
				}
				case fate:
				{
					cout << pl2 << " on Fate, give and read a Fate-card" << endl;
					fate(); // FUCTION UNDERFINED!!!
					break;
				}
				case penalty:
				{
					cout << pl2 << " on Penalty, " << pl2 << " lose 2 points" << endl;
					points2-=2;
					break;
				}
				case bonus:
				{
					cout << pl2 << " on Bonus, " << pl2 << " get 2 points" << endl;
					points2+=2;
					break;
				}
				default:
				{
					cout << pl2 << " on Empty cage" << endl; 
					break;
				}
			}
			cout << pl2 << "has " << points2 << " points" << endl;
		}

	} while (points1<10 || points2<10);

	if (points1>=10)
		cout << pl1 << " win!\nThanks for the game." << endl;
	else cout << pl2 << " win!\nThanks for the game." << endl;
return 0;
}