#include <iostream>
#include "units.h"
#include <string>
#include <fstream>

int main(int argc, char **argv)
{
	Array martin;
	List josh;
	Bheap anthony;

	std::fstream in;
	std::string answ;
	std::string one = "1";
	std::string two = "2";
	bool end = false;
	int number;

	in.open("heap.txt", std::ios::in);
	while (in >> number)
	{
		anthony.addElem(number);
	}
	in.close();

	for (int i = 0; i < anthony._vector.size(); i++)
		printf("%d\t", anthony._vector[i]);

	printf("\n\n");

	anthony.printHeap("","",0);















	/*while (!end)
	{
		printf("What do you want to do?:\n"
			"1 - Add element at head\n"
			"2 - Add element at tail\n"
			"3 - Add element at random\n"
			"4 - Remove element at head\n"
			"5 - Remove element at tail\n"
			"6 - Remove element at random\n"
			"7 - Find element\n");
		std::cin >> answ;
		if (answ.compare(one) ==0) {
			std::cin >> number;
			martin.addElem_head(number);
		}
		else if (answ.compare(two)==0) {
			std::cin >> number;
			martin.addElem_tail(number);
		}
		else if (answ.compare("7") == 0)
		{
			std::cin >> number;
			martin.findElem(number);
			std::cout << number << "\n";
		}
			
		for (int i = 0; i < martin.size; i++)
		{
			printf("Number %d: %d\n", i + 1, martin.p[i]);
		}
	}*/

	/*in.open("1-10000.txt", std::ios::out);
	for (int i = 1; i <= 10000; i++)
	{
		in << i << "\n";
	}
	in.close();*/

	return 0;
}