#include <fstream>
#include <iostream>
#include "ThreadPool.h"

using namespace std;

int main()
{
	srand(time(0));

	unsigned short points = 0;
	unsigned short n;
	
	fstream Map;
	Map.open("Map.dat", ios::in);
	if(!Map) return 1; // Если ошибка открытия файла, то завершаем программу
	Map >> n;
	unsigned short* field = new unsigned short[n];
	unsigned short CurPos;
	for (CurPos=0; CurPos<n; CurPos++)	// CurPos является индексом для экономии памяти, чтобы не выделять память для доп переменной 
	{
		Map >> field[CurPos];
		cout << field[CurPos];
	}
	stack<unsigned short> sChance;
	unsigned short ChanceStackSize;
	Map >> ChanceStackSize;
	for (auto i = 0; i<ChanceStackSize; i++)	
	{
		Map >> sChance.push();
		cout << field[CurPos];
	}
	cout << "\n\n";
	Map.close();
	//pool.runAsync(&)
	ThreadPool pool;
	//unsigned short d;
	unsigned int* r = new unsigned int[9];
	unsigned int r[0] = pool.runAsync<unsigned int>(&try,3,  0,0,field, sChance);
	unsigned int r[1] = pool.runAsync<unsigned int>(&try,4,  0,0,field, sChance);
	unsigned int r[2] = pool.runAsync<unsigned int>(&try,5,  0,0,field, sChance);
	unsigned int r[3] = pool.runAsync<unsigned int>(&try,6,  0,0,field, sChance);
	unsigned int r[4] = pool.runAsync<unsigned int>(&try,7,  0,0,field, sChance);
	unsigned int r[5] = pool.runAsync<unsigned int>(&try,8,  0,0,field, sChance);
	unsigned int r[6] = pool.runAsync<unsigned int>(&try,9,  0,0,field, sChance);
	unsigned int r[7] = pool.runAsync<unsigned int>(&try,10, 0,0,field, sChance);
	unsigned int r[8] = pool.runAsync<unsigned int>(&try,11, 0,0,field, sChance);
	
	unsigned int max = r[0]
	for (auto i=1; i<9; i++)
	{
		if (max < r[i])
			max = r[i];
 	}
 	delete r;

 	unsigned int* r = new unsigned int[9];
	unsigned int r[0] = pool.runAsync<unsigned int>(&try1,3,  0,0,field, sChance);
	unsigned int r[1] = pool.runAsync<unsigned int>(&try1,4,  0,0,field, sChance);
	unsigned int r[2] = pool.runAsync<unsigned int>(&try1,5,  0,0,field, sChance);
	unsigned int r[3] = pool.runAsync<unsigned int>(&try1,6,  0,0,field, sChance);
	unsigned int r[4] = pool.runAsync<unsigned int>(&try1,7,  0,0,field, sChance);
	unsigned int r[5] = pool.runAsync<unsigned int>(&try1,8,  0,0,field, sChance);
	unsigned int r[6] = pool.runAsync<unsigned int>(&try1,9,  0,0,field, sChance);
	unsigned int r[7] = pool.runAsync<unsigned int>(&try1,10, 0,0,field, sChance);
	unsigned int r[8] = pool.runAsync<unsigned int>(&try1,11, 0,0,field, sChance);



		/*dice1 = rand()%6+1; cout << "dice1 = " << dice1 << endl; 
	dice2 = rand()%6+1; cout << "dice2 = " << dice2 << endl;*/
	/*unsigned int r[0]  = pool.runAsync<unsigned int>(&try1,1,1,field[CurPos],0,0,0);
	unsigned int r[6]  = pool.runAsync<unsigned int>(&try1,2,2);
	unsigned int r[11] = pool.runAsync<unsigned int>(&try1,3,3);
	unsigned int r[15] = pool.runAsync<unsigned int>(&try1,4,4);
	unsigned int r[18] = pool.runAsync<unsigned int>(&try1,5,5);
	unsigned int r[20] = pool.runAsync<unsigned int>(&try1,6,6);*/

	
	//system("pause"); // for widows-family OSs
	getchar(); // выступает в роли аналога "system("pause");"
	return 0;
}