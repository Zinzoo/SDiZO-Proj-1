#include <iostream>
#include "units.h"
#include <string>
#include <fstream>
#include <windows.h>
#include <iomanip>
#include <random>

long long int read_QPC();

int main(int argc, char **argv)
{
	Array martin;
	List josh;
	Bheap anthony;
	BST samuel;
	RBTree brian;

	long long int frequency, start, elapsed;
	QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(1, 1000000);

	std::fstream in, out;
	std::string answ;
	std::string one = "1";
	std::string two = "2";
	std::string three = "3";
	std::string four = "4";
	std::string five = "5";
	std::string six = "6";
	std::string seven = "7";
	std::string eight = "8";
	std::string nine = "9";
	bool end = false;
	int number, random;

	while (!end)
	{
		printf("To which data structure do you want to inserst the list of numbers?:\n"
			"1 - Dynamic Array\n"
			"2 - Double linked list\n"
			"3 - Binary heap\n"
			"4 - Binary search tree\n"
			"5 - Red black tree\n"
			"6 - End program\n");
		std::cin >> answ;
		if (answ.compare(one) == 0) {
			in.open("numbers.txt", std::ios::in);
			while (in >> number)
			{
				martin.addElem_tail(number);
			}
			in.close();

			while (true)
			{
				printf("What do you want to do?:\n"
					"1 - Add element at head\n"
					"2 - Add element at tail\n"
					"3 - Add element at random\n"
					"4 - Remove element at head\n"
					"5 - Remove element at tail\n"
					"6 - Remove element at random\n"
					"7 - Find element\n"
					"8 - Print\n"
					"9 - Go back\n");
				std::cin >> answ;
				if (answ.compare(one) == 0) {
					std::cin >> number;
					start = read_QPC();
					martin.addElem_head(number);
					elapsed = read_QPC() - start;
					out.open("result.txt", std::ios_base::app);
					out << std::setprecision(0) << (1000.0 * elapsed) /
						frequency << std::endl;
					out.close();
				}
				else if (answ.compare(two) == 0) {
					std::cin >> number;
					start = read_QPC();
					martin.addElem_tail(number);
					elapsed = read_QPC() - start;
					out.open("result.txt", std::ios_base::app);
					out << std::setprecision(0) << (1000.0 * elapsed) /
						frequency << std::endl;
					out.close();
				}
				else if (answ.compare(three) == 0) {
					std::cin >> number;
					start = read_QPC();
					martin.addElem_random(number);
					elapsed = read_QPC() - start;
					out.open("result.txt", std::ios_base::app);
					out << std::setprecision(0) << (1000.0 * elapsed) /
						frequency << std::endl;
					out.close();
				}
				else if (answ.compare(four) == 0) {
					start = read_QPC();
					martin.removeElem_head();
					elapsed = read_QPC() - start;
					out.open("result.txt", std::ios_base::app);
					out << std::setprecision(0) << (1000.0 * elapsed) /
						frequency << std::endl;
					out.close();
				}
				else if (answ.compare(five) == 0) {
					start = read_QPC();
					martin.removeElem_tail();
					elapsed = read_QPC() - start;
					out.open("result.txt", std::ios_base::app);
					out << std::setprecision(0) << (1000.0 * elapsed) /
						frequency << std::endl;
					out.close();
				}
				else if (answ.compare(six) == 0) {
					start = read_QPC();
					martin.removeElem_random();
					elapsed = read_QPC() - start;
					out.open("result.txt", std::ios_base::app);
					out << std::setprecision(0) << (1000.0 * elapsed) /
						frequency << std::endl;
					out.close();
				}
				else if (answ.compare(seven) == 0)
				{
					std::cin >> number;
					start = read_QPC();
					martin.findElem(number);				
					elapsed = read_QPC() - start;
					out.open("result.txt", std::ios_base::app);
					out << std::setprecision(0) << (1000.0 * elapsed) /
						frequency << std::endl;
					out.close();
					std::cout << number << "\n";
				}
				else if (answ.compare(eight) == 0) {
					for (int i = 0; i < martin.size; i++)
					{
						printf("Element [%d]: %d\n", i + 1, martin.p[i]);
					};
				}
				else if (answ.compare(nine) == 0) {
					break;
				}
			}
		}
		else if (answ.compare(two) == 0) {
			in.open("numbers.txt", std::ios::in);
			while (in >> number)
			{
				josh.addElem_tail(number);
			}
			in.close();

			while (true)
			{
				printf("What do you want to do?:\n"
					"1 - Add element at head\n"
					"2 - Add element at tail\n"
					"3 - Add element at random\n"
					"4 - Remove element at head\n"
					"5 - Remove element at tail\n"
					"6 - Remove element at random\n"
					"7 - Find element\n"
					"8 - Print\n"
					"9 - Go back\n");
				std::cin >> answ;
				if (answ.compare(one) == 0) {
					std::cin >> number;
					start = read_QPC();
					josh.addElem_head(number);
					elapsed = read_QPC() - start;
					out.open("result.txt", std::ios_base::app);
					out << std::setprecision(0) << (1000.0 * elapsed) /
						frequency << std::endl;
					out.close();
				}
				else if (answ.compare(two) == 0) {
					std::cin >> number;
					start = read_QPC();
					josh.addElem_tail(number);
					elapsed = read_QPC() - start;
					out.open("result.txt", std::ios_base::app);
					out << std::setprecision(0) << (1000.0 * elapsed) /
						frequency << std::endl;
					out.close();
				}
				else if (answ.compare(three) == 0) {
					std::cin >> number;
					start = read_QPC();
					josh.addElem_random(number);
					elapsed = read_QPC() - start;
					out.open("result.txt", std::ios_base::app);
					out << std::setprecision(0) << (1000.0 * elapsed) /
						frequency << std::endl;
					out.close();
				}
				else if (answ.compare(four) == 0) {
					start = read_QPC();
					josh.removeElem_head();
					elapsed = read_QPC() - start;
					out.open("result.txt", std::ios_base::app);
					out << std::setprecision(0) << (1000.0 * elapsed) /
						frequency << std::endl;
					out.close();
				}
				else if (answ.compare(five) == 0) {
					start = read_QPC();
					josh.removeElem_tail();
					elapsed = read_QPC() - start;
					out.open("result.txt", std::ios_base::app);
					out << std::setprecision(0) << (1000.0 * elapsed) /
						frequency << std::endl;
					out.close();
				}
				else if (answ.compare(six) == 0) {
					start = read_QPC();
					josh.removeElem_random();
					elapsed = read_QPC() - start;
					out.open("result.txt", std::ios_base::app);
					out << std::setprecision(0) << (1000.0 * elapsed) /
						frequency << std::endl;
					out.close();
				}
				else if (answ.compare(seven) == 0)
				{
					std::cin >> number;
					start = read_QPC();
					josh.findElem(number);
					elapsed = read_QPC() - start;
					out.open("result.txt", std::ios_base::app);
					out << std::setprecision(0) << (1000.0 * elapsed) /
						frequency << std::endl;
					out.close();
					std::cout << number << "\n";
				}
				else if (answ.compare(eight) == 0) {
					josh.print_list();
				}
				else if (answ.compare(nine) == 0) {
					break;
				}
			}
		}
		else if (answ.compare(three) == 0)
		{
			in.open("numbers.txt", std::ios::in);
			while (in >> number)
			{
				anthony.daddElem(number);
			}
			in.close();
			
			while (true)
			{
				printf("What do you want to do?:\n"
					"1 - Add element\n"
					"2 - Remove root element\n"
					"3 - Find element\n"
					"4 - Print\n"
					"5 - Go back\n");
				std::cin >> answ;
				if (answ.compare(one) == 0) {
					std::cin >> number;
					start = read_QPC();
					anthony.daddElem(number);
					elapsed = read_QPC() - start;
					out.open("result.txt", std::ios_base::app);
					out << std::setprecision(0) << (1000.0 * elapsed) /
						frequency << std::endl;
					out.close();
				}
				else if (answ.compare(two) == 0) {
					start = read_QPC();
					anthony.dremoveRoot();
					elapsed = read_QPC() - start;
					out.open("result.txt", std::ios_base::app);
					out << std::setprecision(0) << (1000.0 * elapsed) /
						frequency << std::endl;
					out.close();
				}
				else if (answ.compare(three) == 0) {
					std::cin >> number;
					start = read_QPC();
					josh.findElem(number);
					elapsed = read_QPC() - start;
					out.open("result.txt", std::ios_base::app);
					out << std::setprecision(0) << (1000.0 * elapsed) /
						frequency << std::endl;
					out.close();
				}
				else if (answ.compare(four) == 0) {
					anthony.dprintHeap("","",0);
				}
				else if (answ.compare(five) == 0) {
					break;
				}
			}
		}
		else if (answ.compare(four) == 0)
		{
			in.open("numbers.txt", std::ios::in);
			while (in >> number)
			{
				samuel.addElem(samuel.root, number);
			}
			in.close();
			while (true)
			{
				printf("What do you want to do?:\n"
					"1 - Add element\n"
					"2 - Remove element\n"
					"3 - Find element\n"
					"4 - Print\n"
					"5 - Go back\n");
				std::cin >> answ;
				if (answ.compare(one) == 0) {
					std::cin >> number;
					start = read_QPC();
					samuel.addElem(samuel.root, number);
					elapsed = read_QPC() - start;
					out.open("result.txt", std::ios_base::app);
					out << std::setprecision(0) << (1000.0 * elapsed) /
						frequency << std::endl;
					out.close();
				}
				else if (answ.compare(two) == 0) {
					std::cin >> number;
					start = read_QPC();
					samuel.deleteNode(samuel.root, samuel.findNode(samuel.root, number));
					elapsed = read_QPC() - start;
					out.open("result.txt", std::ios_base::app);
					out << std::setprecision(0) << (1000.0 * elapsed) /
						frequency << std::endl;
					out.close();
				}
				else if (answ.compare(three) == 0) {
					std::cin >> number;
					start = read_QPC();
					samuel.findNode(samuel.root, number);
					elapsed = read_QPC() - start;
					out.open("result.txt", std::ios_base::app);
					out << std::setprecision(0) << (1000.0 * elapsed) /
						frequency << std::endl;
					out.close();
				}
				else if (answ.compare(four) == 0) {
					samuel.printBST("","",samuel.root);
				}
				else if (answ.compare(five) == 0) {
					break;
				}
			}
		}	
		else if (answ.compare(five) == 0)
		{
			in.open("numbers.txt", std::ios::in);
			while (in >> number)
			{
				brian.insertRBT(number);
			}
			in.close();

			while (true)
			{
				printf("What do you want to do?:\n"
					"1 - Add element\n"
					"2 - Remove element\n"
					"3 - Find element\n"
					"4 - Print\n"
					"5 - Go back\n");
				std::cin >> answ;
				if (answ.compare(one) == 0) {
					std::cin >> number;
					start = read_QPC();
					brian.insertRBT(number);
					elapsed = read_QPC() - start;
					out.open("result.txt", std::ios_base::app);
					out << std::setprecision(0) << (1000.0 * elapsed) /
						frequency << std::endl;
					out.close();
				}
				else if (answ.compare(two) == 0) {
					std::cin >> number;
					start = read_QPC();
					brian.removeRBT(brian.findRBT(number));
					elapsed = read_QPC() - start;
					out.open("result.txt", std::ios_base::app);
					out << std::setprecision(0) << (1000.0 * elapsed) /
						frequency << std::endl;
					out.close();
				}
				else if (answ.compare(three) == 0) {
					std::cin >> number;
					start = read_QPC();
					brian.findRBT(number);
					elapsed = read_QPC() - start;
					out.open("result.txt", std::ios_base::app);
					out << std::setprecision(0) << (1000.0 * elapsed) /
						frequency << std::endl;
					out.close();
				}
				else if (answ.compare(four) == 0) {
					brian.print();
				}
				else if (answ.compare(five) == 0) {
					break;
				}
			}
		}
		else if (answ.compare(six) == 0)
		{
			return 0;
		}
	}

	return 0;
}

long long int read_QPC()
{
	LARGE_INTEGER count;
	QueryPerformanceCounter(&count);
	return((long long int)count.QuadPart);
}