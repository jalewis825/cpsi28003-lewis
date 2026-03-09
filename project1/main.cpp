#include <iostream>
using namespace std;
#include "doublylinkedlist.h"

int main()
{
	// test case 1
	// Create a doubly linked list
	DoublyLinkedList Dll_1;
	
	// Each node contains only one integer of a string
	Node n11(10);
	Node n12(20);
	Node n13(30);
	Node n14(40);
	Node n15(50);

	// a doubly linked list of integers by inserting nodes
	Dll_1.addNewNodeToFront(&n11);
	Dll_1.addNewNodeToFront(&n12);
	Dll_1.addNewNodeToFront(&n13);
	Dll_1.addNewNodeToFront(&n14);
	Dll_1.addNewNodeToFront(&n15);

	cout << Dll_1.isPalindrome() << endl;


	// test case 2
	// Create a doubly linked list
	DoublyLinkedList Dll_2;
	
	// Each node contains only one integer of a string
	Node n21(10);
	Node n22(20);
	Node n23(20);
	Node n24(10);

	// a doubly linked list of integers by inserting nodes
	Dll_2.addNewNodeToFront(&n21);
	Dll_2.addNewNodeToFront(&n22);
	Dll_2.addNewNodeToFront(&n23);
	Dll_2.addNewNodeToFront(&n24);

	cout << Dll_2.isPalindrome() << endl;

	system("PAUSE");
	return 0;
}
