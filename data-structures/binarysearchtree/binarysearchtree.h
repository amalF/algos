/*
 * Implementation of binary search tree
 *
 * @author Amal Feriani
 */

#pragma once
#include <stdexcept>

namespace ds{
	template <typename T>
		class BSTree{

			private:
				class Node{
					public:
						Node(T value) : data(value), left(nullptr), right(nullptr){};
						Node(T value, Node* l, Node* r) : data(value), left(l), right(l){};
						~Node(){};
						bool isLeafNode(){
							if ((!left) && (!right)){return true;}
							else{return false;}
						}
						const T data;
						Node* left;
						Node* right;
				};

				Node* _root;
				int height=0;
				int len=0;
				bool _add(Node* node, const T value);


			public:
				BSTree() : _root(nullptr){};
				BSTree(T value) : _root(new Node(value)){};
				~BSTree(){
					bool success = deleteSubTree(_root);
					if(!success){throw std::runtime_error("Something wrong happened during deleting the tree");}
				}

				int size(){return len;}
				bool isEmpty(){return len==0;}

				T& top() const {
					if (_root){return _root->data;}
				}

				bool deleteSubTree(Node* targetRoot);
				bool add(const T value);

		};

	template <typename T>
		bool BSTree<T>::add(const T value){

			if (!_root){
				_root = new Node(value);
				len++;
				return true;
			}

			return _add(_root, value);
		}

	template <typename T>
		bool BSTree<T>::_add(Node* rootNode, const T value){
			if (!rootNode){
				rootNode = new Node(value);
				len++;
				return true;
			}
			if (rootNode->data==value){
				return false;
			}
			else{
				if(value>rootNode->data){
					_add(rootNode->right, value);
				}
				else{
					_add(rootNode->left, value);
				}
			}
		}

	template <typename T>
		bool BSTree<T>::deleteSubTree(Node* targetRoot){
			if (!targetRoot){
				return true;
			}
			else if (targetRoot->isLeafNode()){
				delete targetRoot;
				targetRoot = nullptr;
				len--;
				return true;
			}
			else{
				return deleteSubTree(targetRoot->right) && deleteSubTree(targetRoot->left);
			}
		}

};

