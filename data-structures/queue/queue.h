/**
 * Implementation of a queue using a double linked list
 *
 * @author Amal Feriani
 */

#pragma once

#include <list.h>

namespace ds {
  template <typename T>
    class Queue{
      public:
        //Default Constructor
        Queue() : data(new List<T>()){}; 
        // Destructor
        ~Queue(){
          if(data){
            delete data;
            data = nullptr;
          }
        };

        //copy constructor
        Queue(const Queue<T>& other) : data(other.data){};

        //assignment constructor
        Queue<T>& operator=(const Queue<T>& other){
          data = other.data;
        }

        //Capacity
        int size() const;
        bool isEmpty();

        //Element access
        const T& front() const;
        const T& back() const;

        //Modifiers
        void push(const T value);
        void pop();

        friend std::ostream& operator<<(std::ostream& s, const Queue<T>& v) {
          return s << *(v.data);
        }
        bool operator==(const Queue<T>& other) const {
          return *data==*(other.data);
        }
        bool operator!=(const Queue<T>& other) const {
          return *data!=*(other.data);
        }


      private:
        List<T>* data;

    };

}
#include "queue.hpp"
