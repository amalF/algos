/**
 * A generic C++ implementation of a dynamic array
 * @author
 *      Amal Feriani
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
    int DynamicArray<T>::find(const T element){
      for (int i = 0;i<len;i++){
        if (arr[i] == element)
          return i;
      }
      //Return -1 if the element is not in the array
      return -1;
    }

  template <typename T>
    bool DynamicArray<T>::contains(const T element){
      return DynamicArray<T>::find(element) != -1;
    }

  template <typename T>
    void DynamicArray<T>::add(const T element){
      //If we exceed the array capacity, resize the array by doubling its size
      if (len+1>=capacity){
        DynamicArray<T>::growSize();
      }
      arr[len++] = element;
    }

  template <typename T>
    void DynamicArray<T>::insert(const T element, int index){
      if (index < 0 || index >=len) throw std::out_of_range("Index out of range");

      if (len+1>=capacity){
        DynamicArray<T>::growSize();
      }
      //Move elements to the right
      for (int i=len-1;i>=index;i--){
        arr[i+1] = arr[i];
      }

      arr[index] = element;
      len++;
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
    void DynamicArray<T>::remove(const T element){
      int index = DynamicArray<T>::find(element);
      if (index == -1) throw std::invalid_argument("Element to remove not in the array");
      else removeAt(index);
    }

  template <typename T>
    void DynamicArray<T>::insertOrdered(const T element){
      for (int i=0;i<len;i++){
        if (element<arr[i]){
          DynamicArray<T>::insert(element, i);
          return;
        }
      }
      DynamicArray<T>::add(element);
    }

  template <typename T>
    DynamicArray<T> DynamicArray<T>::insertionSort(){
      DynamicArray<T> result;
      for (int i=0;i<len;i++){
        result.insertOrdered(arr[i]);
      }
      return result;
    }

  template <typename T>
    void DynamicArray<T>::mergeSort(){
      return _mergeSort(0,len-1);
    }

  template <typename T>
    void DynamicArray<T>::_mergeSort(int first, int last){
      if (first<last){
        int middle = (last + first)/2;
        _mergeSort(first, middle);
        _mergeSort(middle+1, last);
        return _combine(first, middle, last);
      }
    }

  template <typename T>
    void DynamicArray<T>::_combine(int first, int middle, int last){
      DynamicArray<T> lhs = DynamicArray((middle-first+1));
      DynamicArray<T> rhs = DynamicArray((last-middle));

      for(int i=first;i<=middle;i++){
        lhs.add(arr[i]);
      }
      for(int i=middle+1;i<last+1;i++){
        rhs.add(arr[i]);
      }

      int i = 0;
      int j = 0;

      for (int k=first;k<last+1;k++){
        if (j==rhs.size()){
          arr[k] = lhs[i];
          i++;
        }
        else if (i==lhs.size()){
          arr[k] = rhs[j];
          j++;
        }
        else{
          if (lhs[i]<rhs[j]){
            arr[k] = lhs[i];
            i++;
          }
          else{
            arr[k] = rhs[j];
            j++;
          }
        }
      }
    }

  template <typename T>
    void DynamicArray<T>::swap(int id1, int id2){
      if ((id1 < 0) || (id2<0) || (id1>=len) || (id2>=len)){throw std::out_of_range("Indices out of ranges");}
      T tmp = arr[id1];
      arr[id1] = arr[id2];
      arr[id2] = tmp;
    }

  /*
   * Operators
   */
  template <typename T>
    T & DynamicArray<T>::operator[](int index){
      return arr[index];
    }

}

