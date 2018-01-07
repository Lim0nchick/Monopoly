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
	//stack<unsigned short> sChance;
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

	//ThreadPool pool;

	unsigned* r1;
	r1=new unsigned[9];
	/*r[0] = pool.runAsync<unsigned int>(&try1,3, 0,0,n,field, lChance);
	r[1] = pool.runAsync<unsigned int>(&try1,4, 0,0,n,field, lChance);
	r[2] = pool.runAsync<unsigned int>(&try1,5, 0,0,n,field, lChance);
	r[3] = pool.runAsync<unsigned int>(&try1,6, 0,0,n,field, lChance);
	r[4] = pool.runAsync<unsigned int>(&try1,7, 0,0,n,field, lChance);
	r[5] = pool.runAsync<unsigned int>(&try1,8, 0,0,n,field, lChance);
	r[6] = pool.runAsync<unsigned int>(&try1,9, 0,0,n,field, lChance);
	r[7] = pool.runAsync<unsigned int>(&try1,10,0,0,n,field, lChance);
	r[8] = pool.runAsync<unsigned int>(&try1,11,0,0,n,field, lChance);*/
	for (auto i=0; i<9; i++)
	{
		future<unsigned> f = async(try1,(i+3), 0,0,n,field, lChance);
		r1[i]=f.get();
	}
	/*future<unsigned> r1[0] = async(try1,3, 0,0,n,field, lChance);
	r1[0].get();
	future<unsigned> r1[1] = async(try1,4, 0,0,n,field, lChance);
	r1[1].get();
	future<unsigned> r1[2] = async(try1,5, 0,0,n,field, lChance);
	r1[2].get();
	future<unsigned> r1[3] = async(try1,6, 0,0,n,field, lChance);
	r1[3].get();
	future<unsigned> r1[4] = async(try1,7, 0,0,n,field, lChance);
	r1[4].get();
	future<unsigned> r1[5] = async(try1,8, 0,0,n,field, lChance);
	r1[5].get();
	future<unsigned> r1[6] = async(try1,9, 0,0,n,field, lChance);
	r1[6].get();
	future<unsigned> r1[7] = async(try1,10, 0,0,n,field, lChance);
	r1[7].get();
	future<unsigned> r1[8] = async(try1,11, 0,0,n,field, lChance);
	r1[8].get();
*/

	unsigned int max = r1[0];
	for (unsigned short i=1; i<9; i++)
	{
		if (max < r1[i])
			max = r1[i];
	}

	/*delete pool;
 	ThreadPool pool;*/

 	//unsigned int* r = new unsigned int[9];
 	vector<vector<unsigned int>> r2; // Проверить корректность объявления двумерного вектора

 	/*for (unsigned short d1=2; d2<14; d2+=2)
 	{
 		for (unsigned short d2 = 0; d2<9; d2++)
 		{
 			if (d1 == 4 || d1 == 6 || d1 == 8 || d1 == 10)
				r1[d1][d2]=pool.runAsync<unsigned int>(&try2,d1, d2+3,0, n, field, r[d1-3]%n, lChance);
			else 
				r1[d1][d2]=pool.runAsync<unsigned int>(&try2,d1, d2+3,0, n, field, 0, lChance);
 			if (max < r1[d1][d2])
 				max=r1[d1][d2];
 		}
 	}*/

 	for (unsigned short d1=2; d1<14; d1+=2)
 	{
 		for (unsigned short d2 = 0; d2<9; d2++)
 		{
 			if (d1 == 4 || d1 == 6 || d1 == 8 || d1 == 10)
 			{
				future<unsigned int> f = async(try1,d1, (d2+3),0, n, field, ((r1[d1-3])%n), lChance);
				r2[d1][d2]=f.get();
 			}
			else 
			{
				future<unsigned int> f = async(try2,d1, (d2+3,0), n, field, 0, lChance);
				r2[d1][d2]=f.get();
			}
 			if (max < r2[d1][d2])
 				max=r2[d1][d2];
 		}
 	}

 	/*delete pool;
 	ThreadPool pool;*/
 	
 	vector<vector<unsigned int>> r3; // Проверить корректность объявления двумерного вектора

 	for (unsigned short d3 = 2; d3<13; d3++)
 	{
 		for (unsigned short d2 = 2; d2<14; d2+=2)
 		{
			if (d2 == 4 || d2 == 6 || d2 == 8 || d2 == 10)
			{
				future<unsigned int> f = async(try3,2, d2,d3, 0, ((r2[2][d2])%n), n, field, lChance);
				r3[d3][d2]=f.get();
			}
			else
			{
				future<unsigned int> f = async(try3,2, d2,d3, 0, 0, field, lChance);
				r3[d3][d2]=f.get();
			}
			if (max < r3[d3][d2])
 				max=r3[d3][d2];
 		}
		for (unsigned short d2 = 2; d2<14; d2+=2)
		{
			if (d2 == 4 || d2 == 6 || d2 == 8 || d2 == 10)
			{
				future<unsigned int> f = async(try3,4, d2,d3, 0, ((r2[4][d2])%n), n, field, lChance);
				r3[d3][d2+12]=f.get();
			}
			else
			{
				future<unsigned int> f = async(try3,4, d2,d3, 0, 0, n, field, lChance);
				r3[d3][d2+12]=f.get();
			}
			if (max < r3[d3][d2+12])
 				max=r3[d3][d2+12];
		}
		for (unsigned short d2 = 2; d2<14; d2+=2)
		{
			if (d2 == 4 || d2 == 6 || d2 == 8 || d2 == 10)
			{
				future<unsigned int> f = async(try3,6, d2,d3, 0, ((r2[6][d2])%n), n, field, lChance);
				r3[d3][d2+24]=f.get();
			}
			else
			{
				future<unsigned int> f = async(try3,6, d2,d3, 0, 0, n, field, lChance);
				r3[d3][d2+24]=f.get();
			}
			if (max < r3[d3][d2+24])
 				max=r3[d3][d2+24];
		}
		for (unsigned short d2 = 2; d2<14; d2+=2)
		{
			if (d2 == 4 || d2 == 6 || d2 == 8 || d2 == 10)
			{
				future<unsigned int> f = async(try3,8, d2,d3, 0, ((r2[8][d2])%n), n, field, lChance);
				r3[d3][d2+36]=f.get();
			}
			else
			{
				future<unsigned int> f = async(try3,8, d2,d3, 0, 0, n, field, lChance);
				r3[d3][d2+36]=f.get();
			}
			if (max < r3[d3][d2+36])
 				max=r3[d3][d2+36];
		}
		for (unsigned short d2 = 2; d2<14; d2+=2)
		{
			if (d2 == 4 || d2 == 6 || d2 == 8 || d2 == 10)
			{
				future<unsigned int> f = async(try3,10, d2,d3, 0, ((r2[10][d2])%n), n, field, lChance);
				r3[d3][d2+48]=f.get();
			}
			else
			{
				r3[d3][d2+48]=async(try3,10, d2,d3, 0, 0, n, field, lChance);
				r3[d3][d2+48]=f.get();
			}
			if (max < r3[d3][d2+48])
 				max=r3[d3][d2+48];
		}
 		for (unsigned short d2 = 2; d2<14; d2+=2)
 		{
 			if (d2 == 4 || d2 == 6 || d2 == 8 || d2 == 10)
 			{
				future<unsigned int> f = async(try3,12, d2,d3, 0, (r2[12][d2])%n), n, field, lChance);
 				r3[d3][d2+60]=f.get();
 			}
			else
			{
				future<unsigned int> f = async(try3,12, d2,d3, 0, 0, n, field, lChance);
				r3[d3][d2+60]=f.get();
			}
 			if (max < r3[d3][d2+60])
 				max=r3[d3][d2+60];
 		}
 	}

 	cout << "The longest move is " << max << "." << endl; 


	//system("pause"); // for windows-family OSs
	getchar(); // выступает в роли аналога "system("pause");"
	return 0;
}