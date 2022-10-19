#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : private std::vector<T>
{
public:
  Stack();
  ~Stack();
  bool empty() const;
  size_t size() const;
  void push(const T& item);
  void pop();  // throws std::underflow_error if empty
  const T& top() const; // throws std::underflow_error if empty
  // Add other members only if necessary
};

template <typename T>
Stack<T>::Stack()
{    
}

template <typename T>
Stack<T>::~Stack() {
}

template <typename T>
bool Stack<T>::empty() const {
  //if no items, then empty
  if(size() == 0) {
      return true;
  }
  //else, not empty
  return false;
}

template <typename T>
void Stack<T>::push(const T& item) {
	//we just add the item
	this->std::vector<T>::push_back(item);
}

template <typename T>
void Stack<T>::pop() {
	//if empty, error
	if(size() == 0) {
		throw std::underflow_error("stack is empty");
	}
	//eliminate item
	this->std::vector<T>::pop_back();
}

template <typename T>
T const & Stack<T>::top() const {
	//if empty, error
	if(size() == 0) {
		throw std::underflow_error("stack is empty");
	}
	//return top item (last item since using vector)
  return (*this)[this->std::vector<T>::size()-1];
}

template <typename T>
size_t Stack<T>::size() const {
	//return size of the vector/stack
	return this->std::vector<T>::size();
}


#endif