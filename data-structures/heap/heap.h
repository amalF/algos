/**
 * Implementation of a min heap
 */


#pragma once
#include <memory>
#include <vector>


namespace ds {

  template <typename T>
    class Heap{
      public:
        Heap(): data(std::make_unique<std::vector<T>>()){};
				Heap(int capacity): data(std::make_unique<std::vector<T>>(capacity)){};
        int size(){return data->size();}
        bool isEmpty(){return data->size()==0;}
        const T& top() const{
          if(data->size()>0){
            return data->at(0);
          }
        }
                                                                              
        //Modifiers
        void push(const T value);
        const T pop();
                                                                              
        friend std::ostream& operator<<(std::ostream& s, const Heap<T>& v) {
					s.put('[');
					char comma[3] = {'\0', ' ', '\0'};
					for (int i =0;i<v.data->size();i++){
					  s << comma << v.data->at(i);
					  comma[0] = ',';
					}
					return s << ']';
        }

      private:
				std::unique_ptr<std::vector<T>> data;

        int _parent(int childIndex);
        int _leftChild(int parentIndex);
        int _rightChild(int parentIndex);
        void _heapifyUp(int index);
				void _heapifyDown(int index);
				int _getMinChild(int index);
    };

  template <typename T>
    void Heap<T>::push(const T value){
      data->push_back(value);
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
      if (data->at(parentIndex)<data->at(index)){
        return;
      }else{
        //swap elements
				std::swap(data->at(parentIndex), data->at(index));
        _heapifyUp(parentIndex);
      }
    }

	template <typename T>
		const T Heap<T>::pop(){
			//The min value is always the top of the heap
			const T minValue = data->front();
			//Remove the top node by replacing it with the value of the last node
			const T lastValue = data->back();
			std::swap(data->front(), data->back());
			data->pop_back();
			if (data->size()>0){
				_heapifyDown(0);
			}
			return minValue;
		}

	template <typename T>
		void Heap<T>::_heapifyDown(int index){
			
			if (2*index+1>data->size()-1){
				return;
			}
			
			int minValueIndex = _getMinChild(index);
			if (data->at(index)<data->at(minValueIndex)){
				// the parent node is already smaller than its children
				return;
			}
			std::swap(data->at(index), data->at(minValueIndex));
			_heapifyDown(minValueIndex);
		}

		template <typename T>
		int Heap<T>::_getMinChild(int index){
			int leftChildIndex = _leftChild(index);
			int rightChildeIndex = _rightChild(index);
			
			if ((leftChildIndex==-1) && (rightChildeIndex==-1)){return -1;}
			if (leftChildIndex==-1){return rightChildeIndex;}
			if (rightChildeIndex==-1){return leftChildIndex;}
			return data->at(leftChildIndex)<data->at(rightChildeIndex) ? leftChildIndex : rightChildeIndex;
		}
};





