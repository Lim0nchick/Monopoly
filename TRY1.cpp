#include <stack>
using namespace std;

unsigned int try(unsigned short d, unsigned int points, unsigned short CurPos,
	unsigned short* field, stack<unsigned short> sChance1)	
{
	stack<unsigned short> sChance1;
	stack<unsigned short> sChance2;
	
	if (d>n)
	{
		step = d%n;
		CurPos += step;
	} else CurPos += d;

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
				points += d;
				return points;	
			}	

	} while (1);
	return points;
}
	

unsigned int try1(unsigned short d1, unsigned short d2,
 unsigned int points, unsigned short* field, unsigned short CurPos,
 stack<unsigned short> sChance1)	
{
	stack<unsigned short> sChance1;
	stack<unsigned short> sChance2;
	
	bool first;
	bool second;
	bool secondAfterChance;

	if (CurPos!=0)
	{
		first = false;
		switch (field[CurPos])
		{
			case 0:
			{
				second = true;
			} break;
			case 1:
			{
				secondAfterChance = true;
			} break;
		}
		//second = true;
	} else
	{
		if (d1>n)
		{
			step = d1%n;
			CurPos += step;
		} else CurPos += d1;
	}
	
	do
	{
		switch field[CurPos]
		{
			case 0:
			{
				if (secondAfterChance)
				{
					points += d2;
					return points;
				}
				if (second)
				{
					if (d2>n)
					{
						step = d2%n;
						CurPos += step;
					} else
					{
						CurPos += d2;
						second = false;
						secondAfterChance = true;
					}
					if (field[CurPos] == 0)
					{
						points += d2;
						return points;
					}
				}
				if (first)
				{
					points += d1;
					second = true;
					first = false;
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
	} while (1);
	return points;
}

unsigned int try2(unsigned short d1, unsigned short d2, unsigned short d3,
 unsigned int points, unsigned short CurPos,
 unsigned short* field, stack<unsigned short> sChance1)	
{
	stack<unsigned short> sChance1;
	stack<unsigned short> sChance2;
	
	bool first = true;
	bool second = false;
	bool third = false;
	bool thirdAfterChance = false;

	if (CurPos!=0) // ДОДЕЛАТЬ!!!
	{
		first = false;
		switch (field[CurPos])
		{
			case 0:
			{
				third = true;
			} break;
			case 1:
			{
				thirdAfterChance = true;
			}
		}
		//second = true;
	} else
	{
		if (d1>n)
		{
			step = d1%n;
			CurPos += step;
		} else CurPos += d1;
	}
	do
	{
		switch field[CurPos]
		{
			case 0:
			{
				if (thirdAfterChance)
				{
					points += d3;
					return points;
				}
				if (third)
				{
					if (d3>n)
					{
						step = d3%n;
						CurPos += step;
					} else CurPos += d3;
					if (field[CurPos] == 0)
					{
						points += d3;
						return points;
					} else 
					{
						third = false;
						thirdAfterChance = true;
					}
				}
				if (second)
				{
					if (d2>n)
					{
						step = d2%n;
						CurPos += step;
					} else CurPos += d2;
					if (field[CurPos] == 0)
					{
						points += d2;
						second = false;
						third = true;
					}
				}
				if (first)
				{
					points += d1;
					second = true;
					first = false;
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
	} while (1);
	return points;
}

/*unsigned int try3(unsigned short d1, unsigned short d2, unsigned short d3, unsigned short d4,
 unsigned int points, unsigned short CurPos,
 unsigned short* field, stack<unsigned short> sChance1)	
{
	stack<unsigned short> sChance1;
	stack<unsigned short> sChance2;
	
	bool first = true;
	bool second = false;
	bool third = false;
	bool fourth = false;
	bool fourthAfterChance = false;

	if (d1>n)
	{
		step = d1%n;
		CurPos += step;
	} else CurPos += d1;

	do
	{
		switch field[CurPos]
		{
			case 0:
			{
				if (fourthAfterChance)
				{
					points += d4;
					return points;
				}
				if (fourth)
				{
					if (d4<n)
					{
						step = d4%n;
						CurPos += step;
					} else CurPos += d4;
					if (field[CurPos] == 0)
					{
						points += d4;
						return points;
					} else 
					{
						fourth = false;
						fourthAfterChance = true;
					}
				}
				if (third)
				{
					if (d3>n)
					{
						step = d3%n;
						CurPos += step;
					} else CurPos += d3;
					if (field[CurPos] == 0)
					{
						points += d3;
						third = false;
						fourth = true;
					}
				}
				if (second)
				{
					if (d2>n)
					{
						step = d2%n;
						CurPos += step;
					} else CurPos += d2;
					if (field[CurPos] == 0)
					{
						points += d2;
						second = false;
						third = true;
					}
				}
				if (first)
				{
					points += d1;
					second = true;
					first = false;
				}
			} break;
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
	} while (1);
	return points;
}*/