#include <iostream>
#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList(int FirstNodeData) {
	FirstNode.Data = FirstNodeData;
	Length = 1;
}

void LinkedList::Add(int NewNodeData) {
	Node * CurrentNode = &FirstNode; // point to first node
	Node& NextNode = *(new Node); // get reference to new node

	NextNode.Data = NewNodeData;
	NextNode.Next = NULL;

	while ((*CurrentNode).Next != NULL) {
		CurrentNode = (*CurrentNode).Next;
	}

	(*CurrentNode).Next = &NextNode; // current node's next property points to the memory location of next node

	Length++;
}

void LinkedList::Iterate() {
	Node * CurrentNode = &FirstNode;

	cout << "The values in the linked list are:" << endl;
	cout << (*CurrentNode).Data << endl;

	while ((*CurrentNode).Next != NULL) {
		CurrentNode = (*CurrentNode).Next;

		cout << (*CurrentNode).Data << endl;
	}
}