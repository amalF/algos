/**
 * Implementation of a stack using a linked list
 *
 * @author Amal Feriani
 */

#pragma once

#include <linkedlist.h>

namespace ds {
  template <typename T>
    class Stack{
      public:
        //Default Constructor
        Stack() {
          list = new LinkedList<T>();
        }; 
        // Destructor
        ~Stack(){
          //list->clear();
          delete list;
          list = nullptr;
        };

        //copy constructor
        Stack(const Stack<T>& other) : Stack(){
          *this = other;
        };

        //assignment constructor
        Stack<T>& operator=(const Stack<T>& other){
          list = other.list;
        }

        //Capacity
        int size() const;
        bool isEmpty();

        //Element access
        const T& top() const;

        //Modifiers
        void push(const T& value);
        void pop();

        friend std::ostream& operator<<(std::ostream& s, const Stack<T>& v) {
          return s << *(v.list);
        }
        bool operator==(const Stack<T>& other) const {
          return *list==*(other.list);
        }
        bool operator!=(const Stack<T>& other) const {
          return *list!=*(other.list);
        }


      private:
        LinkedList<T>* list;

    };

}
#include "stack.hpp"
