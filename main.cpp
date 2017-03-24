#include <iostream>
#include "units.h"
#include <string>

int main(int argc, char **argv)
{
	Array martin;

	martin.addElem_tail(14);
	std::cout << "Number " << martin.p[0] << "\n";

	martin.addElem_tail(22);
	std::cout << "Number " << martin.p[0] << " and " << martin.p[1] << "\n";

	int number;
	bool end = false;
	std::string answ;
	while (!end)
	{
		std::cin >> number;
		martin.addElem_tail(number);
		//std::cout << "Value number 1 = " << martin.p[1] << "\n";
		std::cout << "Wanna end?\n";
		std::cin >> answ;
		if (!answ.compare("y"))
		{
			end = true;
		}
	}

	
	for (int i = 1; i <= martin.size; i++)
	{
		std::cout << "Value number " << i << "= " << martin.p[i-1]<<"\n";
	}
	
	std::cout << "Byebye \n";
	return 0;
}