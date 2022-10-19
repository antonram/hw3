#include <iostream>
#include <fstream>
#include <functional>
#include "stack.h"
using namespace std;

int main(int argc, char* argv[])
{
	Stack<int> stack;
	stack.push(5);
	cout << stack.top() << endl;
	cout << stack.size() << endl;
	cout << stack.empty() << endl;
	stack.push(10);
	cout << stack.top() << endl;
	cout << stack.size() << endl;
	stack.pop();
	cout << stack.top() << endl;
	cout << stack.size() << endl;


	return 0;
}