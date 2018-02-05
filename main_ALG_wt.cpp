#include <fstream>
#include <iostream>
#include "ThreadPool.h"
#include <future>
#include <thread>
#include <vector>
#include "TRY1.hpp"
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
		//cout << "shuffling complete. Check" << endl;
		bool check=checking_chance_dat(lChance, css);
		//cout << "check = " << check << endl;
		if(!checking_chance_dat(lChance, css))
		{
			chance.open("chance.dat", ios::out | ios::app);
			for (lit=lChance.begin(); lit!=lChance.end(); lit++)
			{
				chance << lit->first << endl << lit->second << endl;
			}
			chance.close();
			//cout << "complete shufling chances and write to file" << endl;
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

	//vector<pair<unsigned, list<pair<unsigned short, unsigned>>::iterator>> Pos_and_Chance;
	for(auto i=0; i<N; i++)
	{
		log << "i = " << i << endl;
		//unsigned short D1=0, D2=0, D3=0;
		fstream res;
		unsigned* r1;	
		r1=new unsigned[9];
		for (auto i=0; i<9; i++)
		{
			r1[i] = try1((i+3), 0,0,(n-1),field, lChance);
			cout << r1[i] << "\t";
			if (max < r1[i])
			{
				max = r1[i];
				res.open("result.txt", ios::out | ios::app);
				res.close();
				//D1 = i+3;
				//Pos_and_Chance = Pos_and_Chance1((i+3), 0,0,n,field, lChance) // ТРЭК 
				//res.open("result.txt");
				//res << (i+3) << endl;
				try1p((i+3), 0,0,(n-1),field, lChance);
				res.open("result.txt", ios::out | ios::app);
				//res << "The longest move is " << max << "." << endl;
				res.close();
			}
		}
		cout << endl;
		cout << "Max is " << max << endl;
		cout << endl;
		cout << "r1 completed" << endl;
		cout << endl;
	 	unsigned** r2;
	 	r2 = new unsigned*[14];


	 	for (unsigned short d1=2; d1<14; d1+=2)
	 	{
	 		r2[d1]=new unsigned[9];
	 		for (unsigned short d2 = 0; d2<9; d2++)
	 		{
	 			if ((d1 == 4) || (d1 == 6) || (d1 == 8) || (d1 == 10))
					r2[d1][d2] = try2(d1, (d2+3),(n-1), (r1[d1-3]), field, ((r1[d1-3])%n), lChance);
				else 
					r2[d1][d2] = try2(d1, (d2+3),(n-1), 0, field, 0, lChance);
	 			if (max < r2[d1][d2])
	 			{
	 				max=r2[d1][d2];
	 				res.open("result.txt", ios::out);
	 				res.close();
					//res.open("result.txt", ios::out);
					//res << d1 << endl << (d2+3) << endl;
					//res.close();
					//res.open("result.txt", ios::out | ios::app);
					try1p(d1, 0,0,(n-1),field, lChance);
					res.close();
					//res.open("result.txt", ios::out | ios::app);
					try2p(d1, (d2+3),(n-1), 0, field, 0, lChance);
					res.close();
					res.open("result.txt", ios::out | ios::app);
					res << "The longest move is " << max << "." << endl;
					res.close();
	 			}
	 			cout << r2[d1][d2] << "\t"; 
	 		}
	 		cout << endl;
	 		cout << endl;
	  	}
	  	cout << "Max is " << max << endl;
	 	cout << "r2 completed" << endl;
	 	cout << endl << endl;
	 	
	 	unsigned** r3;
	 	r3 = new unsigned*[13];
		unsigned d1 = 2;
 		for (unsigned short d3 = 3; d3<12; d3++)
 		{
 			r3[d3]=new unsigned[76];
 			for (unsigned short d2 = 2; d2 < 76; d2+=2)
 			{
 				//cout << "d1 = " << d1 << endl;
 				//cout << "d2 = " << d2 << endl;
 				//cout << "d3 = " << d3 << endl;
 				//cout << "r2[d1][d2/12] = " << r2[d1][d2%12] << endl;
 				if (d1=14) d1=2;
 				if ((d2%12) == 4 || (d2%12) == 6 || (d2%12) == 8 || (d2%12) == 10)
 				{
 					//CurPos = (r2[d1][d2%12])%n;
 					//cout << "CurPos = " << CurPos << endl;
 					if (CurPos == 20) CurPos = 0;
					r3[d3][d2] = try3(d1, (d2%12),d3, (n-1), (r2[d1][d2%12]), CurPos, field, lChance);
					cout << r3[d3][d2] <<"\t";
	
 				}
				else
				{
					//CurPos = (r2[d1][d2%12])%n;
					//cout << "CurPos = " << CurPos << endl;
 					if (CurPos == 20) CurPos = 0;
					r3[d3][d2] = try3(d1, (d2%12),d3, (n-1), 0, 0, field, lChance);
				//	cout << "r3[" << d3 << "][" << d2 << "]" << endl;
					cout << r3[d3][d2] <<"\t";
				}
				if (max < r3[d3][d2])
				{
 					max = r3[d3][d2];
 					res.open("result.txt", ios::out);
 					res.close();
					res.open("result.txt", ios::out | ios::app);
					try1p(d1, 0,0,(n-1),field, lChance);
					res.close();
					//res.open("result.txt", ios::out | ios::app);
					try2p(d1, d2,(n-1), 0, field, 0, lChance);
					res.close();
					//res.open("result.txt", ios::out | ios::app);
					try3p(d1, (d2%12),d3, (n-1), 0, 0, field, lChance);
					res.close();
					res.open("result.txt", ios::out | ios::app);
					res << "The longest move is " << max << "." << endl;
					res.close();
				}
 				if (d2 == 12 || d2 == 24 || d2 == 36 || d2 == 48 || d2 == 60)
 					d1+=2;
 			}
 			d1=2;
 			cout << endl;
 			cout << endl;
 		}
 		cout << "r3 completed" << endl;
 		cout << "The longest move is " << max << "." << endl;
 		fstream chance;
		chance.open("chance.dat");
 		for (lit=lChance.begin(); lit!=lChance.end(); lit++)
		{	
			chance << lit->first << endl << lit->second << endl;
		}
 		lChance = reform_chances(lChance, ChanceStackSize);
 		
 		/*for (auto i=0; i<0; i++)
 			r1[i]=0;
 		for (auto d1=2; d1<14; d1+=2)
	 		for (unsigned short d2 = 0; d2<9; d2++)
	 			r2[d1][d2]=0;
	 	for (unsigned short d3 = 3; d3<12; d3++)
 			for (unsigned short d2 = 2; d2 < 76; d2+=2)
 				r3[d3][d2]=0;*/
 		delete r1;
 		delete r2;
 		delete r3;
 		getchar();
	}
	//system("pause"); // for windows-family OSs
	getchar(); // выступает в роли аналога "system("pause");"
	return 0;
}