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
Main driver program used to test the functionality of the
DoublyLinkedList class including drawing a pictorial view
of the list with node addresses, palindrome detection,
splitting the list into evenly sized sublists, and inserting
a new node before a target node.
Date Written: 08 March 2026
Date Revised: 09 March 2026
*********************************************************************/

#include <iostream>
using namespace std;

#include "Node.h"
#include "doublylinkedlist.h"

int main()
{
	/**********************************************************
	 Test 1: drawDoublyLinkedList()
	 *********************************************************/
	cout << "Test 1: drawDoublyLinkedList()" << endl;

	DoublyLinkedList Dll_0;

	Node d1(10);
	Node d2(20);
	Node d3(30);
	Node d4(40);
	Node d5(50);

	Dll_0.addNewNodeToFront(&d1);
	Dll_0.addNewNodeToBack(&d2);
	Dll_0.addNewNodeToFront(&d3);
	Dll_0.addNewNodeToBack(&d4);
	Dll_0.addNewNodeToFront(&d5);

	Dll_0.drawDoublyLinkedList();
	cout << endl;

	/**********************************************************
	 Test 2: isPalindrome() - should print 0
	 *********************************************************/
	cout << "Test 2: isPalindrome() non-palindrome" << endl;

	DoublyLinkedList Dll_1;

	Node n11(10);
	Node n12(20);
	Node n13(30);
	Node n14(40);
	Node n15(50);

	Dll_1.addNewNodeToFront(&n11);
	Dll_1.addNewNodeToFront(&n12);
	Dll_1.addNewNodeToFront(&n13);
	Dll_1.addNewNodeToFront(&n14);
	Dll_1.addNewNodeToFront(&n15);

	cout << Dll_1.isPalindrome() << endl
		 << endl;

	/**********************************************************
	 Test 3: isPalindrome() - should print 1
	 *********************************************************/
	cout << "Test 3: isPalindrome() palindrome" << endl;

	DoublyLinkedList Dll_2;

	Node n21(10);
	Node n22(20);
	Node n23(20);
	Node n24(10);

	Dll_2.addNewNodeToFront(&n21);
	Dll_2.addNewNodeToFront(&n22);
	Dll_2.addNewNodeToFront(&n23);
	Dll_2.addNewNodeToFront(&n24);

	cout << Dll_2.isPalindrome() << endl
		 << endl;

	/**********************************************************
	 Test 4: split(3) with 6 nodes
	 *********************************************************/
	cout << "Test 4: split(3) with 6 nodes" << endl;

	DoublyLinkedList *Dll_3;
	Dll_3 = new DoublyLinkedList;

	Node n31(1);
	Node n32(2);
	Node n33(3);
	Node n34(4);
	Node n35(5);
	Node n36(6);

	Dll_3->addNewNodeToBack(&n31);
	Dll_3->addNewNodeToBack(&n32);
	Dll_3->addNewNodeToBack(&n33);
	Dll_3->addNewNodeToBack(&n34);
	Dll_3->addNewNodeToBack(&n35);
	Dll_3->addNewNodeToBack(&n36);

	Dll_3->split(3);
	cout << endl;

	/**********************************************************
	 Test 5: split(3) with 7 nodes - cannot be processed
	 *********************************************************/
	cout << "Test 5: split(3) with 7 nodes" << endl;

	DoublyLinkedList *Dll_4;
	Dll_4 = new DoublyLinkedList;

	Node n41(1);
	Node n42(2);
	Node n43(3);
	Node n44(4);
	Node n45(5);
	Node n46(6);
	Node n47(7);

	Dll_4->addNewNodeToBack(&n41);
	Dll_4->addNewNodeToBack(&n42);
	Dll_4->addNewNodeToBack(&n43);
	Dll_4->addNewNodeToBack(&n44);
	Dll_4->addNewNodeToBack(&n45);
	Dll_4->addNewNodeToBack(&n46);
	Dll_4->addNewNodeToBack(&n47);

	Dll_4->split(3);
	cout << endl;

	/**********************************************************
	 Test 6: addNewNodeBeforeTargetNode()
	 Expected: 11 22 33 77 44 55 66
	 *********************************************************/
	cout << "Test 6: addNewNodeBeforeTargetNode()" << endl;

	DoublyLinkedList *Dll_5;
	Dll_5 = new DoublyLinkedList;

	Node n51(11);
	Node n52(22);
	Node n53(33);
	Node n54(44);
	Node n55(55);
	Node n56(66);

	Dll_5->addNewNodeToBack(&n51);
	Dll_5->addNewNodeToBack(&n52);
	Dll_5->addNewNodeToBack(&n53);
	Dll_5->addNewNodeToBack(&n54);
	Dll_5->addNewNodeToBack(&n55);
	Dll_5->addNewNodeToBack(&n56);

	Node n57(77);
	Dll_5->addNewNodeBeforeTargetNode(&n57, 44);

	Node n58(88);
	Dll_5->addNewNodeBeforeTargetNode(&n58, 29);

	Dll_5->displayDoublyLinkedList();
	cout << endl
		 << endl;

	system("PAUSE");
	return 0;
}