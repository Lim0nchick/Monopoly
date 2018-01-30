#include <list>
#include <iterator>
#include <vector>
#include <utility>
using namespace std;

void Cycle_Check(vector<pair<unsigned, int>> v)
{
	vector<pair<unsigned, int>>::iterator it;
	for (it=v.begin(); it!=v.end(); it++)
	{
		vector<pair<unsigned, int>>::iterator jt;
		for (jt=it; jt!=v.end(); jt++)
		{
			if (distance(v.begin(),jt) != distance(v.begin(),it))
			{
				if ((it->first == jt->first) && (it->second == jt->second))
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
	list<pair<unsigned short, unsigned>>::iterator it=lChance.begin();
	vector<pair<unsigned, int>> Pos_and_Chance;
	Pos_and_Chance.push_back(make_pair(0,distance(lChance.begin(), it)));
	if (d>n)
	{
		CurPos -= (n-d);
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
						if ((it->second)>(n-CurPos))
						{
							CurPos += ((it->second)%(n-CurPos));
						} else CurPos += (it->second);
					} break;

					case 2:
					{
						
						if ((it->second)>CurPos)
						{
							CurPos += (n-(it->second));
						} else CurPos -= (it->second);
						if ((it->second)>points)
							points = 0;
						else
							points-=(it->second);
					} break;
					
					case 3:
					{
						CurPos=0;
						points+=(n-CurPos);
					} break;
				}
				Pos_and_Chance.push_back(make_pair(CurPos,distance(lChance.begin(), it)));
				advance(it, 1);
				if (it==lChance.end())
				{
					it=lChance.begin();
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
	list<pair<unsigned short, unsigned>>::iterator it=lChance.begin();
	vector<pair<unsigned, int>> Pos_and_Chance;
	Pos_and_Chance.push_back(make_pair(0,distance(lChance.begin(), it)));

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
					if ((CurPos+d2)>n)
					{
						CurPos -= (n-d2);
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
				Pos_and_Chance.push_back(make_pair(CurPos,distance(lChance.begin(), it)));
			} break;

			case 1:
			{
				switch (it->first)
				{
					case 1:
					{
						points+=(it->second);
						if ((it->second)>(n-CurPos))
						{
							CurPos += ((it->second)%(n-CurPos));
						} else CurPos += (it->second);
					} break;
					case 2:
					{
						if ((it->second)>CurPos)
						{
							CurPos += (n-(it->second));
						} else CurPos -= (it->second);
						if ((it->second)>points)
							points = 0;
						else
							points-=(it->second);
					} break;
					
					case 3:
					{
						CurPos=0;
						points+=(n-CurPos);
					} break;
				}
				Pos_and_Chance.push_back(make_pair(CurPos,distance(lChance.begin(), it)));
				advance(it, 1);
				if (it==lChance.end())
				{
					it=lChance.begin();
					Cycle_Check(Pos_and_Chance);
				}
			}break;
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
	list<pair<unsigned short, unsigned>>::iterator it=lChance.begin();
	vector<pair<unsigned, int>> Pos_and_Chance;
	Pos_and_Chance.push_back(make_pair(0,distance(lChance.begin(), it)));

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
			} break;
		}
	} else
	{
		if (d1>n)
		{
			CurPos += (d1%n);
		} else CurPos += d1;
	}
	cout << "CurPos = " << CurPos << endl;
	cout << "field[CurPos] = " << field[CurPos] << endl;
	do
	{
		cout << "CurPos = " << CurPos << endl;
		//cout << "field[CurPos] = " << field[CurPos] << endl;
		switch (field[CurPos])
		{
			case 0:
			{
				cout << "Empty case begin" << endl;
				if (thirdAfterChance)
				{
					points += d3;
					return points;
				}
				if (third)
				{
					if ((CurPos+d3)>n)
					{
						CurPos -= (n-d3);
					} else
					{
						CurPos += d3;
						third = false;
						thirdAfterChance = true;
					}
					if (field[CurPos] == 0)
					{
						points += d3;
						return points;
					}
				}
				if (second)
				{
					points += d2;
					second = false;
					third = true;
					if ((CurPos+d2)>n)
						CurPos -= (n-d2);
					else
						CurPos += d2;
				}
				if (first)
				{
					points += d1;
					second = true;
					first = false;
				}
				Pos_and_Chance.push_back(make_pair(CurPos,distance(lChance.begin(), it)));
				cout << "Empty case END" << endl;
			} break;

			case 1:
			{
				cout << "Chance case begin" << endl;
				switch (it->first)
				{
					case 1:
					{
						points+=(it->second);
						if ((it->second)>(n-CurPos))
						{
							CurPos += ((it->second)%(n-CurPos));
						} else CurPos += (it->second);
					} break;

					case 2:
					{
						if ((it->second)>CurPos)
						{
							CurPos += (n-(it->second));
						} else CurPos -= (it->second);
						if ((it->second)>points)
							points = 0;
						else
							points-=(it->second);
					} break;
					
					case 3:
					{
						CurPos=0;
						points+=(n-CurPos);
					} break;
				}
				Pos_and_Chance.push_back(make_pair(CurPos,distance(lChance.begin(), it)));
				advance(it, 1);
				if (it==lChance.end())
				{
					it=lChance.begin();
					Cycle_Check(Pos_and_Chance);
				}
				cout << "Chance case END" << endl;
			} break;
		}
		//if (CurPos>=20) CurPos = 0;
	} while (1);
	return points;
}