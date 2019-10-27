/**
 *
 */
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <math.h>
#include "list.h"

using namespace ds;

/**
 * Capacity
 */

template <typename T>
int List<T>::size() const{
  return len;
}

template <typename T>
bool List<T>::isEmpty(){
  return len == 0;
}

/**
 * Modifiers
 */

template <typename T>
void List<T>::push_front(const T data){
  /**
   * Insert a new node at the front of the list
   * O(1) thanks to the head pointer
   */

  // create a new node in the heap
  Node * new_node = new Node(data);
  new_node->next = head;

  if(head){
    head->prev = new_node;
  } 
  // move the head to the new node
  head = new_node; 
  if (!tail){
    //If the list is empty, set the tail pointing to the same node as the head
    tail = head;
  }
  len++;
}

template <typename T>
void List<T>::insert(const T data, int index){
  /**
   * Insert a new node at a specific location
   * O(n) in the worst case we will traverse the list to get the node at the specified index
   */

  if (index < 0 || index > len){throw std::out_of_range("Index out of range");}

  if (index == 0){
    List<T>::push_front(data);
    return;
  }
  else if(index==len-1){
    List<T>::push_back(data);
    return;
  }else{

  // create new node
  Node * new_node = new Node(data);

  // get the node at index 
  Node * old = List<T>::get(index);

  // Get the previous node
  Node * prev = old->prev;

  prev->next = new_node;
  old->prev = new_node;
  new_node->prev = prev;
  new_node->next = old;
  len++;
}
}
//
template <typename T>
void List<T>::push_back(T const data){
  /**
   * Insert new node at the end of the list
   * O(1)
   */

  // create the new node
  Node * new_node = new Node(data);

  // If the list is empty, make the new node as head and tail
  if (len == 0){
    head = new_node;
    tail = new_node;
  }
  else{
    new_node->prev = tail;
    tail->next = new_node;
    tail = new_node;
  }
  len++;
}

template <typename T>
void List<T>::pop_front(){
  /**
   * remove the first element of the list
   * o(1)
   */
  if(!head){throw std::runtime_error("pop_front() called on an empty list");}

  // remove the head
  Node * todelete = head;
  if(!head->next){
    head = nullptr;
    tail = nullptr;
  }
  else{
    head = head->next;
    head->prev = nullptr;
  } 
  delete todelete;
  todelete = nullptr;
  len--;
}

template <typename T>
void List<T>::pop_back(){
  /**
   * remove the last element of the list
   * o(1)
   */
  if(!tail){throw std::runtime_error("pop_back() called on an empty list");}
  // remove the head
  Node * todelete = tail;
  if(!tail->prev){
    tail = nullptr;
    head = nullptr;
  }
  else{
    tail = tail->prev;
    tail->next = nullptr;
  }
  delete todelete;
  todelete = nullptr;
  len--;
}

template <typename T>
void List<T>::remove(int index){
  /**
   * Remove a node at a particular index
   * O(n)
   */

  // empty list, nothing to do
  if (index < 0 || index >= len){throw std::out_of_range("Index out of range");}

  if (index == 0){
    List<T>::pop_front();
    return;
  }
  else if (index==len-1){
    List<T>::pop_back();
    return;
  }
  else{

    // find the node at index
    Node * todelete = List<T>::get(index);
    todelete->prev->next = todelete->next;
    delete todelete;
    len--;
   }
}
//
///**
// * Operations
// */
//
template <typename T>
void List<T>::remove_all(const T data){
  /**
   * Remove all the occurences of particular value in the list
   * O(n)
   */

  // Empty list nothing to do
  if (len == 0){return;}

  Node * thru = head;

  while (thru != nullptr){
    if (thru->value == data){
      if (!thru->prev){
        List<T>::pop_front();
      }
      else if (!thru->next){
        List<T>::pop_back();
      }
      else{
        Node * todelete = thru;
        thru->prev->next = thru->next;
        thru->next->prev = thru->prev; 
        delete todelete;
        todelete = nullptr;
        len--; 
      }
    }
    thru = thru->next;
  }
}

//
template <typename T>
typename List<T>::Node * List<T>::find(const T data){
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
//
template <typename T>
typename List<T>::Node * List<T>::get(int index){
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
//
template <typename T>
bool List<T>::contains(const T data){
  /**
   * Returns true if a list contains a particular value
   */
  return List<T>::find(data) != nullptr;
}
//
template <typename T>
bool List<T>::equals(const List<T>& other) const {
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
  const Node* curOther = other.head;

  while (thisCur) {
    if (!curOther) {
      throw std::runtime_error(std::string("Error in equals: ") + "curOther missing a node or wrong item count");
    }
    if (thisCur->value != curOther->value) {
      return false;
    }
    thisCur = thisCur->next;
    curOther = curOther->next;
  }

  return true;
}
//
//
template <typename T>
void List<T>::insertOrdered(const T data){
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
      thru->next->prev = new_node;
      thru->next = new_node;
      len ++;
      return;
    }
    thru = thru->next;
  }

  // If we reach this point, this means that the new value is greater than all
  // the values of the list
  // Then insert the node at the end
  // and update the tail
  thru->next = new_node;
  tail = new_node;
  len++;
}
//
template <typename T>
bool List<T>::_isSorted(Node * headRef) const{
  /**
   * Recursively check if a list is sorted
   *
   */

  if (!headRef->next){
    return true;
  }
  else{
    if (headRef->value > headRef->next->value){return false;}
    return List<T>::_isSorted(headRef->next);
  } 
}
//
template <typename T>
bool List<T>::isSorted() const {
  /**
   * Wrapper around _isSorted
   */
  return List<T>::_isSorted(head);
}
//
template <typename T>
std::tuple<List<T>,List<T>> List<T>::splitHalves() const{
  /**
   * Split a list into two halves
   */

  int middle = len/2; 
  
  List<T> firstHalf;
  List<T> secondHalf = *this;  

  if (len < 2){
    return std::make_tuple(firstHalf, secondHalf);
  }

  for (int i=0;i<middle;i++){
    firstHalf.push_back(secondHalf.head->value);
    secondHalf.pop_front();
  }

  return std::make_tuple(firstHalf, secondHalf);
}
//
template <typename T>
List<T> List<T>::merge(const List<T>& other) const {
  /**
   * Merge two sorted lists
   * O(n)
   */

  if (len == 0){return other;}
  if (other.len == 0){return *this;}

  List<T> result;

  Node * cur = head;
  Node * curOther = other.head;

  while (cur && curOther){
    if (cur->value > curOther->value){
      result.push_back(curOther->value);
      curOther = curOther->next;
    }
    else{
      result.push_back(cur->value);
      cur = cur->next;
    }
  }

  if (!cur && curOther){
    while (curOther){
      result.push_back(curOther->value);
      curOther = curOther->next;
    }
    return result;
  }

  if (!curOther && cur){
    while (cur){
      result.push_back(cur->value);
      cur = cur->next;
    }
  }
  return result;
}
//
template <typename T>
List<T> List<T>::insertionSort() const{
  /**
   * Sort a list using insertion sort algorithm
   * O(n^2)
   */

  if (!head){return *this;}
  List<T> result;

  Node * cur = head;

  while (cur){
    result.insertOrdered(cur->value);
    cur = cur->next;
  }

  return result;
}

template <typename T>
List<T> List<T>::_mergeSort() const{
  /**
   * Implement merge sort algorithm recursively
   * O(nlog(n))
   */

  //base case
  if (len<2){return *this;}
  else{
    auto splits = splitHalves();
    List<T> left = std::get<0>(splits);
    List<T> right = std::get<1>(splits);
    List<T> leftSorted = left._mergeSort();
    List<T> rightSorted = right._mergeSort();
    return leftSorted.merge(rightSorted);
  }
}

template <typename T>
List<T> List<T>::mergeSort() const{
  /**
   * A wrapper function to call merge sort 
   */

  return List<T>::_mergeSort();
}
