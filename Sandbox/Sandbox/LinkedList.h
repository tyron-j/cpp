// to-do: currently only supports int values; use generic templates
class Node {
public:
	int Data;
	Node * Next;
};

class LinkedList {
public:
	int Length;
	Node FirstNode;

	LinkedList(int FirstNodeData);

	void Add(int NewNodeData);
	void Iterate();
};