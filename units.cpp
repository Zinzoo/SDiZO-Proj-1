#include "units.h"
#include <iostream>
#include <random>
#include <string>

void Array::addElem_head(int elem)
{
	size++;

		p = (int*)realloc(p, sizeof(int)*size);
		if (size != 1)
		{
			memcpy(p + 1, p, sizeof(int)*(size - 1));
		}
		p[0] = elem;

}

void Array::addElem_tail(int elem)
{
	size++;

		p = (int*)realloc(p, sizeof(int)*size);
		p[size - 1] = elem;

}

void Array::addElem_random(int elem)
{
	size++;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(0, size - 1);
	int random = dist(gen);
	
	p = (int*)realloc(p, sizeof(int)*size);
	if (size == 1)
	{
		p[0] = elem;
		return;
	}
	memcpy(p+random+1, p+random, sizeof(int)*(size-random));
	p[random] = elem;
}

void Array::removeElem_tail()
{
	size--;

	p = (int*)realloc(p, sizeof(int)*size);
}

void Array::removeElem_head()
{
	size--;
	memcpy(p, p+1, sizeof(int)*size);
	p = (int*)realloc(p, sizeof(int)*size);
}

void Array::removeElem_random()
{
	size--;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(0, size - 1);
	int random = dist(gen);

	memcpy(p + random, p + random + 1, sizeof(int)*(size - random));
	p = (int*)realloc(p, sizeof(int)*size);

}

int Array::findElem(int elem)
{
	int ret_numb;
	int i = 0;
	do
	{
		ret_numb = p[i];
		i++;
	} while (ret_numb != elem);

	return ret_numb;
}

void List::print_list()
{
	node * temp;
	temp = head;
	int i = 1;
	while (temp)
	{
		printf("Element [%d] - %d\n", i, temp->data);
		temp = temp->next;
		i++;
	}
}

void List::addElem_head(int elem)
{
	node * e = new node;
	e->data = elem;
	e->prev = NULL;
	e->next = head;
	head = e;
	size++;
	if (e->next) e->next->prev = e;
	else tail = e;
}

void List::addElem_tail(int elem)
{
	node * e = new node;
	e->data = elem;
	e->next = NULL;
	e->prev = tail;
	tail = e;
	size++;
	if (e->prev) e->prev->next = e;
	else head = e;
}

void List::removeElem(node * e)
{
	size--;
	if (e->prev) e->prev->next = e->next;
	else        head = e->next;
	if (e->next) e->next->prev = e->prev;
	else        tail = e->prev;
	delete e;
}

void List::removeElem_head()
{
	if (size) removeElem(head);
}

void List::removeElem_tail()
{
	if (size) removeElem(tail);
}

void List::addElem_random(int elem)
{
	size++;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(1, size);
	int random = dist(gen);

	node * temp;
	temp = head;
	for (int i = 1; i < random; i++)
	{
		temp = temp->next;
	}
	if (temp == head)
	{
		addElem_head(elem);
	}
	else if (temp == tail)
	{
		addElem_tail(elem);
	}
	else
	{
			node * e = new node;
			e->data = elem;
			e->next = temp;
			e->prev = temp->prev;
			temp->prev->next = e;
			temp->prev = e;
	}
}

void List::removeElem_random()
{
	size--;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(1, size+1);
	int random = dist(gen);

	node * temp;
	temp = head;
	for (int i = 1; i < random; i++)
	{
		temp = temp->next;
	}
	if (temp == head)
	{
		removeElem_head();
	}
	else if (temp == tail)
	{
		removeElem_tail();
	}
	else
	{
		removeElem(temp);
	}
}

node * List::findElem(int elem)
{
	node * p = head;
	while (p && p->data != elem) p = p->next;
	return p;
}

void Bheap::daddElem(int elem)
{
	size++;

	root = (int*)realloc(root, sizeof(int)*size);
	root[size - 1] = elem;
	dgoUp(size - 1);
}

void Bheap::dgoUp(int p)
{
	if (p == 0)
		return;

	int parent = (p - 1) / 2;

	if (root[parent] < root[p])
	{
		int temp = root[parent];
		root[parent] = root[p];
		root[p] = temp;
		dgoUp(parent);
	}
}

void Bheap::dremoveRoot()
{
	int length = size;

	if (length == 0)
		return;

	root[0] = root[length - 1];
	dgoUp(0);
}

int Bheap::dfindElem(int elem)
{
	int v;
	for (int i = 0; i < size; i++)
	{
		if (root[i] == elem)
			v = root[i];
	}

	return v;
}

void Bheap::dprintHeap(std::string sp, std::string sn, int v)
{
	std::string cr, cl, cp;
	cr = cl = cp = "  ";
	cr[0] = 218; cr[1] = 196;
	cl[0] = 192; cl[1] = 196;
	cp[0] = 179;

	std::string s;

	if (v < size)
	{
		s = sp;
		if (sn == cr) s[s.length() - 2] = ' ';
		dprintHeap(s + cp, cr, 2 * v + 2);

		s = s.substr(0, sp.length() - 2);

		std::cout << s << sn << root[v] << std::endl;

		s = sp;
		if (sn == cl) s[s.length() - 2] = ' ';
		dprintHeap(s + cp, cl, 2 * v + 1);
	}
}

void BST::addElem(BSTnode *& root, int v)
{
	BSTnode * q, *w;
	w = new BSTnode;

	w->leftch = w->rightch = NULL;
	w->key = v;

	q = root;

	if (!q)
		root = w;
	else
		while (true)
			if (v < q->key)
			{
				if (!q->leftch)
				{
					q->leftch = w;
					break;
				}
				else q = q->leftch;
			}
			else
			{
				if (!q->rightch)
				{
					q->rightch = w;
					break;
				}
				else q = q->rightch;
			}

	w->parent = q;
}

void BST::printBST(std::string sp, std::string sn, BSTnode * v)
{
	std::string cr, cl, cp;
	cr = cl = cp = "  ";
	cr[0] = 218; cr[1] = 196;
	cl[0] = 192; cl[1] = 196;
	cp[0] = 179;

	std::string s;

	if (v)
	{
		s = sp;
		if (sn == cr) s[s.length() - 2] = ' ';
		printBST(s + cp, cr, v->rightch);

		s = s.substr(0, sp.length() - 2);
		std::cout << s << sn << v->key << std::endl;

		s = sp;
		if (sn == cl) s[s.length() - 2] = ' ';
		printBST(s + cp, cl, v->leftch);
	}
}

BSTnode * BST::findNode(BSTnode * p, int k)
{
	while (p &&p->key != k)
		p = (k < p->key) ? p->leftch : p->rightch;
	return p;
}

BSTnode * BST::minBST(BSTnode * p)
{
	if (p) while (p->leftch) p = p->leftch;
	return p;
}

BSTnode * BST::succBST(BSTnode * p)
{
	BSTnode * r;

	if (p)
	{
		if (p->rightch) return minBST(p->rightch);
		else
		{
			r = p->parent;
			while (r && (p == r->rightch))
			{
				p = r;
				r = r->parent;
			}
			return r;
		}
	}
	return p;
}

void BST::deleteNode(BSTnode *& root, BSTnode * x)
{
	BSTnode * Y, *Z;

	if (x)
	{
		Y = !x->leftch || !x->rightch ? x : succBST(x);

		Z = Y->leftch ? Y->leftch : Y->rightch;

		if (Z) Z->parent = Y->parent;

		if (!Y->parent) root = Z;
		else if (Y == Y->parent->leftch) Y->parent->leftch = Z;
		else                      Y->parent->rightch = Z;

		if (Y != x) x->key = Y->key;

		delete Y;

	}
}

RBTree::RBTree()
{
	cr = cl = cp = "  ";
	cr[0] = 218; cr[1] = 196;
	cl[0] = 192; cl[1] = 196;
	cp[0] = 179;
	S.color = 'B';
	S.up = &S;
	S.left = &S;
	S.right = &S;
	root = &S;
}

void RBTree::printRBT(std::string sp, std::string sn, RBTNode * p)
{
	std::string t;

	if (p != &S)
	{
		t = sp;
		if (sn == cr) t[t.length() - 2] = ' ';
		printRBT(t + cp, cr, p->right);

		t = t.substr(0, sp.length() - 2);
		std::cout << t << sn << p->color << ":" << p->key << std::endl;

		t = sp;
		if (sn == cl) t[t.length() - 2] = ' ';
		printRBT(t + cp, cl, p->left);
	}
}

void RBTree::print()
{
	printRBT("", "", root);
}

RBTNode * RBTree::findRBT(int k)
{
	RBTNode * p;

	p = root;
	while ((p != &S) && (p->key != k))
		if (k < p->key) p = p->left;
		else           p = p->right;
		if (p == &S) return NULL;
		return p;
}

RBTNode * RBTree::minRBT(RBTNode * p)
{
	if (p != &S)
		while (p->left != &S) p = p->left;
	return p;
}

RBTNode * RBTree::succRBT(RBTNode * p)
{
	RBTNode * r;

	if (p != &S)
	{
		if (p->right != &S) return minRBT(p->right);
		else
		{
			r = p->up;
			while ((r != &S) && (p == r->right))
			{
				p = r;
				r = r->up;
			}
			return r;
		}
	}
	return &S;
}

void RBTree::rot_L(RBTNode * A)
{
	RBTNode * B, *p;

	B = A->right;
	if (B != &S)
	{
		p = A->up;
		A->right = B->left;
		if (A->right != &S) A->right->up = A;

		B->left = A;
		B->up = p;
		A->up = B;

		if (p != &S)
		{
			if (p->left == A) p->left = B; else p->right = B;
		}
		else root = B;
	}
}

void RBTree::rot_R(RBTNode * A)
{
	RBTNode * B, *p;

	B = A->left;
	if (B != &S)
	{
		p = A->up;
		A->left = B->right;
		if (A->left != &S) A->left->up = A;

		B->right = A;
		B->up = p;
		A->up = B;

		if (p != &S)
		{
			if (p->left == A) p->left = B; else p->right = B;
		}
		else root = B;
	}
}

void RBTree::insertRBT(int k)
{
	RBTNode * X, *Y;

	X = new RBTNode;
	X->left = &S;
	X->right = &S;
	X->up = root;
	X->key = k;
	if (X->up == &S) root = X;
	else
		while (true)
		{
			if (k < X->up->key)
			{
				if (X->up->left == &S)
				{
					X->up->left = X;
					break;
				}
				X->up = X->up->left;
			}
			else
			{
				if (X->up->right == &S)
				{
					X->up->right = X;
					break;
				}
				X->up = X->up->right;
			}
		}
	X->color = 'R';
	while ((X != root) && (X->up->color == 'R'))
	{
		if (X->up == X->up->up->left)
		{
			Y = X->up->up->right;

			if (Y->color == 'R')
			{
				X->up->color = 'B';
				Y->color = 'B';
				X->up->up->color = 'R';
				X = X->up->up;
				continue;
			}

			if (X == X->up->right)
			{
				X = X->up;
				rot_L(X);
			}

			X->up->color = 'B';
			X->up->up->color = 'R';
			rot_R(X->up->up);
			break;
		}
		else
		{
			Y = X->up->up->left;

			if (Y->color == 'R')
			{
				X->up->color = 'B';
				Y->color = 'B';
				X->up->up->color = 'R';
				X = X->up->up;
				continue;
			}

			if (X == X->up->left)
			{
				X = X->up;
				rot_R(X);
			}

			X->up->color = 'B';
			X->up->up->color = 'R';
			rot_L(X->up->up);
			break;
		}
	}
	root->color = 'B';
}

void RBTree::removeRBT(RBTNode * X)
{
	RBTNode * W, *Y, *Z;

	if ((X->left == &S) || (X->right == &S)) Y = X;
	else Y = succRBT(X);

	if (Y->left != &S) Z = Y->left;
	else              Z = Y->right;

	Z->up = Y->up;

	if (Y->up == &S) root = Z;
	else if (Y == Y->up->left) Y->up->left = Z;
	else                      Y->up->right = Z;

	if (Y != X) X->key = Y->key;

	if (Y->color == 'B')
		while ((Z != root) && (Z->color == 'B'))
			if (Z == Z->up->left)
			{
				W = Z->up->right;

				if (W->color == 'R')
				{
					W->color = 'B';
					Z->up->color = 'R';
					rot_L(Z->up);
					W = Z->up->right;
				}

				if ((W->left->color == 'B') && (W->right->color == 'B'))
				{
					W->color = 'R';
					Z = Z->up;
					continue;
				}

				if (W->right->color == 'B')
				{
					W->left->color = 'B';
					W->color = 'R';
					rot_R(W);
					W = Z->up->right;
				}

				W->color = Z->up->color;
				Z->up->color = 'B';
				W->right->color = 'B';
				rot_L(Z->up);
				Z = root;
			}
			else
			{
				W = Z->up->left;

				if (W->color == 'R')
				{
					W->color = 'B';
					Z->up->color = 'R';
					rot_R(Z->up);
					W = Z->up->left;
				}

				if ((W->left->color == 'B') && (W->right->color == 'B'))
				{
					W->color = 'R';
					Z = Z->up;
					continue;
				}

				if (W->left->color == 'B')
				{
					W->right->color = 'B';
					W->color = 'R';
					rot_L(W);
					W = Z->up->left;
				}

				W->color = Z->up->color;
				Z->up->color = 'B';
				W->left->color = 'B';
				rot_R(Z->up);
				Z = root;
			}

	Z->color = 'B';

	delete Y;
}


