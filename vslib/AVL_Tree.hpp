#ifndef avl_trees
#define avl_trees

#include<iostream>
using namespace std;

namespace vip{
	template<class T>
	class tree_avl{
		private:
			struct node{
				T data;
				node* parent;
				node* leftChild;
				node* rightChild;
			};
			node* root;
			
			int treeHeight(node* subRoot){
				if(subRoot == NULL) return 0;
				return max(treeHeight(subRoot->leftChild), treeHeight(subRoot->rightChild)) + 1;
			}
			
			int balanceFactor(node* subRoot){
				if(subRoot == NULL) return 0;
				return treeHeight(subRoot->leftChild)-treeHeight(subRoot->rightChild);
			}
			
			node* insertLocation(T value){
				node* temp = new node;
				node* parentNode = new node;
				temp = root;
				if(root == NULL){
					return NULL;
				}
				else{
					while(temp != NULL){
						parentNode = temp;
						if(value > temp->data) temp=temp->rightChild;
						else{
							if(value < temp->data) temp=temp->leftChild;
						}
					}
					return parentNode;
				}
			}
			
			int caseFinder(node* unbalanceNode, T value){
				int arr[2];
				for(int i=0;i<2;i++){
					if(value > unbalanceNode->data){
						arr[i] = 1;
						unbalanceNode = unbalanceNode->rightChild;
					}
					else{
						if(value < unbalanceNode->data){
							arr[i] = 0;
							unbalanceNode = unbalanceNode->leftChild;
						}
					}
				}
				int returnValue = 1*arr[0]+2*arr[1];
				return returnValue;
			}
			
			void RR(node* unbalanceNode){
				node* leftChildPointer = new node;
				leftChildPointer = unbalanceNode->leftChild;
				if(unbalanceNode == root){
					leftChildPointer->parent = NULL;
					if(leftChildPointer->rightChild != NULL) leftChildPointer->rightChild->parent = unbalanceNode;
					unbalanceNode->leftChild = leftChildPointer->rightChild;
					leftChildPointer->rightChild = unbalanceNode;
					unbalanceNode->parent = leftChildPointer;
					root = leftChildPointer;
				}
				else{
					int parentChildFlag = 0; // 0: left, 1: right
					if(unbalanceNode->data > unbalanceNode->parent->data) parentChildFlag = 1;
					if(parentChildFlag == 0) unbalanceNode->parent->leftChild = leftChildPointer;
					else unbalanceNode->parent->rightChild = leftChildPointer;
					leftChildPointer->parent = unbalanceNode->parent;
					if(leftChildPointer->rightChild != NULL) leftChildPointer->rightChild->parent = unbalanceNode;
					unbalanceNode->leftChild = leftChildPointer->rightChild;
					leftChildPointer->rightChild = unbalanceNode;
					unbalanceNode->parent = leftChildPointer;
				}
			}
			
			void LL(node* unbalanceNode){
				node* rightChildPointer = new node;
				rightChildPointer = unbalanceNode->rightChild;
				if(unbalanceNode == root){
					rightChildPointer->parent = NULL;
					if(rightChildPointer->leftChild != NULL){
						rightChildPointer->leftChild->parent = unbalanceNode;
					}
					unbalanceNode->rightChild = rightChildPointer->leftChild;
					rightChildPointer->leftChild = unbalanceNode;
					unbalanceNode->parent = rightChildPointer;
					root = rightChildPointer;
				}
				else{
					int parentChildFlag = 0; // 0: left, 1: right
					if(unbalanceNode->data > unbalanceNode->parent->data) parentChildFlag = 1;
					if(parentChildFlag == 0) unbalanceNode->parent->leftChild = rightChildPointer;
					else unbalanceNode->parent->rightChild = rightChildPointer;
					rightChildPointer->parent = unbalanceNode->parent;
					if(rightChildPointer->leftChild != NULL) rightChildPointer->leftChild->parent = unbalanceNode;
					unbalanceNode->rightChild = rightChildPointer->leftChild;
					rightChildPointer->leftChild = unbalanceNode;
					unbalanceNode->parent = rightChildPointer;
				}
			}
			
			void LR(node* unbalanceNode){
				node* leftChildPointer = new node;
				leftChildPointer = unbalanceNode->leftChild;
				unbalanceNode->leftChild = leftChildPointer->rightChild;
				leftChildPointer->rightChild->parent = unbalanceNode;
				if(leftChildPointer->rightChild->leftChild != NULL) leftChildPointer->rightChild->leftChild->parent = leftChildPointer;
				leftChildPointer->rightChild = leftChildPointer->rightChild->leftChild;
				unbalanceNode->leftChild->leftChild = leftChildPointer;
				leftChildPointer->parent = unbalanceNode->leftChild;
				RR(unbalanceNode);
			}
			
			void RL(node* unbalanceNode){
				node* rightChildPointer = new node;
				rightChildPointer = unbalanceNode->rightChild;
				unbalanceNode->rightChild = rightChildPointer->leftChild;
				rightChildPointer->leftChild->parent = unbalanceNode;
				if(rightChildPointer->leftChild->rightChild != NULL) rightChildPointer->leftChild->rightChild->parent = rightChildPointer;
				rightChildPointer->leftChild = rightChildPointer->leftChild->rightChild;
				unbalanceNode->rightChild->rightChild = rightChildPointer;
				rightChildPointer->parent = unbalanceNode->rightChild;
				LL(unbalanceNode);
			}
			
			void printPreOrder(node* base){
				if(base == NULL) return;
				cout<<base->data<<", ";
				printPreOrder(base->leftChild);
				printPreOrder(base->rightChild);
			}
		public:
			AVL(){
				root = NULL;
			}
			
			void insert(T value){
				node* temp = new node;
				temp->data = value;
				temp->leftChild = NULL;
				temp->rightChild = NULL;
				node* parentNode = insertLocation(value);
				temp->parent = parentNode;
				if(parentNode != NULL){
					if(value > parentNode->data){
						parentNode->rightChild = temp;
					}
					if(value <parentNode->data){
						parentNode->leftChild = temp;
					}
					node* balanceChecker = new node;
					balanceChecker = parentNode;
					bool ambiguity = false;
					while(balanceChecker != NULL){
						if(balanceFactor(balanceChecker) > 1){
							ambiguity = true;
							break;
						}
						if(balanceFactor(balanceChecker) < -1){
							ambiguity = true;
							break;
						}
						balanceChecker = balanceChecker->parent;
					}
					if(ambiguity == true){
						int rotationCase = caseFinder(balanceChecker, value);
						switch(rotationCase){
							case 0: RR(balanceChecker);
									break;
							case 1: RL(balanceChecker);
									break;
							case 2: LR(balanceChecker);
									break;
							case 3: LL(balanceChecker);
									break;
						}
					}	
				}
				else root=temp;	
			}
			
			void print(){
				printPreOrder(root);
			}
	};
}

#endif
