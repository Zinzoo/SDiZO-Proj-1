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

struct heapnode
{
	int data, index;
	heapnode *parent, *leftch, *rightch;
};

class Bheap
{
public:
	Bheap()
	{
		size = 0;
	}

	int* root;
	int size;
	void daddElem(int elem);
	void dgoUp(int p);
	void dremoveRoot();
	int dfindElem(int elem);
	void dprintHeap(std::string sp, std::string sn, int v);
};

struct BSTnode
{
	BSTnode * parent, *leftch, * rightch;
	int key;
};

class BST
{
public:
	BSTnode * root;
	BST()
	{
		root = NULL;
	}
	void addElem(BSTnode *& root, int v);
	void printBST(std::string sp, std::string sn, BSTnode * v);
	BSTnode * findNode(BSTnode * p, int key);
	BSTnode * minBST(BSTnode *p);
	BSTnode * succBST(BSTnode * p);
	void deleteNode(BSTnode *&root, BSTnode * x);
};

struct RBTNode
{
	RBTNode * up;
	RBTNode * left;
	RBTNode * right;
	int key;
	char color;
	int data;
};

class RBTree
{
private:
	RBTNode S;
	RBTNode * root;
	std::string cr, cl, cp;

	void printRBT(std::string sp, std::string sn, RBTNode * p);

public:
	RBTree();
	void print();
	RBTNode * findRBT(int k);
	RBTNode * minRBT(RBTNode * p);
	RBTNode * succRBT(RBTNode * p);
	void rot_L(RBTNode * A);
	void rot_R(RBTNode * A);
	void insertRBT(int k);
	void removeRBT(RBTNode * X);
};