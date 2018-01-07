#include <list>
#include <iterator>
#include <vector>
#include <utility>
using namespace std;

void Cycle_Check(vector<pair<unsigned, list<pair<unsigned short, unsigned>>::iterator>> v)
{
	vector<pair<unsigned, list<pair<unsigned short, unsigned>>::iterator>>::iterator it;
	for (it=v.begin(); it!=v.end(); it++)
	{
		vector<pair<unsigned, list<pair<unsigned short, unsigned>>::iterator>>::iterator jt;
		for (jt=it; jt!=v.end(); jt++)
		{
			if (jt!=it)
			{
				if (it->first == jt->first && it->second == jt->second)
				{
					cout << "The longest move is INFINITY." << endl;
					terminate();
				}
			}
		}
	}
}

unsigned int try1(unsigned short d, unsigned int points,
	unsigned short CurPos, unsigned n,
	unsigned short* field, list<pair<unsigned short, unsigned>> lChance)	
{
	list<pair<unsigned short, unsigned>>::iterator it;
	vector<pair<unsigned, list<pair<unsigned short, unsigned>>::iterator>> Pos_and_Chance;
	Pos_and_Chance.push_back(make_pair(0,it));
	if (d>n)
	{
		CurPos += (d%n);
	} else CurPos += d;

	do
	{
		switch (field[CurPos])
		{
			case 1:
			{
				switch (it->first)
				{
					case 1:
					{	
						points+=(it->second);
						if ((it->second)>n)
						{
							CurPos += ((it->second)%n);
						} else CurPos += (it->second);
					} break;

					case 2:
					{
						if ((it->second)>CurPos)
						{
							CurPos -= ((it->second)%n);
						} else CurPos -= (it->second);
						points-=(it->second);
					} break;
					
					case 3:
					{
						CurPos=0;
						points+=(n-CurPos);
					} break;
				}
				Pos_and_Chance.push_back(make_pair(CurPos,it));
				advance(it, 1);
				if (it==lChance.end())
				{
					lChance.begin();
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
 list<pair<unsigned short, unsigned>> lChance)	
{
	bool first;
	bool second;
	bool secondAfterChance;
	list<pair<unsigned short, unsigned>>::iterator it;
	vector<pair<unsigned, list<pair<unsigned short, unsigned>>::iterator>> Pos_and_Chance;
	Pos_and_Chance.push_back(make_pair(0,it));

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
			CurPos += (d1%n);
		} else CurPos += d1;
	}
	
	do
	{
		switch (field[CurPos])
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
						CurPos += (d2%n);
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
				Pos_and_Chance.push_back(make_pair(CurPos,it));
			} break;

			case 1:
			{
				switch (it->first)
				{
					case 1:
					{
						points+=(it->second);
						if ((it->second)>n)
						{
							CurPos += ((it->second)%n);
						} else CurPos += (it->second);
					} break;
					case 2:
					{
						if ((it->second)>CurPos)
						{
							CurPos -= ((it->second)%n);
						} else CurPos -= (it->second);
						points-=(it->second);
					} break;
					
					case 3:
					{
						CurPos=0;
						points+=(n-CurPos);
					} break;
				}
				Pos_and_Chance.push_back(make_pair(CurPos,it));
				advance(it, 1);
				if (it==lChance.end())
				{
					lChance.begin();
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
 unsigned short* field, list<pair<unsigned short, unsigned>> lChance)	
{
	bool first = true;
	bool second = false;
	bool third = false;
	bool thirdAfterChance = false;
	list<pair<unsigned short, unsigned>>::iterator it;
	vector<pair<unsigned, list<pair<unsigned short, unsigned>>::iterator>> Pos_and_Chance;
	Pos_and_Chance.push_back(make_pair(0,it));

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
			CurPos += (d1%n);
		} else CurPos += d1;
	}
	Pos_and_Chance.push_back(make_pair(CurPos,it));
	
	do
	{
		switch (field[CurPos])
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
						CurPos += (d3%n);
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
						CurPos += (d2%n);
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
				Pos_and_Chance.push_back(make_pair(CurPos,it));
			} break;

			case 1:
			{
				switch (it->first)
				{
					case 1:
					{
						points+=(it->second);
						if ((it->second)>n)
						{
							CurPos += ((it->second)%n);
						} else CurPos += (it->second);
					} break;

					case 2:
					{
						if ((it->second)>CurPos)
						{
							CurPos -= ((it->second)%n);
						} else CurPos -= (it->second);
						points-=(it->second);
					} break;
					
					case 3:
					{
						CurPos=0;
						points+=(n-CurPos);
					} break;
				}
				Pos_and_Chance.push_back(make_pair(CurPos,it));
				advance(it, 1);
				if (it==lChance.end())
				{
					lChance.begin();
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