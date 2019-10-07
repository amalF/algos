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
				DynamicArray(){
					capacity = 100;
					arr = new T[capacity];

				};



				//Destructor
				~DynamicArray(){
					delete[] arr;
				}
				int size();
				bool isEmpty();
				int maxSize();
				void resize(int new_capacity);
				void growSize();
				void shrinkSize();
				void add(T element);
				void removeAt(int rm_index);
				void remove(T element);
				int find(T element);
				bool contains(T element);
				T & operator[](int index);
				template <typename U>
					friend std::ostream& operator<<(std::ostream& os, DynamicArray<U>& da);
			private:
				T * arr;
				int len = 0;
				int capacity = 0; //Array capacity




		};
}
#include "dynamicarray.hpp"
