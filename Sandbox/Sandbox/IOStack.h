#include <stack>
#include <string>
#include <fstream>

class IOStackNode {
public:
	int Data;

	IOStackNode(int NewData) {
		Data = NewData;
	};

	IOStackNode * Next;
	IOStackNode * Prev;
};

class IOStack {
public:
	// max number of operations
	static const int NumOperations = 500000;

	// nodes
	IOStackNode * First;
	IOStackNode * Last;

	// number of items; initially empty
	int NumItems = 0;

	std::ifstream MyFile;

	// to-do: remove
	std::string Operations[NumOperations];

	// to-do: remove
	std::stack <int> MyStack;

	IOStack(std::string FileName);

	// standard stack operations
	void Peek();
	void Pop();
	void Push(int Number);

	// incrememt "NumBotItems" bottom elements by "IncValue"
	void Inc(int NumBotItems, int IncValue);

	void Output();
	void Interpret(std::string Operation);
};