/**
 *
 */
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <math.h>
#include "linkedlist.h"

using namespace ds;

/**
 * Capacity
 */

template <typename T>
int LinkedList<T>::size() const{
  return len;
}

template <typename T>
bool LinkedList<T>::isEmpty(){
  return len == 0;
}

/**
 * Modifiers
 */

template <typename T>
void LinkedList<T>::push_front(const T & data){
  /**
   * Insert a new node at the front of the list
   * O(1) thanks to the head pointer
   */

  // create a new node in the heap and set its next pointer to point to the current head
  Node * new_node = new Node(data, head);
  // move the head to the new node
  head = new_node;
  len++;
}

template <typename T>
void LinkedList<T>::insert_at(const T & data, int index){
  /**
   * Insert a new node at a specific location
   * O(n) in the worst case we will traverse the list to get the node at the specified index
   */

  if (index < 0 || index > len){throw std::out_of_range("Index out of range");}

  if (index == 0){
    LinkedList<T>::push_front(data);
    return;
  }

  // create new node
  Node * new_node = new Node(data);

  // get the node at index -1
  Node * prev = LinkedList<T>::get(index-1);

  // set the next pointer of the new node to the current node at index
  new_node->next = prev->next;
  // update the next pointer of the node at index-1
  prev->next = new_node;
  len++;
}

template <typename T>
void LinkedList<T>::push_back(T const & data){
  /**
   * Insert new node at the end of the listi
   * O(n) because we need to find the last node
   */

  // create the new node
  Node * new_node = new Node(data);

  // If the list is empty, make the new node as head
  if (len == 0){
    head = new_node;
  }
  else{
    Node * thru = head;
    while (thru->next != nullptr){
      thru = thru->next;
    }
    // change the next pointer of the last node
    thru->next = new_node;
  }
  len++;
}

template <typename T>
void LinkedList<T>::pop_front(){
  /**
   * Remove the first element of the list
   */

  // remove the head
  Node * todelete = head;
  head = head->next;
  delete todelete;
  len--;
}


template <typename T>
void LinkedList<T>::remove_at(int index){
  /**
   * Remove a node at a particular index
   * O(n)
   */

  // empty list, nothing to do
  if (index < 0 || index >= len){throw std::out_of_range("Index out of range");}

  if (index == 0){
    LinkedList<T>::pop_front();
    return;
  }

  // find the previous node of the node at index
  Node * prev = LinkedList<T>::get(index-1);

  if (prev == nullptr || prev->next == nullptr){throw std::out_of_range("Index out of range");}

  Node * todelete = prev->next;
  prev->next = todelete->next;
  delete todelete;
  len--;
}

/**
 * Operations
 */

template <typename T>
void LinkedList<T>::remove_all(const T& data){
  /**
   * Remove all the occurences of particular value in the list
   * Uses an additional pointer pointing to the previous node
   * O(n)
   */

  // Empty list nothing to do
  if (len == 0){return;}

  Node * thru = head;
  Node * prev = nullptr;

  while (thru != nullptr){
    if (thru->value == data){
      if (prev == nullptr){
        // Removing the head
        Node * todelete = head;
        head = head->next;
        thru = head;
        // free the node allocated memory
        delete todelete;
        todelete = nullptr;
        len--;
      }
      else{
        Node * todelete = thru;
        prev->next = thru->next;
        thru = thru->next;
        // free the allocated memory
        delete todelete;
        todelete = nullptr;
        len--;
      }
    }
    else{
      prev = thru;
      thru = thru->next;
    }
  }
}

template <typename T>
typename LinkedList<T>::Node * LinkedList<T>::find(const T & data){
  /**
   * Find and return the node containing `data`
   * If there are duplicates, this function returns the first occurence of `data`
   * in the list
   * Returns nullptr if `data` is not in the list
   * O(n)
   */
  Node * thru = head;
  while (thru != nullptr){
    if (thru->value == data){return thru;}
    thru = thru->next;
  }
  return nullptr;
}

template <typename T>
typename LinkedList<T>::Node * LinkedList<T>::get(int index){
  /**
   * Returns a node at a particular index
   * O(n)
   */

  if (index < 0 || index >= len){
    throw std::out_of_range("Index out of range");
  }

  Node * thru = head;
  while (index > 0 && thru->next != nullptr){
    thru = thru->next;
    index--;
  }
  return thru;
}

template <typename T>
bool LinkedList<T>::contains(const T & data){
  /**
   * Returns true if a list contains a particular value
   */
  return LinkedList<T>::find(data) != nullptr;
}

template <typename T>
bool LinkedList<T>::equals(const LinkedList<T>& other) const {
  /**
   * Checks if two lists are equal
   * O(n)
   */

  // If the lists are different sizes, they don't have the same contents.
  if (len != other.size()) {
    return false;
  }

  // We'll iterate along both lists and check that all items match by value.
  const Node* thisCur = head;
  const Node* otherCur = other.head;

  while (thisCur) {
    if (!otherCur) {
      throw std::runtime_error(std::string("Error in equals: ") + "otherCur missing a node or wrong item count");
    }
    if (thisCur->value != otherCur->value) {
      return false;
    }
    thisCur = thisCur->next;
    otherCur = otherCur->next;
  }

  return true;
}


template <typename T>
void LinkedList<T>::insertOrdered(const T& data){
/**
 * Insert a new node in the correct position assuming the list was previously sorted
 * O(n)
 */
 
  if (!head || (head->value>data)){
    push_front(data);
    return;
  }
  
  Node * new_node = new Node(data);

  // Look for the first greater element to the new value 
  Node * thru = head;
  while (thru->next){
    if (thru->next->value > data){
      new_node->next = thru->next;
      thru->next = new_node;
      len ++;
      return;
    }
    thru = thru->next;
  }

  // If we reach this point, this means that the new value is greater than all
  // the values of the list
  // Then insert the node at the end
  thru->next = new_node;
  len++;
}

template <typename T>
bool LinkedList<T>::_isSorted(Node * headRef) const{
  /**
   * Recursively check if a list is sorted
   *
   */

  if (!headRef->next){
    return true;
  }
  else{
    if (headRef->value > headRef->next->value){return false;}
    return LinkedList<T>::_isSorted(headRef->next);
  } 
}

template <typename T>
bool LinkedList<T>::isSorted() const {
  /**
   * Wrapper around _isSorted
   */
  return LinkedList<T>::_isSorted(head);
}

template <typename T>
std::tuple<LinkedList<T>,LinkedList<T>> LinkedList<T>::splitHalves() const{
  /**
   * Split a list into two halves
   */

  int middle = len/2; 
  
  LinkedList<T> firstHalf;
  LinkedList<T> secondHalf = *this;  

  if (len < 2){
    return std::make_tuple(firstHalf, secondHalf);
  }

  for (int i=0;i<middle;i++){
    firstHalf.push_back(secondHalf.head->value);
    secondHalf.pop_front();
  }

  return std::make_tuple(firstHalf, secondHalf);
}









