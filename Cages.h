#include <iostream>
using namespace std;
void chance (unsigned short int points)
{
	unsigned short int n=rand()%5+1;
	switch (n):
	{
		case (1):
		{
			cout << "get 3 points and pass to 3 cages forward" << endl;
			forward(3, p);
			points+=3;
			break;
		}
		case (2):
		{
			cout << "lose 3 points" << endl;
			/*функция для перещемения по полю (массиву) игрока*/
			points+=3;
			break;
		}
		case (3):
		{
			cout << "extra course" << endl;
			dice1 = rand()%6+1; cout << "dice1 = " << dice1 << endl; 
			dice2 = rand()%6+1; cout << "dice2 = " << dice2 << endl;
			d = dice1 + dice2;
			cout << d << endl;
			p1=forward(d, p1);
			points+=d;
			break;
		}
		case (4):
		{
			cout << "Go to ""START"", lose all points"<< endl;
			/*функция для перещемения по полю (массиву) игрока*/
			
			points=0;
			break;
		}
		default: 
		{
			cout << "Empty chance" << endl;
			break;
	}
	//return points;
}