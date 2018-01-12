#include <fstream>
#include <iostream>
//#include "ThreadPool.h"
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

	unsigned* r1;	
	r1=new unsigned[9];

	unsigned int max = 0;
	for (auto i=0; i<9; i++)
	{
		r1[i] = try1((i+3), 0,0,n,field, lChance);
		cout << i  << " :: " << r1[i] << endl;
		if (max < r1[i])
			max = r1[i];
	}
	
 	unsigned** r2;
 	r2 = new unsigned*[14];
cout << "r1 completed" << endl;

 	for (unsigned short d1=2; d1<14; d1+=2)
 	{
 		r2[d1]=new unsigned[9];
 		for (unsigned short d2 = 0; d2<9; d2++)
 		{
 			cout << "1" << endl;
 			if ((d1 == 4) || (d1 == 6) || (d1 == 8) || (d1 == 10))
				r2[d1][d2] = try2(d1, (d2+3),0, n, field, ((r1[d1-3])%n), lChance);

			else 
				r2[d1][d2] = try2(d1, (d2+3),0, n, field, 0, lChance);
			cout << "return to main" << endl;
 			if (max < r2[d1][d2])
 				max=r2[d1][d2];
 		}
 	}
 	cout << "r2 completed" << endl;
 	
 	unsigned** r3;
 	r3 = new unsigned*[13];

 	for (unsigned short d3 = 2; d3<13; d3++)
 	{

 		for (unsigned short d2 = 2; d2<14; d2+=2)
 		{
			if (d2 == 4 || d2 == 6 || d2 == 8 || d2 == 10)
				r3[d3][d2] = try3(2, d2,d3, 0, ((r2[2][d2])%n), n, field, lChance);
			else
				r3[d3][d2] = try3(2, d2,d3, 0, 0, n, field, lChance);
			if (max < r3[d3][d2])
 				max=r3[d3][d2];
 		}
		for (unsigned short d2 = 2; d2<14; d2+=2)
		{
			if (d2 == 4 || d2 == 6 || d2 == 8 || d2 == 10)
				r3[d3][d2+12] = try3(4, d2,d3, 0, ((r2[4][d2])%n), n, field, lChance);
			else
				r3[d3][d2+12] = try3(4, d2,d3, 0, 0, n, field, lChance);
			if (max < r3[d3][d2+12])
 				max=r3[d3][d2+12];
		}
		for (unsigned short d2 = 2; d2<14; d2+=2)
		{
			if (d2 == 4 || d2 == 6 || d2 == 8 || d2 == 10)
				r3[d3][d2+24] = try3(6, d2,d3, 0, ((r2[6][d2])%n), n, field, lChance);
			else
				r3[d3][d2+24] = try3(6, d2,d3, 0, 0, n, field, lChance);
			if (max < r3[d3][d2+24])
 				max=r3[d3][d2+24];
		}
		for (unsigned short d2 = 2; d2<14; d2+=2)
		{
			if (d2 == 4 || d2 == 6 || d2 == 8 || d2 == 10)
				r3[d3][d2+36] = try3(8, d2,d3, 0, ((r2[8][d2])%n), n, field, lChance);
			else
				r3[d3][d2+36] = try3(8, d2,d3, 0, 0, n, field, lChance);
			if (max < r3[d3][d2+36])
 				max=r3[d3][d2+36];
		}
		for (unsigned short d2 = 2; d2<14; d2+=2)
		{
			if (d2 == 4 || d2 == 6 || d2 == 8 || d2 == 10)
				r3[d3][d2+48] = try3(10, d2,d3, 0, ((r2[10][d2])%n), n, field, lChance);
			else
				r3[d3][d2+48] = try3(10, d2,d3, 0, 0, n, field, lChance);
			if (max < r3[d3][d2+48])
 				max=r3[d3][d2+48];
		}
 		for (unsigned short d2 = 2; d2<14; d2+=2)
 		{
 			if (d2 == 4 || d2 == 6 || d2 == 8 || d2 == 10)
				r3[d3][d2+60] = try3(12, d2,d3, 0, ((r2[12][d2])%n), n, field, lChance);
			else
				r3[d3][d2+60] = try3(12, d2,d3, 0, 0, n, field, lChance);
 			if (max < r3[d3][d2+60])
 				max=r3[d3][d2+60];
 		}
 	}

 	cout << "The longest move is " << max << "." << endl; 


	//system("pause"); // for windows-family OSs
	getchar(); // выступает в роли аналога "system("pause");"
	return 0;
}