#include <fstream>
#include <iostream>
#include "ThreadPool.h"
//#include "TP.h"
#include <future>
#include <thread>
#include <vector>
//#include "TRY1.hpp"
#include <list>
#include <iterator>
#include <utility>
using namespace std;


void Cycle_Check(vector<unsigned> v)
{
	vector<unsigned>::iterator it;
	for (it=v.begin(); it!=v.end(); it++)
	{
		vector<unsigned>::iterator jt;
		for (jt=it; jt!=v.end(); jt++)
		{
			if (jt!=it)
			{
				//if ((it->first == jt->first) && (it->second == jt->second))
				if (*it=*jt)
				{
					cout << "CYCLE" << endl; // WTF??? why print always???
					return;
					//terminate();
				}
			}
		}
	}
}

/*unsigned int try1(unsigned short d, unsigned int points,
	unsigned short CurPos, unsigned n,
	unsigned short* field, list<pair<unsigned short, unsigned>> lChance)	
{
	list<pair<unsigned short, unsigned>>::iterator it=lChance.begin();
	vector<pair<unsigned, list<pair<unsigned short, unsigned>>::iterator>> Pos_and_Chance;
	Pos_and_Chance.push_back(make_pair(0,it));
	if (d>n)
	{
		CurPos += (d%n);
	} else CurPos += d;

	do
	{
		switch (field[CurPos])
		{
			case 1:
			{
				switch (it->first)
				{
					case 1:
					{	
						points+=(it->second);
						if ((it->second)>n)
						{
							CurPos += ((it->second)%n);
						} else CurPos += (it->second);
					} break;

					case 2:
					{
						if ((it->second)>CurPos)
						{
							CurPos -= ((it->second)%n);
						} else CurPos -= (it->second);
						points-=(it->second);
					} break;
					
					case 3:
					{
						CurPos=0;
						points+=(n-CurPos);
					} break;
				}
				Pos_and_Chance.push_back(make_pair(CurPos,it));
				advance(it, 1);
				if (it==lChance.end())
				{
					lChance.begin();
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
}*/


/*stack<unsigned short> stackreform(stack<unsigned short> s)
{
	for (unsigned short i=0; i<8; i++)
	{
		s.pop();
	}
	return s;
}*/




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
	vector<unsigned> v;
	v.push_back(3);
	//v.push_back(5);
	//v.push_back(7);
	v.push_back(1);
	//v.push_back(3);
	//v.push_back(9);
	//v.push_back(0);
	//v.push_back(8);
Cycle_Check(v);
	/*srand (time(0));
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
//int* r1;
	//vector <future<unsigned>> f1;
	//r1=new int[20];
	/*list<pair<unsigned short, unsigned>>::iterator it;
	for (it=lChance.begin(); it!=lChance.end(); it++)
	{
		cout << it->first << endl;
	}*/



	/*ThreadPool pool;
	//ThreadPool pool/*(4)*/;
	//cout << "i = " << endl;
	/*vector <unsigned> r1;
	vector <future<unsigned>> f1;
	//cout << "i = " << endl;
	vector<unsigned>::iterator it;
	//vector<future<unsigned>>::iterator ft=f1.begin();
	for (auto i=0; i<20; i++)
	{
		/*future<unsigned> f1/*[i]=async(try1,(i+3), 0,0,n,field, lChance);
		r1[i]=f1/*[i].get();*/
		//r1[i] = pool.runAsync<unsigned int>(&try1,3, 0,0,n,field, lChance);
//cout << "i = "  << endl;
		//f1[i]=pool.runAsync<unsigned>(&try1,i, 0,0,n,field, lChance);
//unsigned tmp=pool.runAsync<unsigned>(&try1, 3, 0,0,n,field, lChance);
		//*ft=async(try1,(i+3), 0,0,n,field, lChance);
		//r1.push_back(pool.runAsync<unsigned>(&try1, 3, 0,0,n,field, lChance));
	//	cout << "i = "  << endl;
		//ft++;
		//cout << "r[i] = " << r1[i] << endl;
	//}
	///cout << "\n\n";
	//for (it=r1.begin(); it!=r1.end(); it++)
	//{
	//	r1[i]=f1[i].get();
//		cout <<"\t::\t" << *it << endl;
	//}

	/*for (unsigned i=0; i<20; i++)
	{
		while(!(r1[i]).ready)
		{
			cout << "i = " << i << endl;
			cout << "r[i] = " << (r1[i]).data << endl;
		}
	}*/





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