#pragma once

class Array
{
private:

	int emement;
	

public:

	Array()
	{
		size = 0;
	}

	int* p;
	int* temp;
	int size;

	void addElem_head(int elem);
	void addElem_tail(int elem);
	void removeElem_tail(int);
};
