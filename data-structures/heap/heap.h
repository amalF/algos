/**
 * Implementation of a min heap
 */


#pragma once
#include "dynamicarray.h"


namespace ds {

  template <typename T>
    class Heap{
      public:
        Heap(): data(new DynamicArray<T>()){data->add(-10000000);};
        Heap(int capacity): data(new DynamicArray<T>(capacity)){
          data->add(-10000000);
        };
        //~Heap(){};

        int size(){return data->size()-1;}
        bool isEmpty(){return data->size()-1==0;}
        const T& top() const{
          if(data->size()>0){
            return data->peek(1);
          }
        }
                                                                              
        //Modifiers
        void push(const T value);
        void pop();
                                                                              
        friend std::ostream& operator<<(std::ostream& s, const Heap<T>& v) {
          return s << *(v.data);
        }

      private:
        std::unique_ptr<DynamicArray<T>> data;
        int _parent(int childIndex);
        int _leftChild(int parentIndex);
        int _rightChild(int parentIndex);
        void _heapifyUp(int index);
    };

  template <typename T>
    void Heap<T>::push(const T value){
      data->add(value);
      int len = data->size()-1;
      _heapifyUp(len);
    }
  

  template <typename T>
    int Heap<T>::_parent(int index){
      return index/2;
    }

  template <typename T>
    void Heap<T>::_heapifyUp(int index){
      int parentIndex = _parent(index);
      if (data->peek(parentIndex)<data->peek(index)){
        return;
      }else{
        //swap elements
        data->swap(parentIndex, index);
        _heapifyUp(parentIndex);
      }
    }
};





