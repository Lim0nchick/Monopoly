#include <iostream>
#include  <stack>
#include <list>
#include <iterator>
using namespace std;

/*stack<unsigned short> stackreform(stack<unsigned short> s)
{
	for (unsigned short i=0; i<8; i++)
	{
		s.pop();
	}
	return s;
}*/

int main()
{
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

	list<unsigned> L;
	list<unsigned>::iterator it=L.begin();
	for(auto i=0; i<5; i++)
	{
		L.push_back(i);
	}
	int f=0;
	do
	{
		advance(it,1);
		cout << *it << endl;
		if (it==L.end()) L.begin();
		f++;
	} while (f<20);
}