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
        const T pop();
                                                                              
        friend std::ostream& operator<<(std::ostream& s, const Heap<T>& v) {
          return s << *(v.data);
        }

      private:
				DynamicArray<T>* data;
        int _parent(int childIndex);
        int _leftChild(int parentIndex);
        int _rightChild(int parentIndex);
        void _heapifyUp(int index);
				void _heapifyDown(int index);
				int _getMinChild(int index);
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
		int Heap<T>::_rightChild(int parentIndex){
			int idx = 2*parentIndex+2;
			return idx< data->size() ? idx : -1;
		}
	template <typename T>
		int Heap<T>::_leftChild(int parentIndex){
			int idx = 2*parentIndex+1;
			return idx< data->size() ? idx : -1;
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

	template <typename T>
		const T Heap<T>::pop(){
			//The min value is always the top of the heap
			const T minValue = data->peek(0);
			//Remove the top node by replacing it with the value of the last node
			const T lastValue = data->peek(data->size()-1);
			data->set(lastValue, 0);
			data->removeAt(data->size()-1);
			_heapifyDown(0);
			return minValue;
		}

	template <typename T>
		void Heap<T>::_heapifyDown(int index){
			
			if (2*index+1>data->size()-1){
				return;
			}
			
			int minValueIndex = _getMinChild(index);
			if (data->peek(index)<data->peek(minValueIndex)){
				// the parent node is already smaller than its children
				return;
			}
			data->swap(index, minValueIndex);
			_heapifyDown(minValueIndex);
		}

		template <typename T>
		int Heap<T>::_getMinChild(int index){
			int leftChildIndex = _leftChild(index);
			int rightChildeIndex = _rightChild(index);
			
			if ((leftChildIndex==-1) && (rightChildeIndex==-1)){return -1;}
			if (leftChildIndex==-1){return rightChildeIndex;}
			if (rightChildeIndex==-1){return leftChildIndex;}
			return data->peek(leftChildIndex)<data->peek(rightChildeIndex) ? leftChildIndex : rightChildeIndex;
		}
};





