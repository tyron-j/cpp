#include <stack>
#include <string>
#include <fstream>

class IOStack {
public:
	// max number of operations
	static const int NumOperations = 500000;

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

	// incrememt "numBotItems" bottom elements by "incValue"
	void Inc(int numBotItems, int incValue);

	void Output();
	void Interpret(std::string Operation);
};