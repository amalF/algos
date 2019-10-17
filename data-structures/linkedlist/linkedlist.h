/**
 * Linked List Implementation
 * @author Amal Feriani
 */

#pragma once

#include <ostream>

namespace ds {
  template <typename T>
    class LinkedList {
      public:
        class Node{
          public:
            const T& value;
            Node * next;
            // Constructors
            Node(const T& data) : value(data), next(nullptr){};
            Node(const T& data, Node * next) : value(data), next(next){};
            // Copy constructor
            Node(const Node & other) : value(other.value), next(other.next){};
            // Assignment operator
            Node& operator=(const Node & other){
              value = other.value;
              next = other.next;
              return *this;
            }
        };

        // Default constructor
        LinkedList() : head(nullptr){};
        // Destructor : deallocate all the nodes
        ~LinkedList(){
          clear();
        };

        // Copy constructor
        LinkedList(const LinkedList<T>& other) : LinkedList() {
          *this = other;
        }

        // Assignment constructor
        LinkedList<T>& operator=(const LinkedList<T>& other){
          // Clear the current list.
          clear();

          // We'll walk along the other list and push copies of its data.
          // (The declaration "const Node*" means a pointer to a const Node,
          //  not a const pointer to Node.)
          const Node* cur = other.head;
          while (cur) {
            // Push back a copy of this node's data
            push_back(cur->value);
            // Iterate
            cur = cur->next;
          }
          return *this;
        }
        //

        // Access
        // These functions enables to see the content of a node but it's not possible
        // to change the value of a node
        const T& front() const {
          if (!head){ throw std::runtime_error("front() called on an empty list");}
          return head->value;
        }
        const T & operator[](int index){
          return get(index)->value;
        };

        // Capacity
        int size() const;
        bool isEmpty();

        // Modifiers
        void clear(){
          // Iterate through the list and delete the nodes
          Node * thru = head;
          while (thru != nullptr){
            Node * todelete = thru;
            thru = thru->next;
            delete todelete;
            todelete = nullptr;
          }
        };
        void push_front(const T & data);
        void insert_at(const T& data, int index);
        void push_back(const T& data);
        void pop_front();
        void remove_at(int index);

        // Operations
        void remove_all(const T& data);
        bool contains(const T& data);
        bool equals(const LinkedList<T>& other) const;
        bool operator==(const LinkedList<T>& other) const {
          return equals(other);
        }
        bool operator!=(const LinkedList<T>& other) const {
          return !equals(other);
        }
        void insertOrdered(const T& newData);
        bool isSorted() const;
        LinkedList<T> insertionSort() const;
        std::tuple<LinkedList<T>,LinkedList<T>> splitHalves() const;
        LinkedList<T> merge(const LinkedList<T>& other) const;
        LinkedList<T> mergeSort() const;
        std::ostream& print(std::ostream& os) const;

        friend std::ostream& operator<<(std::ostream& s, const LinkedList<T>& v) {
          s.put('[');
          Node * thru = v.head;
          char comma[3] = {'\0', ' ', '\0'};
          while (thru) {
            s << comma << thru->value;
            comma[0] = ',';
            thru = thru->next;
          }
          return s << ']';
        }

      private:
        Node * find(const T& data);
        Node * get(int index);
        bool _isSorted(Node * headRef) const;
        Node* head;
        int len = 0;
    };
}
#include "linkedlist.hpp"
