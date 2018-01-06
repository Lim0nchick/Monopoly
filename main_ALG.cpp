#include <fstream>
#include <iostream>
#include "ThreadPool.h"
#include <vector>
#include "TRY1.hpp"
#include <list>
#include <iterator>

using namespace std;



int main()
{
	//srand(time(0));

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
	//stack<unsigned short> sChance;
	unsigned short ChanceStackSize;
	list<Chance> CL;
	Map >> ChanceStackSize;
	for (auto i = 0; i<ChanceStackSize; i++)	
	{
		p = new Chance;
		unsigned short _type, _val;
		Map >> _type;	Map >> _val;
		p-> _type;		p-> _val;
		CL.push_back(p);
		cout << field[CurPos];
	}
	cout << "\n\n";
	Map.close();

	ThreadPool pool;

	vector<unsigned int> r;
	r[0] = pool.runAsync<unsigned int>(&try1,3, 0,0,n,field, CL);
	r[1] = pool.runAsync<unsigned int>(&try1,4, 0,0,n,field, CL);
	r[2] = pool.runAsync<unsigned int>(&try1,5, 0,0,n,field, CL);
	r[3] = pool.runAsync<unsigned int>(&try1,6, 0,0,n,field, CL);
	r[4] = pool.runAsync<unsigned int>(&try1,7, 0,0,n,field, CL);
	r[5] = pool.runAsync<unsigned int>(&try1,8, 0,0,n,field, CL);
	r[6] = pool.runAsync<unsigned int>(&try1,9, 0,0,n,field, CL);
	r[7] = pool.runAsync<unsigned int>(&try1,10,0,0,n,field, CL);
	r[8] = pool.runAsync<unsigned int>(&try1,11,0,0,n,field, CL);

	unsigned int max = r[0];
	for (unsigned short i=1; i<9; i++)
	{
		if (max < r[i])
			max = r[i];
	}

	delete pool;
 	ThreadPool pool;

 	//unsigned int* r = new unsigned int[9];
 	vector<vector<unsigned int>> r1; // Проверить корректность объявления двумерного вектора

 	for (unsigned short d1=2; d2<14; d2+=2)
 	{
 		for (unsigned short d2 = 0; d2<9; d2++)
 		{
 			if (d1 == 4 || d1 == 6 || d1 == 8 || d1 == 10)
			r1[d1][d2]=pool.runAsync<unsigned int>(&try2,d1, d2+3,0, n, field, r[d1-3]%n, CL);
			else 
			r1[d1][d2]=pool.runAsync<unsigned int>(&try2,d1, d2+3,0, n, field, 0, CL);
 			if (max < r1[d1][d2])
 				max=r1[d1][d2];
 		}
 	}

 	delete pool;
 	ThreadPool pool;
 	
 	vector<vector<unsigned int>> r2; // Проверить корректность объявления двумерного вектора

 	for (unsigned short d3 = 2; d3<13; d3++)
 	{
 		for (unsigned short d2 = 2; d2<14; d2+=2)
 		{
			if (d2 == 4 || d2 == 6 || d2 == 8 || d2 == 10)
				r2[d3][d2]=pool.runAsync<unsigned int>(&try3,2, d2,d3, 0, r1[2][d2]%n, n, field, CL);
			else
				r2[d3][d2]=pool.runAsync<unsigned int>(&try3,2, d2,d3, 0, 0, field, CL);
			if (max < r2[d3][d2])
 				max=r2[d3][d2];
 		}
		for (unsigned short d2 = 2; d2<14; d2+=2)
		{
			if (d2 == 4 || d2 == 6 || d2 == 8 || d2 == 10)
				r2[d3][d2+12]=pool.runAsync<unsigned int>(&try3,4, d2,d3, 0, r1[4][d2]%n, n, field, CL);
			else
				r2[d3][d2+12]=pool.runAsync<unsigned int>(&try3,4, d2,d3, 0, 0, n, field, CL);
			if (max < r2[d3][d2+12])
 				max=r2[d3][d2+12];
		}
		for (unsigned short d2 = 2; d2<14; d2+=2)
		{
			if (d2 == 4 || d2 == 6 || d2 == 8 || d2 == 10)
				r2[d3][d2+24]=pool.runAsync<unsigned int>(&try3,6, d2,d3, 0, r1[6][d2]%n, n, field, CL);
			else
				r2[d3][d2+24]=pool.runAsync<unsigned int>(&try3,6, d2,d3, 0, 0, n, field, CL);
			if (max < r2[d3][d2+24])
 				max=r2[d3][d2+24];
		}
		for (unsigned short d2 = 2; d2<14; d2+=2)
		{
			if (d2 == 4 || d2 == 6 || d2 == 8 || d2 == 10)
				r2[d3][d2+36]=pool.runAsync<unsigned int>(&try3,8, d2,d3, 0, r1[8][d2]%n, n, field, CL);
			else
				r2[d3][d2+36]=pool.runAsync<unsigned int>(&try3,8, d2,d3, 0, 0, n, field, CL);
			if (max < r2[d3][d2+36])
 				max=r2[d3][d2+36];
		}
		for (unsigned short d2 = 2; d2<14; d2+=2)
		{
			if (d2 == 4 || d2 == 6 || d2 == 8 || d2 == 10)
				r2[d3][d2+48]=pool.runAsync<unsigned int>(&try3,10, d2,d3, 0, r1[10][d2]%n, n, field, CL);
			else
				r2[d3][d2+48]=pool.runAsync<unsigned int>(&try3,10, d2,d3, 0, 0, n, field, CL);
			if (max < r2[d3][d2+48])
 				max=r2[d3][d2+48];
		}
 		for (unsigned short d2 = 2; d2<14; d2+=2)
 		{
 			if (d2 == 4 || d2 == 6 || d2 == 8 || d2 == 10)
				r2[d3][d2+60]=pool.runAsync<unsigned int>(&try3,12, d2,d3, 0, r1[12][d2]%n, n, field, CL);
			else
				r2[d3][d2+60]=pool.runAsync<unsigned int>(&try3,12, d2,d3, 0, 0, n, field, CL);
 			if (max < r2[d3][d2+48])
 				max=r2[d3][d2+48];
 		}
 	}

 	cout << "The longest move" << max << "." << endl; 

 	delete pool;
 	delete r;
 	delete r1;
 	delete r2;
	
	
	//system("pause"); // for windows-family OSs
	getchar(); // выступает в роли аналога "system("pause");"
	return 0;
}