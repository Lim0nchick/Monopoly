#include <list>
#include <iterator>
#include <vector>
#include <utility>
#include <fstream>
using namespace std;

void Cycle_Check(vector<pair<unsigned, int> > v)
{
	vector<pair<unsigned, int> >::iterator it;
	for (it=v.begin(); it!=v.end(); it++)
	{
		vector<pair<unsigned, int> >::iterator jt;
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

unsigned try1(unsigned short d1, unsigned short d2,
 unsigned short d3,  unsigned n,
 unsigned short* field, list<pair<unsigned short, unsigned> > lChance, bool print)
{
	unsigned CurPos = 0;
	unsigned points = 0;
	fstream res;
	if (print)
		res.open("result.txt", ios::out | ios::app);
	bool first = true;
	bool second = false;
	bool third = false;
	bool thirdAfterChance = false;
	
	list<pair<unsigned short, unsigned> >::iterator it=lChance.begin();
	vector<pair<unsigned, int> > Pos_and_Chance;
	Pos_and_Chance.push_back(make_pair(0,distance(lChance.begin(), it)));
	if (print)
		res << "From " << CurPos;
	if (d1>n)
		CurPos += (d1%n);
	else CurPos += d1;
	points += d1;
	if (CurPos==n) CurPos = 0;
	if (print)
	{
		res << " Go to " << CurPos <<", it's " << field[CurPos] << endl;
		res << "points += " << d1 << " = " << points << "(by First dice)" << endl << endl;
	}
	do
	{
		res << "CurPos = " << CurPos << "\tpoints = " << points << endl << endl;
		if (CurPos==n) CurPos = 0;

		switch(field[CurPos])
		{
			case 0:
			{
				if (thirdAfterChance)
				{
					if (print)
						res.close();
					return points;
				}
				if (third)
				{
					if (print)
						res << "From " << CurPos;
					if ((CurPos+d3)>n)
						CurPos -= (n-d3);
					else
						CurPos += d3;
					third = false;
					points += d3;
					if(print)
					{
						res << " Go to " << CurPos << " it's " << field[CurPos] << endl;
						res << "points += " << d3 << " = " << points << " (by Third dice)" << endl;
					}
					if (field[CurPos] == 0)
					{
						res.close();
						return points;
					} else
					{
						third = false;
						thirdAfterChance = true;
					}
				}
				if (second)
				{
					points += d2;
					if (print)
						res << "points += " << d2 << " = " << points << " (by Second dice)" << endl << "From " << CurPos;
					second = false;
					if (d2%2==0)
						third = true;
					if ((CurPos+d2)>n)
						CurPos -= (n-d2);
					else
						CurPos += d2;
					if (print)
						res << " Go to: " << CurPos << " it's " << field[CurPos] << " (by Second dice)" << endl << endl;
				}
				if (first)
				{
					if ((d1%2)==0)
						second = true;
					first = false;
				}
				if ((field[CurPos]==0) && ((d1%2)!=0) && (first == false))
				{
					if ((field[CurPos]==0) && ((d2%2)!=0) && (second == false) && (first == false))
					{
						if ((field[CurPos]==0) && ((d3%2)!=0) && (third == false) && (second == false) && (first == false))
						{
							if (print)
								res.close();
							return points;
						}
					}
				}
			Pos_and_Chance.push_back(make_pair(CurPos,distance(lChance.begin(), it)));
			} break;

			case 1:
			{
				switch (it->first)
				{
					case 1:
					{
						points += it->second;
						if (((it->second)%n)>(n-CurPos))
							CurPos=((it->second)%n)-(n-CurPos);
						else CurPos += ((it->second)%n);
					} break;
					case 2:
					{
						if (((it->second)%n)>CurPos)
							CurPos = (n-((it->second)%n-CurPos));
						else CurPos -= ((it->second)%n);
						if ((it->second)>points)
							points = 0;
						else
							points -= (it->second);
						if (print)
						{
							res << "Chance: back on " << it->second << " fields to " << CurPos << endl;
							res << "points -= " << it->second << " = " << points << endl;
							res << "It's field is " << field[CurPos] << endl << endl;
						}
					} break;
					case 3:
					{
						if (print)
							res << "Chance: forward to " << it->second << endl;
						if ((it->second)<CurPos)
						{
							points += (n-(CurPos-(it->second)));
							if (print)
								res << "points += " << (n-(CurPos-(it->second))) << " = " << points << endl;
						} else
						{
							points+=((it->second)-CurPos);
							if(print)
								res << "points += " << ((it->second)-CurPos) << " = " << points << endl;
						}
						CurPos=(it->second);
						if(print)
							res << "It's field is " << field[CurPos] << endl << endl;
					} break;
				}
				Pos_and_Chance.push_back(make_pair(CurPos,distance(lChance.begin(), it)));
				advance(it, 1);
				if (it==lChance.end())
				{
					it=lChance.begin();
					Cycle_Check(Pos_and_Chance);
				}
				
				//if ((field[CurPos]==0) && ((d2%2)!=0) && (second == false) && (first == false))
			} break;
		}
	} while(1);
}