#include <fstream>
#include <iostream>
#include "ThreadPool.h"
#include <future>
#include <thread>
#include <vector>
#include "TRY1.hpp"
#include <list>
#include <iterator>
using namespace std;



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
		cout << field[CurPos];
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
	cout << "\n\n";
	Map.close();

	//vector<pair<unsigned, list<pair<unsigned short, unsigned>>::iterator>> Pos_and_Chance;

	//unsigned short D1=0, D2=0, D3=0;
	fstream res;
	unsigned* r1;	
	r1=new unsigned[9];
	unsigned int max = 0;
	for (auto i=0; i<9; i++)
	{
		r1[i] = try1((i+3), 0,0,(n-1),field, lChance);
		cout << r1[i] << "\t";
		if (max < r1[i])
		{
			max = r1[i];
			//D1 = i+3;
			//Pos_and_Chance = Pos_and_Chance1((i+3), 0,0,n,field, lChance) // ТРЭК 
			res.open("result.txt");
			res << (i+3) << endl;
			try1p((i+3), 0,0,(n-1),field, lChance, res);
			res.open("result.txt", ios::out | ios::app);
			res << "The longest move is " << max << "." << endl;
		}
	}
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
				res.open("result.txt");
 				unsigned short D1;
				res >> D1;
				res.close();
				res.open("result.txt", ios::out);
				res << D1 << endl << (d2+3) << endl;
				res.close();
				res.open("result.txt", ios::out | ios::app);
				try1p(D1, 0,0,(n-1),field, lChance, res);
				res.open("result.txt", ios::out | ios::app);
				try2p(D1, (d2+3),(n-1), 0, field, 0, lChance, res);
				res.open("result.txt", ios::out | ios::app);
				res << "The longest move is " << max << "." << endl;
 			}
 			cout << r2[d1][d2] << "\t"; 
 		}
 		cout << endl;
 		cout << endl;
  	}
 	cout << "r2 completed" << endl;
 	
 	int D1,D2,D3;
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
 				unsigned short D1,D2,D3;
				res >> D1;
				res >> D2;
				D3=d3;
				res.open("result.txt", ios::out);
				res.close();
				res.open("result.txt", ios::out | ios::app);
				res << D1 << endl;
				res << D2 << endl;
				res << d3 << endl;
				try1p(D1, 0,0,(n-1),field, lChance, res);
				res.open("result.txt", ios::out | ios::app);
				try2p(D1, (d2+3),(n-1), 0, field, 0, lChance, res);
				res.open("result.txt", ios::out | ios::app);
				try3p(D1, (d2%12),d3, (n-1), 0, 0, field, lChance, res);
				res.open("result.txt", ios::out | ios::app);
				res << "The longest move is " << max << "." << endl;
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
 	cout << "D1 = " << D1 << endl;
 	cout << "D2 = " << D2 << endl;
 	cout << "D3 = " << D3 << endl;
 	


 	//cout << "Print track in result.dat, please wait...";
 	//print_result(D1, D2, D3, max); // underfined
 	//cout << "Complete." << endl;
 	//delete r1; delete r2; //delete r3;
	//system("pause"); // for windows-family OSs
	getchar(); // выступает в роли аналога "system("pause");"
	return 0;
}