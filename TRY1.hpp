#include <list>
#include <iterator>
#include <vector>
#include <utility>
#include <fstream>
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
	unsigned short* field, list<pair<unsigned short, unsigned>> lChance, bool print)	
{
	fstream res;
	if (print)
	{
		res.open("result.txt", ios::out);
		res.close();
		res.open("result.txt", ios::out | ios::app);
		res << d << " is First dice." << endl;
	}
	list<pair<unsigned short, unsigned>>::iterator it=lChance.begin();
	vector<pair<unsigned, int>> Pos_and_Chance;
	Pos_and_Chance.push_back(make_pair(0,distance(lChance.begin(), it)));
	if (d>n)
	{
		CurPos -= (d%n);
	} else CurPos += d;
	points += d;
	if(print)
	{
		res << "Go to " << CurPos <<", it's " << field[CurPos] << endl;
		res << "points += " << d << " = " << points << endl; 
	}

	if (CurPos==(n+1)) CurPos = 0;
	do
	{
		if (CurPos==(n+1)) CurPos = 0;
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
						if (print)
						{
							res << "Chance: forward on " << it->second << " fields to " << CurPos << endl;
							res << "points += " << it->second << " = " << points << endl;
							res << "It's field is " << field[CurPos] << endl; 
						}
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
						if (print)
						{
							res << "Chance: back on " << it->second << " fields to " << CurPos << endl;
							res << "points -= " << it->second << " = " << points << endl;
							res << "It's field is " << field[CurPos] << endl;
						}
					} break;
					
					case 3:
					{
						if (print)
							res << "Chance: forward to " << it->second << endl;
						if ((it->second)<CurPos)
						{
							points+=(n+1-((it->second)-CurPos));
							if (print)
								res << "points += " << (n+1-((it->second)-CurPos)) << " = " << points << endl;
						}
						else 
						{
							points+=((it->second)-CurPos);
							if(print)
								res << "points += " << ((it->second)-CurPos) << " = " << points << endl;
						}
						CurPos=(it->second);
						if(print)
							res << "It's field is " << field[CurPos] << endl;
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
				if (print)
				{
					res << endl;
					res << points << " points" << endl;
					res.close();
				}
				fstream iter;
				iter.open("iter.dat");
				iter << distance(lChance.begin(), it);
				iter.close();
				return points;	
			} break;	
		}
	} while (1);
	return points;
}

unsigned int try2(unsigned short d1, unsigned short d2, unsigned n,
 unsigned int points, unsigned short* field, unsigned short CurPos,
 list<pair<unsigned short, unsigned>> lChance, bool print)	
{
	fstream res;
	if (print)
	{
		res.open("result.txt", ios::out | ios::app);
		res << d2 << " is Second dice." << endl;
	}
	bool first;
	bool second;
	bool secondAfterChance;
	list<pair<unsigned short, unsigned>>::iterator it=lChance.begin();
	vector<pair<unsigned, int>> Pos_and_Chance;
	Pos_and_Chance.push_back(make_pair(0,distance(lChance.begin(), it)));
	fstream iter;
	if (points!=0)
	{
		iter.open("iter.dat");
		unsigned number;
		iter >> number;
		for (auto i=0; i<number; i++)
			advance(it,1);
		iter.close();
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
		if (print)
			unsigned a = try1(d1, 0,0,(n-1),field, lChance, true);
	} else
	{
		if (d1>n)
		{
			CurPos += (d1%n);
		} else CurPos += d1;
		points += d1;
		if (print)
			res << "points += " << d1 << " = " << points << " (by First dice)" << endl;
	}

	if (CurPos==(n+1)) CurPos = 0;
	do
	{
		if (CurPos==n) CurPos = 0;
		switch (field[CurPos])
		{
			case 0:
			{
				if (secondAfterChance)
				{
					points += d2;
					if (print)
					{
						res << "points += " << d2 << " = " << points << " (by Second dice)" << endl;
						res << points << " points" << endl; 
						res.close();
					}
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
					if(print)
					{
						res << "Go to " << CurPos <<", it's " << field[CurPos] << endl;
					}
					if (field[CurPos] == 0)
					{
						points += d2;
						iter.open("iter.dat");
						iter << distance(lChance.begin(), it);
						iter.close();
						if (print)
						{
							res << "points += " << d2 << " = " << points << endl << endl;
							res << points << " points" << endl; 
							res.close();
						}
						return points;
					}
				}
				if (first)
				{
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
						if (print)
						{
							res << "Chance: forward on " << it->second << " fields to " << CurPos << endl;
							res << "points += " << it->second << " = " << points << endl;
							res << "It's field is " << field[CurPos] << endl; 
						}
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
						if (print)
						{
							res << "Chance: back on " << it->second << " fields to " << CurPos << endl;
							res << "points -= " << it->second << " = " << points << endl;
							res << "It's field is " << field[CurPos] << endl;
						}
					} break;
					
					case 3:
					{
						if (print)
							res << "Chance: forward to " << it->second << endl;
						if ((it->second)<CurPos)
						{
							points+=(n+1-((it->second)-CurPos));
							if (print)
								res << "points += " << (n+1-((it->second)-CurPos)) << " = " << points << endl;
						}
						else 
						{
							points+=((it->second)-CurPos);
							if(print)
								res << "points += " << ((it->second)-CurPos) << " = " << points << endl;
						}
						CurPos=(it->second);
						if(print)
							res << "It's field is " << field[CurPos] << endl;
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
 unsigned short* field, list<pair<unsigned short, unsigned>> lChance, bool print, unsigned* r1)	
{
	fstream res;
	if (print)
	{
		res.open("result.txt", ios::out | ios::app);
		res << d3 << " is Third dice." << endl;
	}
	bool first = true;
	bool second = false;
	bool third = false;
	bool thirdAfterChance = false;
	list<pair<unsigned short, unsigned>>::iterator it=lChance.begin();
	vector<pair<unsigned, int>> Pos_and_Chance;
	Pos_and_Chance.push_back(make_pair(0,distance(lChance.begin(), it)));
	fstream iter;
	if (points!=0)
	{
		iter.open("iter.dat");
		unsigned number;
		iter >> number;
		for (auto i=0; i<number; i++)
			advance(it,1);
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
		if (print)
		{
			if ((d1 == 4) || (d1 == 6) || (d1 == 8) || (d1 == 10))
				unsigned a = try2(d1, (d2+3),(n-1), (r1[d1-3]), field, ((r1[d1-3])%n), lChance, true);
			else
				unsigned a = try2(d1, (d2+3),(n-1), 0, field, 0, lChance, true);
		}
	} else
	{
		if (d1>n)
		{
			CurPos += (d1%n);
		} else CurPos += d1;
		points += d1;
		if (print)
			res << "points += " << d1 << " = " << points << "(by First dice)" << endl;
	}
	//cout << "CurPos = " << CurPos << endl;
	//cout << "field[CurPos] = " << field[CurPos] << endl;
	if (CurPos==(n+1)) CurPos = 0;
	if (print)
		res << "Go to " << CurPos <<", it's " << field[CurPos] << endl;
	do
	{
		if (CurPos==(n+1)) CurPos = 0;
	//	cout << "CurPos = " << CurPos << endl;
		//cout << "field[CurPos] = " << field[CurPos] << endl;
		switch (field[CurPos])
		{
			case 0:
			{
	//			cout << "Empty case begin" << endl;
				if (thirdAfterChance)
				{
					points += d3;
					iter.open("iter.dat");
					iter << distance(lChance.begin(), it);
					iter.close();
					if (print)
					{
						res << "points += " << d3 << " = " << points << endl;
						res << points << " points" << endl;
						res.close();
					}
					fstream max;
					max.open("max.dat", ios::out | ios::app);
					max << "Max = " << points << endl;
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
						if (print)
						{
							res << "points += " << d3 << " = " << points << " (by Third dice)" << endl;
							res << points << " points" << endl;
							res.close();
						}
						iter.open("iter.dat");
						iter << distance(lChance.begin(), it);
						iter.close();
						fstream max;
						max.open("max.dat", ios::out | ios::app);
						max << "Max = " << points << endl;
						return points;
					}
				}
				if (second)
				{
					points += d2;
					if (print)
						res << "points += " << d2 << " = " << points << " (by Second dice)" << endl;
					second = false;
					third = true;
					if ((CurPos+d2)>n)
						CurPos -= (n-d2);
					else
						CurPos += d2;
					if (print)
						res << "Go to: " << CurPos << " it's " << field[CurPos] << " (by Second dice)" << endl;
				}
				if (first)
				{
					second = true;
					first = false;
				}
				Pos_and_Chance.push_back(make_pair(CurPos,distance(lChance.begin(), it)));
	//			cout << "Empty case END" << endl;
			} break;

			case 1:
			{
	//			cout << "Chance case begin" << endl;
				switch (it->first)
				{
					case 1:
					{	
						points+=(it->second);
						if ((it->second)>(n-CurPos))
						{
							CurPos += ((it->second)%(n-CurPos));
						} else CurPos += (it->second);
						if (print)
						{
							res << "Chance: forward on " << it->second << " fields to " << CurPos << endl;
							res << "points += " << it->second << " = " << points << endl;
							res << "It's field is " << field[CurPos] << endl; 
						}
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
						if (print)
						{
							res << "Chance: back on " << it->second << " fields to " << CurPos << endl;
							res << "points -= " << it->second << " = " << points << endl;
							res << "It's field is " << field[CurPos] << endl;
						}
					} break;
					
					case 3:
					{
						if (print)
							res << "Chance: forward to " << it->second << endl;
						if ((it->second)<CurPos)
						{
							points+=(n+1-((it->second)-CurPos));
							if (print)
								res << "points += " << (n+1-((it->second)-CurPos)) << " = " << points << endl;
						}
						else 
						{
							points+=((it->second)-CurPos);
							if(print)
								res << "points += " << ((it->second)-CurPos) << " = " << points << endl;
						}
						CurPos=(it->second);
						if(print)
							res << "It's field is " << field[CurPos] << endl;
					} break;
				}
		//if (CurPos>=20) CurPos = 0;
	} while (1);
	return points;
}