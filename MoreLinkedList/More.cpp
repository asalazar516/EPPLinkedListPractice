//File Name		More.cpp
//Name			Adrian Salazar
//Date			11/4/2016
//Assignment	More Linked List
//Create a linked list that is able to count the size, add the
//total inside the nodes, copy it into an independent list,
//and reverse the list
//====================================================================

#include <iostream>
#include <ctime>

using namespace std;

// CLASS DECLARATION==================================================
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
///======================================================================

//=====================PROTOTYPE FUNCTIONS==============================

// Add a node in the list
void insert(NodeType * &headPtr, int value);

// Search and delete a node in the list (Recursive)
void searchAndDelete(NodeType * &headPtr, int value);

// Create an empty list
void DeleteList(NodeType * &headPtr);

// Print function (Recursive)
void print(NodeType * headPtr);

// Print function for constant list(Recursive)
void C_print(const NodeType * headPtr);

// Return the size of the list
int count(NodeType * headptr);

// Adding the nodes in the list and returning the total
int sum(NodeType * headptr);

// Create a copy of the list
const NodeType * copy(NodeType * headptr);

// Reverse the list
NodeType * reverse(NodeType * headptr);

//Helper function for copy
void CopyHelper(NodeType * &headPtr, int value);

void InsertAtBack(NodeType * &headPtr, int value);

NodeType * Merged(NodeType * &headPtr, NodeType * &headPtr2);

//Recursively print odd position in the list
void OddPrint(NodeType * headPtr, int counter);

//======================================================================

//BEGIN MAIN()==========================================================
int main()
{
	//Initalization
	const int SIZE = 10; //Maximum size for the list
	NodeType * List = NULL;
	NodeType * List2 = NULL;
	NodeType * List3 = NULL;
    const NodeType * Copy = NULL;
	int ListCounter, ListSum, random[SIZE], userSize, random2[SIZE];

	//Creating a random number generator
	srand(time(NULL));

	//Asking for the size of the list
	cout << "How many integers would you like in the list (less or equal to 10): ";
	cin >> userSize;

	//Check if user input is less than max size
	while (userSize > SIZE){
		cout << "Array requested too large. Enter again: ";
		cin >> userSize;
	}

	cout << "Entering " << userSize << " random numbers in the linked list\n";
	for (int i = 0; i < userSize; i++)
	{
		random[i] = rand() % 100 + 1;
		random2[i] = rand() % 100 + 1;
	}

	//Inserting array to list
	for (int i = 0; i < userSize; i++)
	{
		insert(List, random[i]);
		insert(List2, random2[i]);
	}

	//Display list
	cout << "\nPrint list" << endl;
	print(List);

	cout << "NULL\n" << endl;

	cout << "\nPrint list 2" << endl;
	print(List2);

	cout << "NULL\n" << endl;

	cout << "\n Print list 1, but only in the odd position placed.\n";

	OddPrint(List, userSize);

	cout << "NULL\n";

	//Merge List
	List3 = Merged(List, List2);

	cout << "\nPrint merged list " << endl;
	print(List3);

	cout << "NULL\n" << endl;

	//Count the list
	ListCounter = count(List);

	cout << "The list counter is " << ListCounter << endl <<endl;

	ListSum = sum(List);

	cout << "The sum of all integers stored in nodes in the list is " << ListSum << endl << endl;

	//Copy merged list
	Copy = copy(List);

	cout << "Copy list\n";
	C_print(Copy);

	cout << "NULL\n";

	//Display merged list reversed
	List3 = reverse(List);
	cout << "\nList has been reversed.\n\nPrinted original list in reversed\n";
	print(List3);

	//Delete list
	DeleteList(List);
	cout << "NULL\n\nOriginal list has been DELETED!\n";
	cout << endl;

	cout << "Let's check if the original list is empty.\n";
	print(List);

	cout << "Here is the copy list again\n";
	C_print(Copy);
	cout << "NULL\n\n";

	//Stop Program
	system("pause");

	//Close program
	return 0;

}//END MAIN()

//======================FUNCTION DEFINITIONS============================

void insert(NodeType *& headPtr, int value)
{
	NodeType * currentPtr = new NodeType;
	currentPtr->info = value;
	currentPtr->nextPtr = headPtr;
	headPtr = currentPtr;
}

void searchAndDelete(NodeType * &headPtr, int value)
{
	if (headPtr == NULL)
	{
		cout << "not found\n" << endl;
	}
	else if (headPtr->info == value)
	{
		NodeType * next = new NodeType;
		next = headPtr;
		headPtr = headPtr->nextPtr;
		delete next;
	}
	else
	{
		searchAndDelete(headPtr->nextPtr, value);
	}
}

void DeleteList(NodeType * &headPtr)
{
	if (headPtr == NULL)
	{
		cout << "List is deleted." << endl;
	}

	else
	{
		headPtr = NULL;
	}

}

void print(NodeType * headPtr)
{
	if (!headPtr)
		cout << "List is empty.\n\n";

	while (headPtr != NULL)
	{
		cout << "[ " << headPtr->info << " ]->";
		headPtr = headPtr->nextPtr;
	}


}

void C_print(const NodeType * headPtr)
{
	if (headPtr != NULL)
	{
		cout << "[ " << headPtr->info << " ]->";
		C_print(headPtr->nextPtr);
	}

}

int count(NodeType * headPtr)
{
	int counter = 0;
	if (headPtr == NULL)
	{
		return counter;

	}
	else
	{
		counter++;
		return counter + count(headPtr->nextPtr);
	}

}

int sum(NodeType * headPtr)
{
	if (headPtr == NULL)
		return 0;
	else
		return headPtr->info + sum(headPtr->nextPtr);
}

const NodeType * copy(NodeType * headptr)
{
	NodeType * ListCopy = new NodeType;
	int value;

	while (headptr != NULL)
	{
		
		value = headptr->info;
		if (value != 0)
		{
			CopyHelper(ListCopy, value);

			headptr = headptr->nextPtr;
		}
		
	}
	searchAndDelete(ListCopy, 0);
	return ListCopy;
	
}

void CopyHelper(NodeType * &headPtr, int value)
{
	if (headPtr == NULL || headPtr->nextPtr == NULL)
	{
		NodeType * currentPtr = new NodeType;
		currentPtr->info = value;
		currentPtr->nextPtr = headPtr;
		headPtr = currentPtr;
		return;
	}
	else
		InsertAtBack(headPtr->nextPtr, value);
}

void InsertAtBack(NodeType *& headPtr, int value)
{
	if (headPtr->nextPtr != NULL)
	{
		InsertAtBack(headPtr->nextPtr, value);
	}
	else
	{
		NodeType * currentPtr = new NodeType;
		headPtr->nextPtr = currentPtr;
		headPtr->nextPtr->info = value;
		headPtr->nextPtr->nextPtr = NULL;
	}

}

NodeType * reverse(NodeType *  headPtr)
{
	if (headPtr->nextPtr == NULL) {
		return headPtr;
	}
	else {
		NodeType * t = reverse(headPtr->nextPtr); // Now p->next is reversed, t is the new head.
		headPtr->nextPtr->nextPtr = headPtr; // p->next is the current tail, so p becomes the new tail.
		headPtr->nextPtr = NULL;
		return t;
	}
}


NodeType * Merged(NodeType * &headPtr, NodeType * &headPtr2)
{
	NodeType * currentPtr = new NodeType;
	int value;
	
	if (headPtr == NULL)
	{
		return headPtr2;
	}
	else if (headPtr2 == NULL)
	{
		return headPtr;
	}
	else	while (headPtr2 != NULL)
	{
		value = headPtr2->info;
		InsertAtBack(headPtr, value);
		headPtr2 = headPtr2->nextPtr;
		
	}
	return headPtr;
}

void OddPrint(NodeType * headPtr, int counter)
{
	if (headPtr == NULL)
	{
		;
	}
	if (headPtr != NULL && counter % 2 == 0)
	{
		counter = counter--;
		OddPrint(headPtr->nextPtr, counter);
	}
	else if (headPtr != NULL && counter % 2 == 1)
	{
		cout << "[ " << headPtr->info << " ]->";
		counter = counter--;
		OddPrint(headPtr->nextPtr, counter);
	}
}

//======================================================================
