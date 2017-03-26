#pragma once
#include <vector>

class Array
{
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
	void addElem_random(int elem);
	void removeElem_tail();
	void removeElem_head();
	void removeElem_random();
	int findElem(int elem);
};

struct node
{
	node * next, * prev;
	int data;
};

class List
{

public:

	node * head, * tail;
	unsigned size;

	List()
	{
		tail = head = 0;	
		size = 0;
	}
	
	void print_list();
	void addElem_head(int elem);
	void addElem_tail(int elem);
	void removeElem(node * e);
	void removeElem_head();
	void removeElem_tail();
	void addElem_random(int elem);
	void removeElem_random();
	node * findElem(int elem);
};

class Bheap
{
public:
	std::vector<int> _vector;
	void goUp(int index);
	void addElem(int elem);
	void removeRoot();
	void printHeap(std::string sp, std::string sn, int v);
};