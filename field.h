enum CageType
{
	start,
	empty,
	chance,
	fate,
	penalty,
	bonus
};

class Field
{
	CageType type;
	//class Cage;
	Field *Next;
	Field *Prev;
public:
	Field (void) : Next (this) , Prev (this){}
	Field *pNext(void)
	{
		return Next;
	}
	Field *pPrev(void)
	{
		return Prev;
	}
	~Cage (void){};
};

Field forward (int d, Field p)
{
	for (int i=0; i<d; i++)
	{
		p=p->Next;
	}
}

/*class Cage
{
CageType type;
int number;
public:
	Cage();
	~Cage();
	
};*/