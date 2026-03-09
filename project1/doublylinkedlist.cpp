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

void DoublyLinkedList::addNewNodeToFront(Node * newNode) {
	if(head == NULL && tail == NULL) {
		head = tail = newNode;
	} else {
		head->prev = newNode;
		newNode->next = head;
		head = newNode;
	}
}

void DoublyLinkedList::addNewNodeToBack(Node * newNode) {
	if(head == NULL && tail == NULL) {
		head = tail = newNode;
	} else {
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
}

Node* DoublyLinkedList::removeNodeFromFront()
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

void DoublyLinkedList::drawDoublyLinkedList()
{
	//create a pointer named tempNode that starts at head
  Node* tempNode = head; 
	//while tempNode is not equal NULL do the following loop
   while (tempNode != NULL)
   {
	//print out current address of tempNode
	cout << "[address: " << tempNode 
		//if tempNode points to previous then tempNode points to previous address, if not, value is 0
		 << ", prev: " << (tempNode->prev ? tempNode->prev : 0)  
		 //print out value stored at tempNode
		 << ", value: " << tempNode->value
		 //if tempNode points to next then tempNode points to next address, if not, value is 0
		 << ", next: " << (tempNode->next ? tempNode->next : 0)
		 << "]" << endl;

    tempNode = tempNode->next;
   }
}

bool DoublyLinkedList::isPalindrome()
{
	//check if the list is empty; if there are no nodes, head doesn't point to anything & list is empty
	if(head == NULL) {
		return true;
	}
	
	Node* left = head;
	Node* right = tail; 
while(true){
	if(left->value != right->value) {
		return false;
	}
	
}
	
}


#endif