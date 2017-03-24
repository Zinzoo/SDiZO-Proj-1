#include "units.h"
#include <algorithm>
#include <iostream>

void Array::addElem_tail(int elem)
{
	size++;

	temp = new int[size];

	if (size != 1)
	{
		for (int i = 0; i < size; i++)
		{
			std::cout << p[0] << "\n";
			temp[i] = p[i];
			/*std::cout << p[i] << "\n";
			std::cout << temp[i] << "\n";*/
		}
		/*delete[] p;*/
	}
	
	p = new int[size];
	p = temp;
	delete[] temp;
	p[size-1] = elem;
}
