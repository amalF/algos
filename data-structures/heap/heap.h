/**
 * Implementation of a min heap
 */


#pragma once
#include "dynamicarray.h"


namespace ds {

  template <typename T>
    class Heap{
      public:
        Heap(): data(new DynamicArray<T>()){};
        Heap(int capacity): data(new DynamicArray<T>(capacity)){
        };

        int size(){return data->size();}
        bool isEmpty(){return data->size()==0;}
        const T& top() const{
          if(data->size()>0){
            return data->peek(0);
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
			if (index % 2 ==0){
				return index/2 -1;
			}else{
				return index/2;
			}
      
    }

  template <typename T>
    void Heap<T>::_heapifyUp(int index){
			if (index==0){return;}
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





