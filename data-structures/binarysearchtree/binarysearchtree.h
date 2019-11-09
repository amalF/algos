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


			public:
				BSTree() : _root(nullptr){};
				BSTree(T value) : _root(new TreeNode(value)){};
				~BSTree(){
					bool success = deleteSubTree(_root);
					if(!success){throw std::runtime_error("Something wrong happened during deleting the tree");}
				}

				int size(){return len;}
				bool isEmpty(){return len==0;}

				T& top() const {
					if (_root){return _root->data;}
				}

				bool deleteSubTree(TreeNode* targetRoot);
				void add(const T value);

				std::ostream& Print(std::ostream& os) const;

				friend std::ostream& operator<<(std::ostream& os, const BSTree<T>& tree){
					return tree.Print(os);
				}

		};

	template <typename T>
		void BSTree<T>::add(const T value){

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
			if (!rootNode){
				rootNode = new TreeNode(value);
			}
			else if (rootNode->data==value){
				std::cout << "Value already exists"<<std::endl;
			}
			else{
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
		std::ostream& BSTree<T>::Print(std::ostream& os) const {
			const TreeNode* rootNode = this->_root;
			if(!_root){
				os << "[empty tree]" << std::endl;
				return os;
			}

			std::stack<const TreeNode*> nodesToPrint;
			nodesToPrint.push(rootNode);

			//std::stack<int> depthStack;
			//depthStack.push(0);

			std::stack<std::vector<bool>> curMarginStack;
			curMarginStack.push( std::vector<bool>() );
			std::stack<std::vector<bool>> trailingMarginStack;
			trailingMarginStack.push(std::vector<bool>());

			while(!nodesToPrint.empty()){

				const TreeNode* cur = nodesToPrint.top();
				nodesToPrint.pop();
				// Pop the current depth for the node being explored.
				//int curDepth = depthStack.top();
				//depthStack.pop();

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
					//std::cout << childrenPtr.size()<< std::endl;
					//std::cout << "cur->left" << cur->left << std::endl;
					//std::cout << "cur->right" << cur->right << std::endl;
					for (auto it = childrenPtr.rbegin();it!=childrenPtr.rend();it++){
						const TreeNode* childPtr = *it;
						//std::cout << "CHildPTR " << childPtr->data << std::endl;
						nodesToPrint.push(childPtr);
						//depthStack.push(curDepth+1);
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

