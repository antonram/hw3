#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
typename std::vector<T> items;
int m_;
PComparator c_;
void trickleDown(size_t root);
void trickleUp(size_t root);


};

// Add implementation of member functions here


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("heap is empty");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return items[0];


}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
     throw std::underflow_error("heap is empty");

  }

  //following buildHeap, we first copy last item into first
  items[0] = items[items.size()-1];

  //then we eliminate last item
  items.pop_back();

  //then we trickle down
  trickleDown(0);

}


//assign values to data members
template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c) 
: m_(m), c_(c) 
{ }


// no need to destroy anything...
template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap() 
{ }


template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item) {
  //first we add item to the end
  items.push_back(item);

  //then we trickleUp to corresponding spot
  trickleUp(items.size()-1);
}


template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const {
  //if items is empty, return true
  if(items.size() == 0) {
    return true;
  }
  //else return false
  return false;
}


template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const {
  //return size of items vector
  return items.size();
}


template <typename T, typename PComparator>
void Heap<T,PComparator>::trickleDown(size_t root) {
	size_t childIndex = root*m_ + 1;
	//if no child, return
	if(childIndex > items.size()) {
		return;
	}
	T child = items[childIndex];

	//find best child and store it in child
	size_t i = childIndex+1;
	while((i <= (root*m_ + m_)) && (i < items.size())) {
		// if new node better, set child to new node
		if(c_(items[i], child)) {
			child = items[i];
			childIndex = i;
		}
		i++;
	}

	// if "best" child has priority over parent, swap the two and call trickleDown again on childIndex
	if(c_(child, items[root])) {
		items[childIndex] = items[root];
		items[root] = child;
		trickleDown(childIndex);
	}
}


template <typename T, typename PComparator>
void Heap<T,PComparator>::trickleUp(size_t root) {
	//if at origin, just return
	if(root == 0) {
		return;
	}
	T parent;
	size_t parentIndex;

	//find parent
	parentIndex = (root-1)/m_;
	parent = items[parentIndex];

	// if child is better
	if(c_(items[root], parent)) {
		//swap child and parent
		items[parentIndex] = items[root];
		items[root] = parent;
		//and call trickleUp again on parentIndex
		trickleUp(parentIndex);
	}
}

#endif

