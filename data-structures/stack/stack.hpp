#include <ostream>
#include <iostream>
#include <stdexcept>
#include "stack.h"

using namespace ds;

/**
 * Capacity
 */

template <typename T>
int Stack<T>::size() const{
  return list->size();
}

template <typename T>
bool Stack<T>::isEmpty(){
  return list->isEmpty();
}

/**
 * Element Access
 */

template <typename T>
const T& Stack<T>::top() const{
  // Return the top element in the stack
  // O(1)
  return list->front(); 
}


template <typename T>
void Stack<T>::push(const T& value){
  /**
   * Pushes an element to the front of the list
   * O(1)
   */
  list->push_front(value);
}

template <typename T>
void Stack<T>::pop(){
  /**
   * Remove the first element of the list
   * O(1)
   */
  list->pop_front();
}
