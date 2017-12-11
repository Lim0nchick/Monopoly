#include <iostream>
#include  <stack>
using namespace std;

stack<unsigned short> stackreform(stack<unsigned short> s)
{
	for (unsigned short i=0; i<8; i++)
	{
		s.pop();
	}
	return s;
}

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
stack<unsigned short> sChance1;
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

}