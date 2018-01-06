#include <list>
#include <iterator>
#include <vector>
#include <utility>
using namespace std;

struct Chance
{
	unsigned short type;
	unsigned value;
};

void Cycle_Check(vector<pair<unsigned, int>> v)
{
	for (auto i : v)
	{
		for (int j=(i+1); j<v.size; j++)
		{
			if (A[i]==A[j])
			{
				cout << "INFINITY" << endl;
				terminate();
			}
		}
	}
}

unsigned int try1(unsigned short d, unsigned int points,
	unsigned short CurPos, unsigned n,
	unsigned short* field, list<Chance> lChance)	
{
	list<Chance>::iterator it;
	vector<pair<unsigned, int>> Pos_and_Chance;
	Pos_and_Chance.push_back(make_pair(0,-1));
	if (d>n)
	{
		step = d%n;
		CurPos += step;
	} else CurPos += d;

	do
	{
		switch field[CurPos]
		{
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
						CurPos=0;
						points+=(n-CurPos);
					}break;
				}
				Pos_and_Chance.push_back(make_pair(CurPos,*it));
				advance(it, 1);
				if (it==CL.end())
				{
					CL.begin();
					Cycle_Check(Pos_and_Chance);
				}
			} break;
			case 0:
			{
				points += d;
				return points;	
			} break;	
		}
	} while (1);
	return points;
}
	

unsigned int try2(unsigned short d1, unsigned short d2, unsigned n,
 unsigned int points, unsigned short* field, unsigned short CurPos,
 list<Chance> CL)	
{
	bool first;
	bool second;
	bool secondAfterChance;
	list<Chance>::iterator it;
	vector<pair<unsigned, int>> Pos_and_Chance;
	Pos_and_Chance.push_back(make_pair(0,-1));

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
				Pos_and_Chance.push_back(make_pair(CurPos,-1));
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
				Pos_and_Chance.push_back(make_pair(CurPos,*it));
				advance(it, 1);
				if (it==CL.end())
				{
					CL.begin();
					Cycle_Check(Pos_and_Chance);
				}
			}
		}
	} while (1);
	return points;
}

unsigned int try3(unsigned short d1, unsigned short d2,
 unsigned short d3,  unsigned n,
 unsigned int points, unsigned short CurPos,
 unsigned short* field, list<Chance> CL)	
{
	bool first = true;
	bool second = false;
	bool third = false;
	bool thirdAfterChance = false;
	list<Chance>::iterator it;
	vector<pair<unsigned, int>> Pos_and_Chance;
	Pos_and_Chance.push_back(make_pair(0,-1));

	if (CurPos!=0)
	{
		first = false;
		second = false;
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
	} else
	{
		if (d1>n)
		{
			step = d1%n;
			CurPos += step;
		} else CurPos += d1;
	}
	Pos_and_Chance.push_back(make_pair(CurPos,-1));
	
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
				Pos_and_Chance.push_back(make_pair(CurPos,-1));
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
				Pos_and_Chance.push_back(make_pair(CurPos,*it));
				advance(it, 1);
				if (it==CL.end())
				{
					CL.begin();
					Cycle_Check(Pos_and_Chance);
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