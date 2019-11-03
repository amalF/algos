/**
 * Dynamic Array class outline
 *
 * @author
 * Amal Feriani
 *
 */

#pragma once
#include <stdexcept>

namespace ds {
	template <typename T>
		class DynamicArray {
			public:
				//Constructors

				DynamicArray(int _capacity){
					if (_capacity<0){
						throw std::invalid_argument("Capacity cannot be negative");
					}
					capacity = _capacity;
					arr = new T[capacity];
				};

				DynamicArray(): capacity(100), arr(new T[capacity]){};

				//Destructor
				~DynamicArray(){
					delete[] arr;
					arr = nullptr;
				}

				int size();
				bool isEmpty();
				int maxSize();
				void resize(int new_capacity);
				void growSize();
				void shrinkSize();
				void add(const T element);
				void insert(const T element, int index);
				void insertOrdered(const T element);
				void removeAt(int rm_index);
				void remove(const T element);
				int find(T element);
				bool contains(const T element);
				DynamicArray<T> insertionSort();
				void mergeSort();
				T & operator[](int index);
				friend std::ostream& operator<<(std::ostream& s, DynamicArray<T>& da){
					s.put('[');
					char comma[3] = {'\0', ' ', '\0'};
					for (int i =0;i<da.len;i++){
						s << comma << da.arr[i];
					  comma[0] = ',';
					}
					return s << ']';
					
			}

			private:
				T * arr;
				int len = 0;
				int capacity = 0; //Array capacity
				void _mergeSort(int first, int last);
				void _combine(int first, int middle, int last);
				std::tuple<DynamicArray<T>, DynamicArray<T>> _split(int splitIndex);
		};
}
#include "dynamicarray.hpp"
