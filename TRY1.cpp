#include <stack>
using namespace std;

unsigned int try(unsigned short d, unsigned int points, unsigned short CurPos, unsigned short* field, stack<unsigned short> sChance)	
{
	stack<unsigned short> sChance1 = sChance;
	stack<unsigned short> sChance2;
	
	bool sChanceSelect=false;
	do
	{
		switch field[CurPos]
		{
			case 1:
			{
				if (sChanceSelect==false)
				{
					unsigned short Card = sChance1.top();
				}
				else
				{
					unsigned short Card = sChance2.top();
				}
				switch (Card)
				{
					case 1:
					{	
						points+=3;
						if (3>n)
						{
							step = 3%n;
							CurPos += step;
						} else CurPos += 3;
					}break;
					case 2:
					{
						if (3>CurPos)
						{
							step = 3%n;
							CurPos -= step;
						} else CurPos -= 3;
						points-=3;
					}break;
					
					case 3:
					{
						//cout << "Go to 'START'"<< endl;
						CurPos=0;
						points+=(n-CurPos);
					}break;
				}
				if (sChanceSelect==false)
				{
					sChance2.push(sChance1.top());
					sChance1.pop();
					if (sChance1.empty()) sChanceSelect = true;
				}
				else
				{
					sChance1.push(sChance2.top());
					sChance2.pop();
					if (sChance2.empty()) sChanceSelect = false;
				}		
			} break;
			case 0:
			{
				points +=d;
				return points;	
			}	

	} while (1/*exit == false*/);
}
	

int try1(unsigned short d, unsigned short dice12, unsigned short dice22,
 unsigned int points, unsigned short CurPos,
 unsigned short* field, stack<unsigned short> sChance)	
{
	stack<unsigned short> sChance1 = sChance;
	stack<unsigned short> sChance2;
	
	bool exit=false;
	bool first;
	do
	{
		switch field[CurPos]
		{
			case 0:
			{
				if (first)
				{
					d = dice11 + dice21;
					points += d;

				} else
				{
					d = dice12 + dice22;
					points +=d;
					return points;
				}	
			} break;

			case 1:
			{
				switch (Card)
				{
					case 1:
					{
						points+=3;
						if (3>n)
						{
							step = 3%n;
							CurPos += step;
						} else CurPos += 3;
					} break;
					case 2:
					{
						if (3>CurPos)
						{
							step = 3%n;
							CurPos -= step;
						} else CurPos -= 3;
						points-=3;
					} break;
					
					case 3:
					{
						CurPos=0;
						points+=(n-CurPos);
					} break;
				}
			}
		}
	} while (exit == false);
	return points;
}