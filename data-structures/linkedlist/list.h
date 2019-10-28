/**
 * Double Linked List Implementation
 * @author Amal Feriani
 */

#pragma once

#include <ostream>

namespace ds {
  template <typename T>
    class List {
      public:
        class Node{
          public:
            const T value;
            Node * next;
            Node * prev;

            // Constructors
            Node(const T data) : value(data), next(nullptr), prev(nullptr){};

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
        List() : head(nullptr), tail(nullptr){};
        // Destructor : deallocate all the nodes
        ~List(){
          clear();
        };

        // Copy constructor
        List(const List<T>& other) : List() {
          *this = other;
        }

        // Assignment constructor
        List<T>& operator=(const List<T>& other){
          // Clear the current list.
          clear();

          // We'll walk along the other list and push copies of its data.
          // TODO review this
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
        const T& back() const {
          if(!tail) { throw std::runtime_error("back() called on an empty list");}
          return tail->value;
        }
        const T& val(int index){
          return get(index)->value;
        }
        
        /*const T & operator[](int index){
          return get(index)->value;
        };*/

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

        void push_front(const T data);
        void insert(const T data, int index);
        void push_back(const T data);
        void pop_front();
        void pop_back();
        void remove(int index);

        // Operations
        void remove_all(const T data);
        bool contains(const T data);
        bool equals(const List<T>& other) const;
        bool operator==(const List<T>& other) const {
          return equals(other);
        }
        bool operator!=(const List<T>& other) const {
          return !equals(other);
        }
        void insertOrdered(const T newData);
        bool isSorted() const;
        std::tuple<List<T>,List<T>> splitHalves() const;
        List<T> merge(const List<T>& other) const;
        List<T> insertionSort() const;
        List<T> mergeSort() const;
        List<T> _mergeSort() const;

        friend std::ostream& operator<<(std::ostream& s, const List<T>& v) {
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
        Node * find(const T data);
        Node * get(int index);
        bool _isSorted(Node * headRef) const;
        Node* head;
        Node* tail;
        int len = 0;
    };
}
#include "list.hpp"
