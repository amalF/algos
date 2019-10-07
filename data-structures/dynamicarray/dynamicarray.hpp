/**
 * A generic C++ implementation of a dynamic array
 * @author
 *	Amal Feriani
 */

#include "dynamicarray.h"
#include <iostream>
#include <stdexcept>
#include <chrono>

#include <typeinfo>

namespace ds {
	template <typename T>
		int DynamicArray<T>::size(){
			return len;
		}
	template <typename T>
		int DynamicArray<T>::maxSize(){
			return capacity;
		}

	template <typename T>
		bool DynamicArray<T>::isEmpty(){
			return size() ==0;
		}
	template <typename T>
		void DynamicArray<T>::resize(int new_capacity){
			//Create new array with the new capacity
			T* new_arr = new T[new_capacity];
			//Copy the current array to the new allocated array
			for (int i=0;i<new_capacity;i++){
				new_arr[i] = arr[i];
			}
			//Release the allocated memory for the old array
			delete[] arr;
			//Point to the newly created array
			arr = new_arr;
		}

	template <typename T>
		void DynamicArray<T>::growSize(){
			// double the size of the array
			if (capacity == 0) capacity = 1;
			else capacity *= 2;
			DynamicArray<T>::resize(capacity);
		}

	template <typename T>
		void DynamicArray<T>::shrinkSize(){
			if (len==capacity) return; //nothing to do
			capacity = len;
			DynamicArray<T>::resize(len);
		}

	template <typename T>
		int DynamicArray<T>::find(T element){
			for (int i = 0;i<len;i++){
				if (arr[i] == element)
					return i;
			}
			//Return -1 if the element is not in the array
			return -1;
		}

	template <typename T>
		bool DynamicArray<T>::contains(T element){
			return DynamicArray<T>::find(element) != -1;
		}

	template <typename T>
		void DynamicArray<T>::add(T element){
			//If we exceed the array capacity, resize the array by doubling its size
			if (len+1>=capacity){
				DynamicArray<T>::growSize();
			}
			arr[len++] = element;
		}

	template <typename T>
		void DynamicArray<T>::removeAt(int index){
			if (index>=len || index <0) throw std::out_of_range("Index out of range");

			T* new_arr = new T[len-1];
			//Copy the current array to the new allocated array
			for (int i=0,j=0;i<len;i++,j++){
				if (i == index){j--;}
				else{new_arr[j] = arr[i];}
			}
			//Release the allocated memory for the old array
			delete[] arr;
			//Point to the newly created array
			arr = new_arr;
			capacity = --len;
		}

	template <typename T>
		void DynamicArray<T>::remove(T element){
			int index = DynamicArray<T>::find(element);
			if (index == -1) throw std::invalid_argument("Element to remove not in the array");
			else removeAt(index);
		}

	/*
	 * Operators
	 */
	template <typename T>
		T & DynamicArray<T>::operator[](int index){
			return arr[index];
		}

	template <typename T>
		std::ostream& operator<<(std::ostream& os, DynamicArray<T>& da){
			for (int i =0;i<da.len-1;i++){
				os << da.arr[i] << " ";
			}
			os << da.arr[da.len-1];

			return os;
		}
}

