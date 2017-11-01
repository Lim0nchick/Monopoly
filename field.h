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


/*class Cage
{
CageType type;
int number;
public:
	Cage();
	~Cage();
	
};*/