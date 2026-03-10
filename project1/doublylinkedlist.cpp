/*********************************************************************
University of Arkansas at Little Rock
Department of Computer Science
CPSI 28003 - 9S1: Algorithms
Spring 2026
Project 1: Doubly Linked List
Due Date: March 10, 2026, Tuesday
Name: Jessi Lewis
ID (Last 4 Digits):39929
Description of the Program:
Implementation of the DoublyLinkedList class. This file
contains the logic for the drawing of the address, palindrome
detection, splitting a list into equal sublists, and inserting
noes before a target node.
Date Revised: 9 March 2026
*********************************************************************/

#ifndef DOUBLYLINKEDLIST_CPP
#define DOUBLYLINKEDLIST_CPP

#include "doublylinkedlist.h"

DoublyLinkedList::DoublyLinkedList()
{
	head = NULL;
	tail = NULL;
}

DoublyLinkedList::~DoublyLinkedList()
{
}

void DoublyLinkedList::addNewNodeToFront(Node *newNode)
{
	if (head == NULL && tail == NULL)
	{
		head = tail = newNode;
	}
	else
	{
		head->prev = newNode;
		newNode->next = head;
		head = newNode;
	}
}

void DoublyLinkedList::addNewNodeToBack(Node *newNode)
{
	if (head == NULL && tail == NULL)
	{
		head = tail = newNode;
	}
	else
	{
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
}

Node *DoublyLinkedList::removeNodeFromFront()
{
	Node *tempNode;

	tempNode = head;
	head = head->next;
	return tempNode;
}

void DoublyLinkedList::displayDoublyLinkedList()
{
	Node *tempNode;

	tempNode = head;
	while (tempNode != NULL)
	{
		cout << tempNode->value << " ";
		tempNode = tempNode->next;
	}
}

/*This function prints a pictorial representation of the doubly linked list.
For each node, it displays the node's memory address, the address of the
previous node, the stored value, and the address of the next node.*/
void DoublyLinkedList::drawDoublyLinkedList()
{
	/*Create a temporary pointer that starts at the head of the list.
	This pointer will be used to traverse the doubly linked list
	without modifying the actual head pointer.*/
	Node *tempNode = head;

	// Traverse the list until we reach the end (NULL).
	while (tempNode != NULL)
	{
		// Print the memory address of the current node
		cout << "[address: " << tempNode

			 // Print the address of the previous node.
			 // If there is no previous nod (prev == NULL), print 0 to indicate beginning of the list.
			 << ", prev: " << (tempNode->prev ? tempNode->prev : 0)

			 // Print the value stored in the current node.
			 << ", value: " << tempNode->value

			 // Print the address of the next node.
			 // If there is no next node (next == NULL), print 0 to indicate end of list
			 << ", next: " << (tempNode->next ? tempNode->next : 0)

			 << "]" << endl;

		/*Move the pointer to the next node in the list.
		This allows us to continue traversing the list.*/
		tempNode = tempNode->next;
	}
}

/*This function checks whether the doubly linked list forms a palindrome.
It compares node values from the front and back simultaneously
and returns true if all matching pairs are equal*/
bool DoublyLinkedList::isPalindrome()
{
	// An empty list is considered a palindrome.
	if (head == NULL)
	{
		return true;
	}
	/*Use two pointers:
	left starts at the front of the list,
	right starts at the back of the list.*/
	Node *left = head;
	Node *right = tail;

	/*Compare matching noes from the outside moving in.
	Stop when the pointers meet or cross.*/
	while (left != right && left->prev != right)
	{
		if (left->value != right->value)
		{
			return false;
		}

		// Move both pointers toward the middle of the list
		left = left->next;
		right = right->prev;
	}

	// If all matching pars were equal, the list is a palindrome.
	return true;
}

/*This function splits the doubly linked list into n 
evenly sized sublists.If the list cannot be evenly divided
or n is invalid, it prints "List cannot be processed." */
void DoublyLinkedList::split(int n)
{
	// Creat a temporary pointer to navigate the list.
	Node *tempNode = head;

	// count stores the total number of nodes in the list.
	int count = 0;

	/*subListSize stores how many nodes should appear in
	each evenly split sublist.*/
	int subListSize = 0;

	// Step 1: Counts the number of nodes in the list
	while (tempNode != NULL)
	{
		count++;
		tempNode = tempNode->next;
	}

	/*Step 2: Validate whether the list can be split evenly
	The split cannot be proccessed if:
	1. n is less than 1
	2. n is greater than the number of nodes
	3. the list size is not evenly divisable by n*/
	if (n < 1 || n > count || count % n != 0)
	{
		cout << "List cannot be processed." << endl;
		return;
	}
	//Step 3: Compute the size of each sublist
	else
	{
		subListSize = count / n;
		cout << n << " evenly split sub-doubly linked lists:" << endl;
	}
// Rest tempNode back to the head so the list can be gone over again.
	tempNode = head;

	/*Step 4: Print the list in equal partitions
	Outer loop controls how many sublists are printed*/
	for (int i = 0; i < n; i++)
	{
		//Inner loop prints the nodes belonging to one sublist
		for (int j = 0; j < subListSize; j++)
		{
			cout << tempNode->value << " ";
			tempNode = tempNode->next;
		}

		//Move to the next line before printing another list.
		cout << endl;
	}
}

/*This function inserts a new node before the first node whose value matches val.
If the targe value is found, the new node is linked into the list;
otherwise the list remains unchanged.*/
void DoublyLinkedList::addNewNodeBeforeTargetNode(Node *newNode, int val)
{
	//Start at the head of the list and search for the target value
	Node *tempNode = head;

	//Navigate the list until the target node is found or the end is reached.
	while (tempNode != NULL)
	{
		//If the target value is found, insert newNode before tempNode.
		if (tempNode->value == val)
		{
			//Special case: Inserting before the head node
			if (tempNode == head)
			{
				newNode->prev = NULL; //new head has no previous node
				newNode->next = head; //link new node to old head
				head->prev = newNode; // old head points back to new node
				head = newNode; 	  //update head to the new front node
			}
			//Normal Case: insert before a node in the middle of the list
			else
			{
				newNode->prev = tempNode->prev; //link new node to previous node
				newNode->next = tempNode;       //link new node to target node
				tempNode->prev->next = newNode; //previous node points forward to new node
				tempNode->prev = newNode;       //target node points back to new node
			}
			//Stop once insertion is complete.
			return;
		}
		//move to next node if target has not been found
		tempNode = tempNode->next;
	}
	//If target is not found, no changes are made to the list
}

#endif