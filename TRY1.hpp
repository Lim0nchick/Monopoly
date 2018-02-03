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
	unsigned short* field, list<pair<unsigned short, unsigned>> lChance)	
{
	list<pair<unsigned short, unsigned>>::iterator it=lChance.begin();
	vector<pair<unsigned, int>> Pos_and_Chance;
	Pos_and_Chance.push_back(make_pair(0,distance(lChance.begin(), it)));
	if (d>n)
	{
		CurPos -= (d%n);
	} else CurPos += d;
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
						CurPos=(it->second);
						if ((it->second)<CurPos)
							points+=(n-((it->second)-CurPos));
						else 
							points+=((it->second)-CurPos);
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
	
void try1p(unsigned short d, unsigned int points,
	unsigned short CurPos, unsigned n,
	unsigned short* field, list<pair<unsigned short, unsigned>> lChance, fstream res)	
{
	list<pair<unsigned short, unsigned>>::iterator it=lChance.begin();
	vector<pair<unsigned, int>> Pos_and_Chance;
	Pos_and_Chance.push_back(make_pair(0,distance(lChance.begin(), it)));
	if (d>n)
	{
		CurPos -= (d%n);
	} else CurPos += d;
	res << d << " is First dice." << endl;
	res << "Go to " << CurPos <<", it's " << field[CurPos] << endl; 
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
						res << "Chance: forward on " << it->second << " fields to " << CurPos << endl;
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
						res << "Chance: back on " << it->second << " fields to " << CurPos << endl;
					} break;
					
					case 3:
					{
						CurPos=(it->second);
						if ((it->second)<CurPos)
							points+=(n-((it->second)-CurPos));
						else 
							points+=((it->second)-CurPos);
						res << "Chance: forward to " << CurPos << endl;
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
				res << "finish: " << points << "steps";
				res.close();
				return;	
			} break;	
		}
	} while (1);
	return;
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
						CurPos=(it->second);
						if ((it->second)<CurPos)
							points+=(n-((it->second)-CurPos));
						else 
							points+=((it->second)-CurPos);
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

void try2p(unsigned short d1, unsigned short d2, unsigned n,
 unsigned int points, unsigned short* field, unsigned short CurPos,
 list<pair<unsigned short, unsigned>> lChance, fstream res)	
{
	bool first;
	bool second;
	bool secondAfterChance;
	list<pair<unsigned short, unsigned>>::iterator it=lChance.begin();
	vector<pair<unsigned, int>> Pos_and_Chance;
	Pos_and_Chance.push_back(make_pair(0,distance(lChance.begin(), it)));

	unsigned short D1;
	res >> D1;
	if (D1==d1)
	{
		res.close();
		res.open("result.txt", ios::out | ios::app);
	}
	else
	{
		fstream res("result.txt", ios::out); // Cтерли данные в файле
		res.close();
		fstream res("result.txt");
		try1p(D1, 0,0,(n-1),field, lChance, res);
		res.open("result.txt", ios::out | ios::app);
	}
	res << d2 << " is Second dice." << endl;
	 
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
	res << "Go to " << CurPos <<", it's " << field[CurPos] << endl;
	
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
					res << "finish: " << points << "steps";
					res.close();
					return;
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
					res << "Go to " << CurPos <<", it's " << field[CurPos] << endl;
					if (field[CurPos] == 0)
					{
						points += d2;
						res.close();
						return;
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
						res << "Chance: forward on " << it->second << " fields to " << CurPos << endl;
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
						res << "Chance: back on " << it->second << " fields to " << CurPos << endl;
					} break;
					
					case 3:
					{
						CurPos=(it->second);
						if ((it->second)<CurPos)
							points+=(n-((it->second)-CurPos));
						else 
							points+=((it->second)-CurPos);
						res << "Chance: forward to " << CurPos << endl;
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
	//cout << "CurPos = " << CurPos << endl;
	//cout << "field[CurPos] = " << field[CurPos] << endl;
	if (CurPos==(n+1)) CurPos = 0;
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
						CurPos=(it->second);
						if ((it->second)<CurPos)
							points+=(n-((it->second)-CurPos));
						else 
							points+=((it->second)-CurPos);
					} break;
				}
				Pos_and_Chance.push_back(make_pair(CurPos,distance(lChance.begin(), it)));
				advance(it, 1);
				if (it==lChance.end())
				{
					it=lChance.begin();
					Cycle_Check(Pos_and_Chance);
				}
	//			cout << "Chance case END" << endl;
			} break;
		}
		//if (CurPos>=20) CurPos = 0;
	} while (1);
	return points;
}

void try3p(unsigned short d1, unsigned short d2,
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

	unsigned short D1,D2;
	res >> D1;
	res >> D2;
	if (D1==d1 && D2==d2)
	{
		res.close();
		res.open("result.txt", ios::out | ios::app);
		res << d3 << endl;
	}
	else
	{
		fstream res("result.txt", ios::out); // Cтерли данные в файле
		res.close();
		fstream res("result.txt", ios::out | ios::app);
		res << D1 << endl;
		res << d2 << endl;
		try1p(D1, 0,0,(n-1),field, lChance, res);
		res.open("result.txt", ios::out | ios::app);
	}


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
	//cout << "CurPos = " << CurPos << endl;
	if (CurPos==(n+1)) CurPos = 0;
	//cout << "field[CurPos] = " << field[CurPos] << endl;
	do
	{
		if (CurPos==(n+1)) CurPos = 0;
		//cout << "CurPos = " << CurPos << endl;
		//cout << "field[CurPos] = " << field[CurPos] << endl;
		switch (field[CurPos])
		{
			case 0:
			{
				//cout << "Empty case begin" << endl;
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
	//			cout << "Empty case END" << endl;
			} break;

			case 1:
			{
			//	cout << "Chance case begin" << endl;
				switch (it->first)
				{
					case 1:
					{
						points+=(it->second);
						if ((it->second)>(n-CurPos))
						{
							CurPos += ((it->second)%(n-CurPos));
						} else CurPos += (it->second);
						cout << "forward on " << it->second << " fields to " << CurPos << endl;
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
						cout << "back on " << it->second << " fields to " << CurPos << endl;

					} break;
					
					case 3:
					{
						CurPos=(it->second);
						if ((it->second)<CurPos)
							points+=(n-((it->second)-CurPos));
						else 
							points+=((it->second)-CurPos);
						cout << "forward to " << CurPos << endl;

					} break;
				}
				Pos_and_Chance.push_back(make_pair(CurPos,distance(lChance.begin(), it)));
				advance(it, 1);
				if (it==lChance.end())
				{
					it=lChance.begin();
					Cycle_Check(Pos_and_Chance);
				}
	//			cout << "Chance case END" << endl;
			} break;
		}
		//if (CurPos>=20) CurPos = 0;
	} while (1);
	return points;
}