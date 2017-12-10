#include "Cages.h"
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	srand(time(0));

	unsigned short points = 0;
	unsigned short n;
	
	fstream Map;
	Map.open("Map.dat", ios::in);
	if(!Map) return 1; // Если ошибка открытия файла, то завершаем программу
	Map >> n;
	unsigned short* field = new unsigned short[n];
	unsigned short CurPos;
	for (CurPos=0; CurPos<n; CurPos++)	// CurPos является индексом для экономии памяти, чтобы не выделять память для доп переменной 
	{
		Map >> field[CurPos];
	}
	Map.close();
	for (CurPos=0; CurPos<n; CurPos++)	// CurPos является индексом для экономии памяти, чтобы не выделять память для доп переменной 
	{
		cout << field[CurPos] << endl;
	}
	
	unsigned short dice1, dice2, d;
	dice1 = rand()%6+1; cout << "dice1 = " << dice1 << endl; 
	dice2 = rand()%6+1; cout << "dice2 = " << dice2 << endl;
	d = dice1 + dice2;
	cout << d << endl;

	points+=d;
	cout << points << " points" << endl;

	unsigned short step;
	if (d>n)
	{
		step = d%n;
		CurPos = step;
	} else CurPos = d;
	unsigned short c_doubles;
	if (dice1=dice2)
		c_doubles+=1;
	
	bool exit=false;
	do
	{
		if (field[CurPos]!=1)
		{
			if (c_doubles != 0)
			{
				dice1 = rand()%6+1; cout << "dice1 = " << dice1 << endl; 
				dice2 = rand()%6+1; cout << "dice2 = " << dice2 << endl;
				d = dice1 + dice2;
				cout << d << endl;
				if (dice1=dice2)
				{
					c_doubles+=1;
					points+=d;
					if (d>n)
					{
						step = d%n;
						CurPos = step;
					} else CurPos = d;
					if (c_doubles=3)
						exit = true;
					
				} else exit = true;	
			} else exit = true;	
		}

		switch (field[CurPos])
		{
			case 1:
			{
				cout << "Chance, give and read a Chance-card" << endl;
				unsigned short Card = rand()%4+1;
				switch (Card):
				{
					case 1:
					{
						cout << "get 3 points and pass to 3 cages forward" << endl;
				
						points+=3;
						if (3>n)
						{
							step = 3%n;
							CurPos += step;
						} else CurPos += 3;
						break;
					}
					case 2:
					{
						cout << "lose 3 points and pass to 3 cages back" << endl;
						if (3>CurPos)
						{
							step = 3%n;
							CurPos -= step;
						} else CurPos -= 3;
						points-=3;
						break;
					}
					case 3:
					{
						cout << "extra course" << endl;
						dice1 = rand()%6+1; cout << "dice1 = " << dice1 << endl; 
						dice2 = rand()%6+1; cout << "dice2 = " << dice2 << endl;
						d = dice1 + dice2;
						cout << d << endl;
						if (dice1=dice2)
							c_doubles+=1;
						else c_doubles=0;
						if (c_doubles=3)
							exit = true;
						else
						{
							points+=d;
							if (d>n)
							{
								step = d%n;
								CurPos = step;
							} else CurPos = d;
						}
						break;
					}
					case 4:
					{
						cout << "Go to 'START'"<< endl;
						CurPos=0;
						points+=(n-CurPos);
						break;
					}
				}
				cout << points << " - points" << endl;
				cout << CurPos << " - Current position" << endl;
			default:
			{
				cout << " Empty cage" << endl;
				break;
			}
	} while (exit = false)
	
	system("pause");
	return 0;
}