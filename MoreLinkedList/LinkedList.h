#ifndef LIST_H
#define LIST_H

#include <iostream>

class NodeType {
public:
	NodeType(int = 0); // constructor with default value for
	// info field
	int info; // data
	NodeType * nextPtr; // pointer to next node in the list
};

//CLASS DEFINITION -------------------------------
// Constructor
NodeType::NodeType(int data)
{
	info = data;
	nextPtr = nullptr;
}
//======================================================================

class Linkedlist
{
public:
	Linkedlist();
	void InsertAtLast(int value);
	void Print();
	void InsertAtFront(int value);
	void DeleteAtFront();
	int count();
	int sum();
	Linkedlist Merge(Linkedlist &List1, Linkedlist &List2);
	bool Split(Linkedlist &list1, Linkedlist &list2);

private:
	NodeType * First;
	NodeType * Last;
	int length;

};

Linkedlist::Linkedlist()
{
	First = nullptr;
	Last = nullptr;
	length = 0;
}

void Linkedlist::InsertAtLast(int value)
{
	NodeType* current = new NodeType;
	current->info = value;
	current->nextPtr = NULL;
	Last = current;
	length++;
}

void Linkedlist::Print()
{
	while (First != NULL)
	{
		cout << "[ " << First->info << " ] ->";
		First = First->nextPtr;
	}
}

void Linkedlist::InsertAtFront(int value)
{
	NodeType * current = new NodeType;
	current->info = value;
	First = current;
	length++;
}

void Linkedlist::DeleteAtFront()
{
	NodeType * NewHead = First->nextPtr;
	delete First;
	First = NewHead;
	length--;
}

int Linkedlist::count()
{
	return length;
}



#endif