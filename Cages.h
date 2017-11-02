#include <iostream>
using namespace std;
void chance (int points, Field p)
{
	int n=rand()%10+1;
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
			cout << "get 3 points" << endl;
			points+=3;
			break;
		}
		case (3):
		{
			cout << "lose 3 points" << endl;
			points-=3;
			break;
		}
		case (4):
		{
			cout << "lose 3 points" << endl;
			/*функция для перещемения по полю (двусвязному кольцевому списку) игрока*/
			points+=3;
			break;
		}
		case (5):
		{
			cout << "lose all your points" << endl;
			points=0;
			break;
		}
		case (6):
		{
			cout << "GET 1000000 POINTS!!!" << endl;
			points=100;
			break;
		}
		case (7):
		{
			cout << "give dice to the opponent)" << endl;
			break;
		}
		case (8):
		{
			cout << "you receive the additional course" << endl;
			// TO DO
			break;
		}
		case (9):
		{
			cout << "admission of the course" << endl;
			// TO DO
			break;
		}
		case (10):
		{
			cout << "Go to ""START"", get 5 points"<< endl;
			/*функция для перещемения по полю (двусвязному кольцевому списку) игрока*/
			points+=5;
			break;
		}
	}
	//return points;
}