#include <ostream>
#include <iostream>
#include <stdexcept>
#include "queue.h"

using namespace ds;

/**
 * Capacity
 */

template <typename T>
int Queue<T>::size() const{
  return data->size();
}

template <typename T>
bool Queue<T>::isEmpty(){
  return data->isEmpty();
}

/**
 * Element Access
 */

template <typename T>
const T& Queue<T>::front() const{
  // Return the top element in the queue
  // O(1)
  return data->front(); 
}

template <typename T>
const T& Queue<T>::back() const{
  // Return the end element in the queue
  // O(1)
  return data->back(); 
}


template <typename T>
void Queue<T>::push(const T value){
  /**
   * Insert an element to the end of the queue
   * O(1)
   */
  data->push_back(value);
}

template <typename T>
void Queue<T>::pop(){
  /**
   * Remove the first element of the queue
   * O(1)
   */
  data->pop_front();
}
