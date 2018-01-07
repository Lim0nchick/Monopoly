#include <iostream>
#include <stack>
#include <list>
#include <iterator>
#include <utility>
#include <vector>
#include <fstream>
//#include "ThreadPool.h"
using namespace std;

/*stack<unsigned short> stackreform(stack<unsigned short> s)
{
	for (unsigned short i=0; i<8; i++)
	{
		s.pop();
	}
	return s;
}*/



/*void Cycle_Check(vector<pair<unsigned, int>> v)
{
	vector<pair<unsigned, int>>::iterator it;
	for (it=v.begin(); it!=v.end(); it++)
	{
		vector<pair<unsigned, int>>::iterator jt;
		for (jt=v.begin(); jt!=v.end(); jt++)
		{
			if (v[i]==v[j])
			{
				cout << "The longest move is INFINITY." << endl;
				terminate();
			}
		}
	}
}
*/
/*int foo(int a)
{
	cout << a << endl;
	if (a==3)
	{	
		cout << "TERMINATE!!!"<< endl;
		terminate();
	}else
	return a;
}*/

int main()
{
	srand (time(0));
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

	list<pair<unsigned short, unsigned>>::iterator it;
	for (it=lChance.begin(); it!=lChance.end(); it++)
	{
		cout << it->first << endl;
	}









	/*for (int i=0; i<10; i++)
	{
		std::cout << rand()%2+1 << std::endl;
	}*/

	/*queue<int> q;
	q.push(1);
	int r=q.front();
	cout << r;*/
/*stack<unsigned short> sChance1;
	for (unsigned short i=0; i<10; i++)
	{
		sChance1.push(rand()%3+1);
		cout << sChance1.top() << endl;
	}

cout << endl;
cout << endl;

	stack<unsigned short> sChance2 = stackreform(sChance1);


	for (unsigned short i=0; i<10; i++)
	{
		cout << sChance1.top() << endl;
		sChance1.pop();
	}

cout << endl;
cout << endl;

for (unsigned short i=0; i<2; i++)
	{
		cout << sChance2.top() << endl;
		sChance2.pop();
	}
*/
/*int i=0;
	do
	{
		i++;
		cout << i << endl;
	} while (i!=5);*/

	/*list<unsigned> L;
	list<unsigned>::iterator it=L.begin();
	for(auto i=0; i<5; i++)
	{
		L.push_back(i);
	}
	int f=0;
	/*do
	{
		
		//cout << *it << endl;
		if (it==L.end()) L.begin();
		f++;
	} while (f<20);*/

/*vector<pair<unsigned, unsigned>> v;
//pair<unsigned, unsigned> p;

for (auto i=0; i<8; i++)
{
	v.push_back(make_pair(i,*it));
	advance(it,1);
}
for (auto i=0; i<8; i++)
{
	cout << v[i].first << "\t" << v[i].second << endl;
}
*/
/*bool b=false;

cout << b << endl;
cout << endl;

int *A; A=new int [5];
for (int i=0; i<5; i++)
{
	A[i]=rand()%3;
	cout << A[i] << endl;
}
cout << endl;
for (int i=0; i<5; i++)
{
	for (int j=i+1; j<5; j++)
	{
		if (A[i]==A[j])
		{
			cout << A[i] << " = " << A[j] << endl;	
			b=true;
			
		}
		//if (b) break;
		cout << A[i] << " != " << A[j] << endl;
		
	}
}
cout << endl;
cout << b << endl;
*/
/*ThreadPool pool;
//vector<int> r;
for (int i=0; i<200; i++)
{
	pool.runAsync(&foo,i);
}*/

return 0;
}