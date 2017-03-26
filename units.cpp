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

void Bheap::goUp(int index)
{
	if (index == 0)
		return;

	int parent = (index - 1) / 2;

	if (_vector[parent] < _vector[index])
	{
		int temp = _vector[parent];
		_vector[parent] = _vector[index];
		_vector[index] = temp;
		goUp(parent);
	}
}

void Bheap::addElem(int elem)
{
	int length = _vector.size();
	_vector.push_back(elem);
	goUp(length);
}

void Bheap::removeRoot()
{
	int length = _vector.size();

	if (length == 0)
		return;

	_vector[0] = _vector[length - 1];
	goUp(0);
}

void Bheap::printHeap(std::string sp, std::string sn, int v)
{
	std::string cr, cl, cp;
	cr = cl = cp = "  ";
	cr[0] = 218; cr[1] = 196;
	cl[0] = 192; cl[1] = 196;
	cp[0] = 179;

	std::string s;

	if (v < _vector.size())
	{
		s = sp;
		if (sn == cr) s[s.length() - 2] = ' ';
		printHeap(s + cp, cr, 2 * v + 2);

		s = s.substr(0, sp.length() - 2);

		std::cout << s << sn << _vector[v] << std::endl;

		s = sp;
		if (sn == cl) s[s.length() - 2] = ' ';
		printHeap(s + cp, cl, 2 * v + 1);
	}
}
