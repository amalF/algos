/**
 *
 */
#include <iostream>
#include <ostream>
#include <stdexcept>
#include "linkedlist.h"

using namespace ds;

template <typename T>
int LinkedList<T>::size(){
  return len;
}

template <typename T>
bool LinkedList<T>::isEmpty(){
  return len == 0;
}

template <typename T>
void LinkedList<T>::push(const T & data){
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
void LinkedList<T>::insertAt(const T & data, int index){
  /**
   * Insert a new node at a specific location
   * O(n) in the worst case we will traverse the list to get the node at the specified index
   */

  if (index < 0 || index > len){ throw std::out_of_range("Index out of range");}

  if (index == 0){
    LinkedList<T>::push(data);
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
void LinkedList<T>::append(const T & data){
  /**
   * Insert new node at the end of the listi
   * O(n) because we need to find the last node
   */
  // find the tail of list


  // create the new node
  Node * new_node = new Node(data);

  // If the list is empty, make the new as head
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
    if (thru->val == data){return thru;}
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
void LinkedList<T>::remove(const T& data){
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
    if (thru->val == data){
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
void LinkedList<T>::removeAt(int index){
  /**
   * Remove a node at a particular index
   * O(n)
   */

  // empty list, nothing to do
  if (index < 0 || index >= len){throw std::out_of_range("Index out of range");}

  if (index == 0){
    // remove the head
    Node * todelete = head;
    head = head->next;
    delete todelete;
    len--;
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
 * Operators
 */

template <typename T>
const T & LinkedList<T>::operator [](int index){
  return LinkedList<T>::get(index)->val;
}

