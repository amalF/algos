/**
 * Linked List Implementation
 * @author
 *      Amal Feriani
 */

#pragma once

#include <ostream>

namespace ds {
  template <typename T>
    class LinkedList {
      public:
      LinkedList() : head(nullptr){};
        ~LinkedList(){
          // Iterate through the list and delete the nodes
          Node * thru = head;
          while (thru != nullptr){
            Node * todelete = thru;
            thru = thru->next;
            delete todelete;
            todelete = nullptr;
          }
        };

        void push(const T & data);
        void insertAt(const T& data, int index);
        void append(const T& data);

        void remove(const T& data);
        void removeAt(int index);

        const T & operator[](int index);

        int size();
        bool isEmpty();

        bool contains(const T& data);
        

      private:
        class Node{
          public:
            const T& val;
            Node * next;
            Node(const T& data) : val(data), next(nullptr){};
            Node(const T& data, Node * next) : val(data), next(next){};
            Node(const Node & other){val = other.val2; next = other.next;}

        };

        
        Node * find(const T& data);
        Node * get(int index);

        Node *head;
        int len = 0;

    };
}
#include "linkedlist.hpp"
