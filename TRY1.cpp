/*int try(int dice1, int dice2)	
{
	bool exit=false;
	do
	{
		if (field[CurPos] == 0)
		{
			//cout << "empty cage" << endl;
			if (c_doubles != 0)
			{
				unsigned int* r1 = new unsigned int[21];
				// распараллеливаем перебор вариантов при  броске кубика
				unsigned int r1[0]  = pool.runAsync<unsigned int>(&try1,1,1,field[CurPos], CurPos, points);
				unsigned int r1[1]  = pool.runAsync<unsigned int>(&try1,1,2,field[CurPos], CurPos, points);
				unsigned int r1[2]  = pool.runAsync<unsigned int>(&try1,1,3,field[CurPos], CurPos, points);
				unsigned int r1[3]  = pool.runAsync<unsigned int>(&try1,1,4,field[CurPos], CurPos, points);
				unsigned int r1[4]  = pool.runAsync<unsigned int>(&try1,1,5,field[CurPos], CurPos, points);
				unsigned int r1[5]  = pool.runAsync<unsigned int>(&try1,1,6,field[CurPos], CurPos, points);
				unsigned int r1[6]  = pool.runAsync<unsigned int>(&try1,2,2,field[CurPos], CurPos, points);
				unsigned int r1[7]  = pool.runAsync<unsigned int>(&try1,2,3,field[CurPos], CurPos, points);
				unsigned int r1[8]  = pool.runAsync<unsigned int>(&try1,2,4,field[CurPos], CurPos, points);
				unsigned int r1[9]  = pool.runAsync<unsigned int>(&try1,2,5,field[CurPos], CurPos, points);
				unsigned int r1[10] = pool.runAsync<unsigned int>(&try1,2,6,field[CurPos], CurPos, points);
				unsigned int r1[11] = pool.runAsync<unsigned int>(&try1,3,3,field[CurPos], CurPos, points);
				unsigned int r1[12] = pool.runAsync<unsigned int>(&try1,3,4,field[CurPos], CurPos, points);
				unsigned int r1[13] = pool.runAsync<unsigned int>(&try1,3,5,field[CurPos], CurPos, points);
				unsigned int r1[14] = pool.runAsync<unsigned int>(&try1,3,6,field[CurPos], CurPos, points);
				unsigned int r1[15] = pool.runAsync<unsigned int>(&try1,4,4,field[CurPos], CurPos, points);
				unsigned int r1[16] = pool.runAsync<unsigned int>(&try1,4,5,field[CurPos], CurPos, points);
				unsigned int r1[17] = pool.runAsync<unsigned int>(&try1,4,6,field[CurPos], CurPos, points);
				unsigned int r1[18] = pool.runAsync<unsigned int>(&try1,5,5,field[CurPos], CurPos, points);
				unsigned int r1[19] = pool.runAsync<unsigned int>(&try1,5,6,field[CurPos], CurPos, points);
				unsigned int r1[20] = pool.runAsync<unsigned int>(&try1,6,6,field[CurPos], CurPos, points);
				d = dice1 + dice2;
				cout << d << endl;
				if (dice1==dice2)
				{
					c_doubles+=1;
					points+=d;
					if (d>n)
					{
						step = d%n;
						CurPos = step;
					} else CurPos = d;
					if (c_doubles=3)
						exit = true;
					
				} else exit = true;	
			} else exit = true;	
		}	

		if (field[CurPos]==1)
		{
				//cout << "Chance, give and read a Chance-card" << endl;
				unsigned short Card = rand()%4+1;
				
				ThreadPool pool1;

				switch (Card)
				{
					case 1:
					{
						//cout << "get 3 points and pass to 3 cages forward" << endl;
				
						points+=3;
						if (3>n)
						{
							step = 3%n;
							CurPos += step;
						} else CurPos += 3;
					}break;
					case 2:
					{
						//cout << "lose 3 points and pass to 3 cages back" << endl;
						if (3>CurPos)
						{
							step = 3%n;
							CurPos -= step;
						} else CurPos -= 3;
						points-=3;
					}break;
					case 3:
					{
						//cout << "extra course" << endl;
						dice1 = rand()%6+1; //cout << "dice1 = " << dice1 << endl; 
						dice2 = rand()%6+1; //cout << "dice2 = " << dice2 << endl;
						d = dice1 + dice2;
						cout << d << endl;

						if (dice1==dice2)
							c_doubles+=1;
						else c_doubles=0;

						if (c_doubles==3)
							exit = true;
						else
						{
							points+=d;
							if ((CurPos+d)>n)
							{
								step = (CurPos+d)%n;
								CurPos = step;
							} else CurPos += d;
						}
					}break;
					case 4:
					{
						//cout << "Go to 'START'"<< endl;
						CurPos=0;
						points+=(n-CurPos);
					}break;
				}

		}

	} while (exit == false);
	return points;
}*/
	

int try1(unsigned int dice1, unsigned int dice2, unsigned int field[CurPos],
	unsigned int CurPos, unsigned int points, unsigned short Card)	
{
	bool exit=false;
	do
	{
		if (field[CurPos] == 0)
		{
			//cout << "empty cage" << endl;
			if (c_doubles != 0)
			{
				unsigned short Card = 0;
				unsigned int* r1 = new unsigned int[21];
				// распараллеливаем перебор вариантов при "хрен его знает каком" броске кубика
				unsigned int r1[0]  = pool.runAsync<unsigned int>(&try1,1,1,field[CurPos], CurPos, points, Card);
				unsigned int r1[1]  = pool.runAsync<unsigned int>(&try1,1,2,field[CurPos], CurPos, points, Card);
				unsigned int r1[2]  = pool.runAsync<unsigned int>(&try1,1,3,field[CurPos], CurPos, points, Card);
				unsigned int r1[3]  = pool.runAsync<unsigned int>(&try1,1,4,field[CurPos], CurPos, points, Card);
				unsigned int r1[4]  = pool.runAsync<unsigned int>(&try1,1,5,field[CurPos], CurPos, points, Card);
				unsigned int r1[5]  = pool.runAsync<unsigned int>(&try1,1,6,field[CurPos], CurPos, points, Card);
				unsigned int r1[6]  = pool.runAsync<unsigned int>(&try1,2,2,field[CurPos], CurPos, points, Card);
				unsigned int r1[7]  = pool.runAsync<unsigned int>(&try1,2,3,field[CurPos], CurPos, points, Card);
				unsigned int r1[8]  = pool.runAsync<unsigned int>(&try1,2,4,field[CurPos], CurPos, points, Card);
				unsigned int r1[9]  = pool.runAsync<unsigned int>(&try1,2,5,field[CurPos], CurPos, points, Card);
				unsigned int r1[10] = pool.runAsync<unsigned int>(&try1,2,6,field[CurPos], CurPos, points, Card);
				unsigned int r1[11] = pool.runAsync<unsigned int>(&try1,3,3,field[CurPos], CurPos, points, Card);
				unsigned int r1[12] = pool.runAsync<unsigned int>(&try1,3,4,field[CurPos], CurPos, points, Card);
				unsigned int r1[13] = pool.runAsync<unsigned int>(&try1,3,5,field[CurPos], CurPos, points, Card);
				unsigned int r1[14] = pool.runAsync<unsigned int>(&try1,3,6,field[CurPos], CurPos, points, Card);
				unsigned int r1[15] = pool.runAsync<unsigned int>(&try1,4,4,field[CurPos], CurPos, points, Card);
				unsigned int r1[16] = pool.runAsync<unsigned int>(&try1,4,5,field[CurPos], CurPos, points, Card);
				unsigned int r1[17] = pool.runAsync<unsigned int>(&try1,4,6,field[CurPos], CurPos, points, Card);
				unsigned int r1[18] = pool.runAsync<unsigned int>(&try1,5,5,field[CurPos], CurPos, points, Card);
				unsigned int r1[19] = pool.runAsync<unsigned int>(&try1,5,6,field[CurPos], CurPos, points, Card);
				unsigned int r1[20] = pool.runAsync<unsigned int>(&try1,6,6,field[CurPos], CurPos, points, Card);
				d = dice1 + dice2;
				cout << d << endl;
				if (dice1==dice2)
				{
					c_doubles+=1;
					points+=d;
					if (d>n)
					{
						step = d%n;
						CurPos = step;
					} else CurPos = d;
					if (c_doubles=3)
						exit = true;
					
				} else exit = true;	
			} else exit = true;	
		}	

		if (field[CurPos]==1)
		{
				//cout << "Chance, give and read a Chance-card" << endl;
				//unsigned short Card = rand()%4+1;
				unsigned int* r1 = new unsigned int[21];
				unsigned int r1[0]  = pool.runAsync<unsigned int>(&try1,dice1,dice2,field[CurPos], CurPos, points, 1);
				unsigned int r1[1]  = pool.runAsync<unsigned int>(&try1,dice1,dice2,field[CurPos], CurPos, points, 2);
				unsigned int r1[2]  = pool.runAsync<unsigned int>(&try1,dice1,dice2,field[CurPos], CurPos, points, 3);
				unsigned int r1[3]  = pool.runAsync<unsigned int>(&try1,dice1,dice2,field[CurPos], CurPos, points, 4);

				
				ThreadPool pool1;

				switch (Card)
				{
					case 1:
					{
						//cout << "get 3 points and pass to 3 cages forward" << endl;
				
						points+=3;
						if (3>n)
						{
							step = 3%n;
							CurPos += step;
						} else CurPos += 3;
					}break;
					case 2:
					{
						//cout << "lose 3 points and pass to 3 cages back" << endl;
						if (3>CurPos)
						{
							step = 3%n;
							CurPos -= step;
						} else CurPos -= 3;
						points-=3;
					}break;
					case 3:
					{
						//cout << "extra course" << endl;
						//dice1 = rand()%6+1; //cout << "dice1 = " << dice1 << endl; 
						//dice2 = rand()%6+1; //cout << "dice2 = " << dice2 << endl;
						unsigned int* r1 = new unsigned int[21];
						// распараллеливаем перебор вариантов при "хрен его знает каком" броске кубика
						unsigned int r1[0]  = pool.runAsync<unsigned int>(&try1,1,1,field[CurPos], CurPos, points, Card);
						unsigned int r1[1]  = pool.runAsync<unsigned int>(&try1,1,2,field[CurPos], CurPos, points, Card);
						unsigned int r1[2]  = pool.runAsync<unsigned int>(&try1,1,3,field[CurPos], CurPos, points, Card);
						unsigned int r1[3]  = pool.runAsync<unsigned int>(&try1,1,4,field[CurPos], CurPos, points, Card);
						unsigned int r1[4]  = pool.runAsync<unsigned int>(&try1,1,5,field[CurPos], CurPos, points, Card);
						unsigned int r1[5]  = pool.runAsync<unsigned int>(&try1,1,6,field[CurPos], CurPos, points, Card);
						unsigned int r1[6]  = pool.runAsync<unsigned int>(&try1,2,2,field[CurPos], CurPos, points, Card);
						unsigned int r1[7]  = pool.runAsync<unsigned int>(&try1,2,3,field[CurPos], CurPos, points, Card);
						unsigned int r1[8]  = pool.runAsync<unsigned int>(&try1,2,4,field[CurPos], CurPos, points, Card);
						unsigned int r1[9]  = pool.runAsync<unsigned int>(&try1,2,5,field[CurPos], CurPos, points, Card);
						unsigned int r1[10] = pool.runAsync<unsigned int>(&try1,2,6,field[CurPos], CurPos, points, Card);
						unsigned int r1[11] = pool.runAsync<unsigned int>(&try1,3,3,field[CurPos], CurPos, points, Card);
						unsigned int r1[12] = pool.runAsync<unsigned int>(&try1,3,4,field[CurPos], CurPos, points, Card);
						unsigned int r1[13] = pool.runAsync<unsigned int>(&try1,3,5,field[CurPos], CurPos, points, Card);
						unsigned int r1[14] = pool.runAsync<unsigned int>(&try1,3,6,field[CurPos], CurPos, points, Card);
						unsigned int r1[15] = pool.runAsync<unsigned int>(&try1,4,4,field[CurPos], CurPos, points, Card);
						unsigned int r1[16] = pool.runAsync<unsigned int>(&try1,4,5,field[CurPos], CurPos, points, Card);
						unsigned int r1[17] = pool.runAsync<unsigned int>(&try1,4,6,field[CurPos], CurPos, points, Card);
						unsigned int r1[18] = pool.runAsync<unsigned int>(&try1,5,5,field[CurPos], CurPos, points, Card);
						unsigned int r1[19] = pool.runAsync<unsigned int>(&try1,5,6,field[CurPos], CurPos, points, Card);
						unsigned int r1[20] = pool.runAsync<unsigned int>(&try1,6,6,field[CurPos], CurPos, points, Card);		
						d = dice1 + dice2;
						cout << d << endl;

						if (dice1==dice2)
							c_doubles+=1;
						else c_doubles=0;

						if (c_doubles==3)
							exit = true;
						else
						{
							points+=d;
							if ((CurPos+d)>n)
							{
								step = (CurPos+d)%n;
								CurPos = step;
							} else CurPos += d;
						}
					}break;
					case 4:
					{
						//cout << "Go to 'START'"<< endl;
						CurPos=0;
						points+=(n-CurPos);
					}break;
				}
		}
	} while (exit == false);
	return points;
}