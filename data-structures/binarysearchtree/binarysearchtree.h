/*
 * Implementation of binary search tree
 *
 * @author Amal Feriani
 */

#pragma once
#include <stdexcept>
#include <iostream>
#include <ostream>
#include <vector>
#include <stack>
#include "queue.h"

namespace ds{
	template <typename T>
		class BSTree{

			private:
				class TreeNode{
					public:
						TreeNode(T value) : data(value), left(nullptr), right(nullptr){};
						TreeNode(T value, TreeNode* l, TreeNode* r) : data(value), left(l), right(r){};
						~TreeNode(){};
						bool isLeafNode(){
							if ((!left) && (!right)){return true;}
							else{return false;}
						}
						std::vector<TreeNode*> getChildren() const {
							std::vector<TreeNode*> childrenPtr;
							if (left){
								TreeNode* cur = this->left;
								childrenPtr.push_back(cur);
							}
							if (right){
								TreeNode* curr = this->right;
								childrenPtr.push_back(right);
							}
							return childrenPtr;
						}

						const T data;
						TreeNode* left;
						TreeNode* right;
				};

				TreeNode* _root;
				int height=0;
				int len=0;
				TreeNode* _add(TreeNode* node, const T value);
				TreeNode* _find(TreeNode* node, const T value);
				TreeNode* _remove(TreeNode* node, const T value);
				void _inorderTraversal(TreeNode* node);
				void _preorderTraversal(TreeNode* node);
				void _postorderTraversal(TreeNode* node);

			public:
				BSTree() : _root(nullptr){};
				BSTree(T value) : _root(new TreeNode(value)){};
				~BSTree(){
					deleteSubTree(_root);
				}

				int size(){return len;}
				bool isEmpty(){return len==0;}

				T& top() const {
					if (_root){return _root->data;}
					else{throw std::runtime_error("Empty List");}
				}

				const T& min() const{
					if(_root){return getMin(_root)->data;}
					else{throw std::runtime_error("Empty List");}
				}

				const T& max() const{
					if(_root){return getMax(_root)->data;}
					else{throw std::runtime_error("Empty list");}
				}

				bool deleteSubTree(TreeNode* targetRoot);
				void add(const T value);
				bool contains(const T value);
				TreeNode* find(const T value);
				bool remove(const T value);
				TreeNode* getMin(TreeNode* node) const;
				TreeNode* getMax(TreeNode* node) const;

				void inorderTraversal();
				void preorderTraversal();
				void postorderTraversal();
				void bfs();


				std::ostream& Print(std::ostream& os) const;

				friend std::ostream& operator<<(std::ostream& os, const BSTree<T>& tree){
					return tree.Print(os);
				}

		};

	template <typename T>
		void BSTree<T>::add(const T value){
			/**
			 * A wrapper function to add an element recursively in the tree
			 *
			 * O(log(n))
			 */

			if (!_root){
				_root = new TreeNode(value);
				len++;
				return;
			}
			_root = _add(_root, value);
			len++;
		}

	template <typename T>
		typename BSTree<T>::TreeNode* BSTree<T>::_add(TreeNode* rootNode, const T value){
			/**
			 * Recursively add new node to a tree
			 * This implementation doesn't allow duplicates
			 */

			if (!rootNode){
				rootNode = new TreeNode(value);
			}
			else if (rootNode->data==value){
				std::cout << "Value already exists"<<std::endl;
			}
			else{
				//Compare the value to the node data
				if(value>rootNode->data){
					rootNode->right = _add(rootNode->right, value);
				}
				else{
					rootNode->left = _add(rootNode->left, value);
				}
			}
			return rootNode;
		}

	template <typename T>
		bool BSTree<T>::deleteSubTree(TreeNode* targetRoot){
			/**
			 * Recursively delete a subtree and its children
			 * O(n)
			 */

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

	template <typename T>
		typename BSTree<T>::TreeNode* BSTree<T>::find(const T value){
			/*
			 * Wrapper function to find the node with value equal to the specified value
			 *
			 */
			return _find(_root, value);
		}

	template <typename T>
		typename BSTree<T>::TreeNode* BSTree<T>::_find(TreeNode* rootNode, const T value){
			/**
			 * Recursively find if a node is equal to the specified key
			 * O(log(n))
			 */

			if (!rootNode){
				return nullptr;
			}
			else if (rootNode->data==value){
				return rootNode;
			}
			else{
				if (value<rootNode->data){
					return _find(rootNode->left, value);
				}
				else{
					return _find(rootNode->right, value);
				}
			}
		}

	template <typename T>
		bool BSTree<T>::contains(const T value){
			/**
			 * Check if the tree contains a node equals to the specified key
			 */
			return find(value)!=nullptr;
		}


	template <typename T>
		bool BSTree<T>::remove(const T value){
			/**
			 * Wrapper function to remove a value from a tree
			 */

			if (!find(value)){
				std::cout << "Value doesn't exist in the tree" << std::endl;
				return false;
			}
			else{
				_root = _remove(_root, value);
				return true;
			}
		}
	template <typename T>
		typename BSTree<T>::TreeNode* BSTree<T>::_remove(TreeNode* rootNode, const T value){
			/**
			 * Recursively remove an element from a tree
			 * O(log(n))
			 */

			if (!rootNode){
				return nullptr;
			}
			else if (rootNode->data==value){
				std::vector<TreeNode*> childrenPtr = rootNode->getChildren();
				if (childrenPtr.size()==0){
					//If it's a leaf node, simply delete the node
					delete rootNode;
					rootNode = nullptr;
				}
				else if (childrenPtr.size()==1){
					//If the node has node subtree, delete the node and replace it with its subtree
					delete rootNode;
					rootNode=nullptr;
					return childrenPtr[0];
				}
				else{
					//if the node has 2 subtrees, we look for the smallest node in the right subtree
					// and swap it with the node. Then we delete the smallest node in the right subtree
					// We can also use the biggest node in the left subtree instead the smallest node in
					// the right subtree

					// Find the smallest node by traversing as far left in the right subtree
					TreeNode* minNode = getMin(rootNode->right);

					//Create a new node that will replace the current node
					//We cannot directly change the value of the node because
					//the data is a read-only member(const)
					TreeNode* tmp = new TreeNode(minNode->data);
					tmp->right = _remove(rootNode->right, minNode->data);
					tmp->left = rootNode->left;
					//deallocate the current node
					delete rootNode;
					rootNode = tmp;
				}
				len--;
			}
			else{
				if (value<rootNode->data){
					rootNode->left =  _remove(rootNode->left, value);
				}else{
					rootNode-> right = _remove(rootNode->right, value);
				}
			}
			return rootNode;
		}

	template <typename T>
		typename BSTree<T>::TreeNode* BSTree<T>::getMin(TreeNode* node) const{
			/**
			 * Find the smallest node in a subtree by traversing as far as possible
			 * to the left
			 */
			TreeNode* cur = node;
			while(cur->left){
				cur = cur->left;
			}
			return cur;
		}

	template <typename T>
		typename BSTree<T>::TreeNode* BSTree<T>::getMax(TreeNode* node) const{
			/**
			 * Find the biggest node in a subtree by traversing as far as possible
			 * to the right
			 */
			TreeNode* cur = node;
			while(cur->right){
				cur = cur->right;
			}
			return cur;
		}

	template <typename T>
		void BSTree<T>::preorderTraversal(){
			_preorderTraversal(_root);
			std::cout << std::endl;
		}
	template <typename T>
		void BSTree<T>::_preorderTraversal(TreeNode* node){
			if (!node){
				return;
			}
			std::cout << node->data << " ";
			_preorderTraversal(node->left);
			_preorderTraversal(node->right);
		}

	template <typename T>
		void BSTree<T>::inorderTraversal(){
			_inorderTraversal(_root);
			std::cout << std::endl;
		}
	template <typename T>
		void BSTree<T>::_inorderTraversal(TreeNode* node){
			if (!node){
				return;
			}
			_inorderTraversal(node->left);
			std::cout << node->data << " ";
			_inorderTraversal(node->right);
		}

	template <typename T>
		void BSTree<T>::postorderTraversal(){
			_postorderTraversal(_root);
			std::cout << std::endl;
		}
	template <typename T>
		void BSTree<T>::_postorderTraversal(TreeNode* node){
			if (!node){
				return;
			}
			_postorderTraversal(node->left);
			_postorderTraversal(node->right);
			std::cout << node->data << " ";
		}

	template <typename T>
		void BSTree<T>::bfs(){
			Queue<const TreeNode*> nodesToExplore;
			nodesToExplore.push(_root);
			while(!nodesToExplore.isEmpty()){
				const TreeNode* cur = nodesToExplore.front();
				if (cur){
					std::cout << cur->data << " ";
					
					if(cur->left){
						const TreeNode* l = cur->left;
						nodesToExplore.push(l);
					}
					if(cur->right){
						const TreeNode* r = cur->right;
						nodesToExplore.push(r);
					}
					nodesToExplore.pop();
				}
			}
			std::cout << std::endl;
		}

	template <typename T>
		std::ostream& BSTree<T>::Print(std::ostream& os) const {
			/**
			 * Helper function to print a tree
			 * This function was inspired by the code provided in the Illinois coursera
			 * programming assignment (https://www.coursera.org/learn/cs-fundamentals-2/home/welcome)
			 */
			const TreeNode* rootNode = this->_root;
			if(!_root){
				os << "[empty tree]" << std::endl;
				return os;
			}

			std::stack<const TreeNode*> nodesToPrint;
			nodesToPrint.push(rootNode);

			std::stack<std::vector<bool>> curMarginStack;
			curMarginStack.push( std::vector<bool>() );
			std::stack<std::vector<bool>> trailingMarginStack;
			trailingMarginStack.push(std::vector<bool>());

			while(!nodesToPrint.empty()){

				const TreeNode* cur = nodesToPrint.top();
				nodesToPrint.pop();

				// Pop the current and trailing margin graphic flags for this node.
				std::vector<bool> curMargin = curMarginStack.top();
				curMarginStack.pop();
				std::vector<bool> trailingMargin = trailingMarginStack.top();
				trailingMarginStack.pop();

				constexpr int LAST_ROW = 2;
				for (int row=1; row<=LAST_ROW; row++){
					for (auto stemIt= curMargin.begin(); stemIt !=curMargin.end(); stemIt++){
						bool showStem = *stemIt;
						std::string stemSymbol = "|";
						if (!showStem){
							stemSymbol = " ";
						}
						bool isLastCol = false;
						if (stemIt+1 == curMargin.end()){
							isLastCol = true;
						}

						if (isLastCol){
							if (LAST_ROW==row){
								os << stemSymbol << "_ ";
							}
							else if (showStem){
								os << stemSymbol << std::endl;
							}
							else{
								os << std::endl;
							}
						}
						else{
							os << stemSymbol << " ";
						}
					}
				}
				if (cur){
					os << cur->data << std::endl;
				}
				else{
					os << "[null]" << std::endl;
				}

				if (cur){
					std::vector<TreeNode*> childrenPtr = cur->getChildren();
					for (auto it = childrenPtr.rbegin();it!=childrenPtr.rend();it++){
						const TreeNode* childPtr = *it;
						nodesToPrint.push(childPtr);
						auto nextMargin = trailingMargin;
						nextMargin.push_back(true);
						curMarginStack.push(nextMargin);

						auto nextTrailingMargin = trailingMargin;
						nextTrailingMargin.push_back(true);
						trailingMarginStack.push(nextTrailingMargin);
					}
				}
			}
			return os;
		}
};

