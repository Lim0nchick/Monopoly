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
	cout << "\n\n";
	Map.close();
	pool.runAsync(&)
	ThreadPool pool;
	//unsigned short dice1, dice2, d;
	unsigned int* r = new unsigned int[21];
	// распараллеливаем перебор вариантов при первом броске кубика
	unsigned int r[0]  = pool.runAsync<unsigned int>(&try1,1,1,field[CurPos],0,0,0);
	unsigned int r[1]  = pool.runAsync<unsigned int>(&try1,1,2);
	unsigned int r[2]  = pool.runAsync<unsigned int>(&try1,1,3);
	unsigned int r[3]  = pool.runAsync<unsigned int>(&try1,1,4);
	unsigned int r[4]  = pool.runAsync<unsigned int>(&try1,1,5);
	unsigned int r[5]  = pool.runAsync<unsigned int>(&try1,1,6);
	unsigned int r[6]  = pool.runAsync<unsigned int>(&try1,2,2);
	unsigned int r[7]  = pool.runAsync<unsigned int>(&try1,2,3);
	unsigned int r[8]  = pool.runAsync<unsigned int>(&try1,2,4);
	unsigned int r[9]  = pool.runAsync<unsigned int>(&try1,2,5);
	unsigned int r[10] = pool.runAsync<unsigned int>(&try1,2,6);
	unsigned int r[11] = pool.runAsync<unsigned int>(&try1,3,3);
	unsigned int r[12] = pool.runAsync<unsigned int>(&try1,3,4);
	unsigned int r[13] = pool.runAsync<unsigned int>(&try1,3,5);
	unsigned int r[14] = pool.runAsync<unsigned int>(&try1,3,6);
	unsigned int r[15] = pool.runAsync<unsigned int>(&try1,4,4);
	unsigned int r[16] = pool.runAsync<unsigned int>(&try1,4,5);
	unsigned int r[17] = pool.runAsync<unsigned int>(&try1,4,6);
	unsigned int r[18] = pool.runAsync<unsigned int>(&try1,5,5);
	unsigned int r[19] = pool.runAsync<unsigned int>(&try1,5,6);
	unsigned int r[20] = pool.runAsync<unsigned int>(&try1,6,6);

	/*dice1 = rand()%6+1; cout << "dice1 = " << dice1 << endl; 
	dice2 = rand()%6+1; cout << "dice2 = " << dice2 << endl;*/
	

	
	//system("pause"); // for widows-family OSs
	getchar(); // выступает в роли аналога "system("pause");"
	return 0;
}