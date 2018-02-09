#include <fstream>
#include <iostream>
#include <future>
#include <thread>
#include <vector>
#include "TRY.hpp"
#include <list>
#include <iterator>
#include <algorithm>
using namespace std;

int factorial(int a)
{
	if (a==0) return 1;
	return a*factorial(a-1);
}

bool checking_chance_dat(list<pair<unsigned short, unsigned>> lChance, unsigned css)
{
	fstream chance;
	chance.open("chance.dat");
	list<pair<unsigned short, unsigned>> buf;
	list<pair<unsigned short, unsigned>>::iterator bit, lit;
	bool* same=new bool[css];
	unsigned short i=0;
	unsigned short j=0;
	unsigned short k=0;
	for (k=0; k<css; k++)
		same[k]=false;
	k=0;
	do
	{
		for (j=0; j<(css*2); j++)
		{
			unsigned short type, value;
			chance >> type;
			chance >> value;
			buf.push_back(make_pair(type, value));
		}
		bit=buf.begin();
		for (lit=lChance.begin(); lit!=lChance.end(); lit++)
		{
			if ((lit->first == bit->first) && (lit->second == bit->second))
				same[i] = true;
			k++;
			bit++;
		}
	} while (!chance.eof());
	chance.close();
	for (k=0; k<css; k++)
	{
		if(same[k]==false)
			return false;
	}
	return true;
}

list<pair<unsigned short, unsigned>> reform_chances (list<pair<unsigned short, unsigned>> lChance, unsigned css)
{
	do
	{
		list<pair<unsigned short, unsigned>>::iterator lit;
		fstream chance;

		vector<pair<unsigned short, unsigned>> buf(css);
		vector<pair<unsigned short, unsigned>>::iterator vit=buf.begin();
		copy(lChance.begin(), lChance.end(), buf.begin());
		random_shuffle(buf.begin(), buf.end());
		copy(buf.begin(), buf.end(), lChance.begin());
		bool check=checking_chance_dat(lChance, css);
		if(!checking_chance_dat(lChance, css))
		{
			chance.open("chance.dat", ios::out | ios::app);
			for (lit=lChance.begin(); lit!=lChance.end(); lit++)
				chance << lit->first << endl << lit->second << endl;
			chance.close();
			return lChance;
		}
	} while (1);
	return lChance;
}


int main()
{
	unsigned short points = 0;
	unsigned short n;
		
	fstream Map;
	Map.open("Map.dat", ios::in);
	if(!Map) return 1; // Если ошибка открытия файла, то завершаем программу
	Map >> n;
	unsigned short* field = new unsigned short[n];
	unsigned short CurPos;
	for (CurPos=0; CurPos<n; CurPos++)
	{
		Map >> field[CurPos];
		//cout << field[CurPos];
	}
	unsigned short ChanceStackSize;
	list<pair<unsigned short, unsigned>> lChance;
	Map >> ChanceStackSize;
	for (auto i = 0; i<ChanceStackSize; i++)	
	{
		unsigned short type, value;
		Map >> type;
		Map >> value;
		lChance.push_back(make_pair(type, value));
	}
	//cout << "\n\n";
	Map.close();

	list<pair<unsigned short, unsigned>>::iterator lit;
	fstream chance;
	chance.open("chance.dat", ios::out);
	chance.close();
	chance.open("chance.dat");
	for (lit=lChance.begin(); lit!=lChance.end(); lit++)
	{
		chance << lit->first << endl << lit->second << endl;
	}
	unsigned int max = 0;
	int N=factorial(ChanceStackSize);
	fstream log;
	log.open("log.dat", ios::out | ios::app);
	
	cout << "Map load complete" << endl;

	for(auto i=0; i<N; i++)
	{
		//for (CurPos=0; CurPos<n; CurPos++)
			//cout << field[CurPos] << "  ";
		//cout << endl;
		//for (lit=lChance.begin(); lit!=lChance.end(); lit++)
			//cout << lit->first << endl << lit->second << endl;
		log << "i = " << i << endl;
		fstream res;
		unsigned*** r;
		r = new unsigned**[12];
		for (auto d1=0; d1<12; d1++)
		{
			r[d1]=new unsigned*[12];
			for(auto d2=0; d2<12; d2++)
			{
				r[d1][d2]=new unsigned[12];
				for(auto d3=0; d3<12; d3++)
				{
					r[d1][d2][d3]=try1((d1+1), (d2+1), (d3+1), n, field, lChance, false);
					if (max < r[d1][d2][d3])
	 				{
	 					max=r[d1][d2][d3];
	 					res.open("result.txt", ios::out);
	 					res.close();
	 					unsigned a = try1((d1+1), (d2+1), (d3+1), n, field, lChance, true);
	 					res.open("result.txt", ios::out | ios::app);
						res << "The longest move is " << max << "." << endl;
						res.close();
					}
					cout << r[d1][d2][d3] << "\t";
				}
				cout << endl;
			}
			cout << endl << endl;
		}
		cout << "The longest move is " << max << "." << endl;
 		fstream chance;
		chance.open("chance.dat");
 		for (lit=lChance.begin(); lit!=lChance.end(); lit++)
			chance << lit->first << endl << lit->second << endl;
 		lChance = reform_chances(lChance, ChanceStackSize);
 		chance.close();
 		delete r;
 		getchar();
	}


	//vector<pair<unsigned, list<pair<unsigned short, unsigned>>::iterator>> Pos_and_Chance;
	//ThreadPool pool;
	//vector<future<unsigned>> f1;
	//vector<unsigned> r1;




	getchar(); // выступает в роли аналога "system("pause");"
	return 0;
}