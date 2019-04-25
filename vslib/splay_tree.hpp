#ifndef splay_trees
#define splay_trees

#include<iostream>
using namespace std;

namespace vip{
	template<class T>
	class SplayTree{
		private:
			struct node{
				T data;
				node* parent;
				node* leftChild;
				node* rightChild;
			};
			
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
				
			node* root;
			
			int caseFinder(node* splayNode){
				int arr[2];
				for(int i=0;i<2;i++){
					
				}
				if(splayNode->data > splayNode->parent->data) arr[1] = 2;
				if(splayNode->data < splayNode->parent->data) arr[1] = 1;
				if(splayNode->parent->parent != NULL){
					splayNode = splayNode->parent;
					if(splayNode->data > splayNode->parent->data) arr[0] = 2;
					if(splayNode->data < splayNode->parent->data) arr[0] = 1;
				}
				else{
					arr[0] = arr[1];
					arr[1] = 0;
				}
				return 1*arr[0]+2*arr[1];
			}
			
			void RR(node* inbalanceNode){
				node* leftChildPointer = new node;
				leftChildPointer = inbalanceNode->leftChild;
				if(inbalanceNode == root){
					leftChildPointer->parent = NULL;
					if(leftChildPointer->rightChild != NULL) leftChildPointer->rightChild->parent = inbalanceNode;
					inbalanceNode->leftChild = leftChildPointer->rightChild;
					leftChildPointer->rightChild = inbalanceNode;
					inbalanceNode->parent = leftChildPointer;
					root = leftChildPointer;
				}
				else{
					int parentChildFlag = 0; // 0: left, 1: right
					if(inbalanceNode->data > inbalanceNode->parent->data) parentChildFlag = 1;
					if(parentChildFlag == 0) inbalanceNode->parent->leftChild = leftChildPointer;
					else inbalanceNode->parent->rightChild = leftChildPointer;
					leftChildPointer->parent = inbalanceNode->parent;
					if(leftChildPointer->rightChild != NULL) leftChildPointer->rightChild->parent = inbalanceNode;
					inbalanceNode->leftChild = leftChildPointer->rightChild;
					leftChildPointer->rightChild = inbalanceNode;
					inbalanceNode->parent = leftChildPointer;
				}
				R(leftChildPointer->leftChild);
			}
			
			void LL(node* inbalanceNode){
				node* rightChildPointer = new node;
				rightChildPointer = inbalanceNode->rightChild;
				if(inbalanceNode == root){
					rightChildPointer->parent = NULL;
					if(rightChildPointer->leftChild != NULL){
						rightChildPointer->leftChild->parent = inbalanceNode;
					}
					inbalanceNode->rightChild = rightChildPointer->leftChild;
					rightChildPointer->leftChild = inbalanceNode;
					inbalanceNode->parent = rightChildPointer;
					root = rightChildPointer;
				}
				else{
					int parentChildFlag = 0; // 0: left, 1: right
					if(inbalanceNode->data > inbalanceNode->parent->data) parentChildFlag = 1;
					if(parentChildFlag == 0) inbalanceNode->parent->leftChild = rightChildPointer;
					else inbalanceNode->parent->rightChild = rightChildPointer;
					rightChildPointer->parent = inbalanceNode->parent;
					if(rightChildPointer->leftChild != NULL) rightChildPointer->leftChild->parent = inbalanceNode;
					inbalanceNode->rightChild = rightChildPointer->leftChild;
					rightChildPointer->leftChild = inbalanceNode;
					inbalanceNode->parent = rightChildPointer;
				}
				L(rightChildPointer->rightChild);
			}
			
			void RO(node* inbalanceNode){
				node* leftChildPointer = new node;
				leftChildPointer = inbalanceNode->leftChild;
				if(inbalanceNode == root){
					leftChildPointer->parent = NULL;
					if(leftChildPointer->rightChild != NULL) leftChildPointer->rightChild->parent = inbalanceNode;
					inbalanceNode->leftChild = leftChildPointer->rightChild;
					leftChildPointer->rightChild = inbalanceNode;
					inbalanceNode->parent = leftChildPointer;
					root = leftChildPointer;
				}
				else{
					int parentChildFlag = 0; // 0: left, 1: right
					if(inbalanceNode->data > inbalanceNode->parent->data) parentChildFlag = 1;
					if(parentChildFlag == 0) inbalanceNode->parent->leftChild = leftChildPointer;
					else inbalanceNode->parent->rightChild = leftChildPointer;
					leftChildPointer->parent = inbalanceNode->parent;
					if(leftChildPointer->rightChild != NULL) leftChildPointer->rightChild->parent = inbalanceNode;
					inbalanceNode->leftChild = leftChildPointer->rightChild;
					leftChildPointer->rightChild = inbalanceNode;
					inbalanceNode->parent = leftChildPointer;
				}
			}
			
			void LO(node* inbalanceNode){
				node* rightChildPointer = new node;
				rightChildPointer = inbalanceNode->rightChild;
				if(inbalanceNode == root){
					rightChildPointer->parent = NULL;
					if(rightChildPointer->leftChild != NULL){
						rightChildPointer->leftChild->parent = inbalanceNode;
					}
					inbalanceNode->rightChild = rightChildPointer->leftChild;
					rightChildPointer->leftChild = inbalanceNode;
					inbalanceNode->parent = rightChildPointer;
					root = rightChildPointer;
				}
				else{
					int parentChildFlag = 0; // 0: left, 1: right
					if(inbalanceNode->data > inbalanceNode->parent->data) parentChildFlag = 1;
					if(parentChildFlag == 0) inbalanceNode->parent->leftChild = rightChildPointer;
					else inbalanceNode->parent->rightChild = rightChildPointer;
					rightChildPointer->parent = inbalanceNode->parent;
					if(rightChildPointer->leftChild != NULL) rightChildPointer->leftChild->parent = inbalanceNode;
					inbalanceNode->rightChild = rightChildPointer->leftChild;
					rightChildPointer->leftChild = inbalanceNode;
					inbalanceNode->parent = rightChildPointer;
				}
			}
			
			void LR(node* inbalanceNode){
				node* leftChildPointer = new node;
				leftChildPointer = inbalanceNode->leftChild;
				inbalanceNode->leftChild = leftChildPointer->rightChild;
				leftChildPointer->rightChild->parent = inbalanceNode;
				if(leftChildPointer->rightChild->leftChild != NULL) leftChildPointer->rightChild->leftChild->parent = leftChildPointer;
				leftChildPointer->rightChild = leftChildPointer->rightChild->leftChild;
				inbalanceNode->leftChild->leftChild = leftChildPointer;
				leftChildPointer->parent = inbalanceNode->leftChild;
				RO(inbalanceNode);
			}
			
			void RL(node* inbalanceNode){
				node* rightChildPointer = new node;
				rightChildPointer = inbalanceNode->rightChild;
				inbalanceNode->rightChild = rightChildPointer->leftChild;
				rightChildPointer->leftChild->parent = inbalanceNode;
				if(rightChildPointer->leftChild->rightChild != NULL) rightChildPointer->leftChild->rightChild->parent = rightChildPointer;
				rightChildPointer->leftChild = rightChildPointer->leftChild->rightChild;
				inbalanceNode->rightChild->rightChild = rightChildPointer;
				rightChildPointer->parent = inbalanceNode->rightChild;
				LO(inbalanceNode);
			}
			
			void R(node* splayNode){
				if(splayNode->parent == root){
					if(splayNode->rightChild != NULL) splayNode->rightChild->parent = splayNode->parent;
					splayNode->parent->leftChild = splayNode->rightChild;
					splayNode->rightChild = splayNode->parent;
					splayNode->parent = NULL;
					splayNode->rightChild->parent = splayNode;
					root = splayNode;	
				}
				else{
					node* splayParent = new node;
					splayParent = splayNode->parent;
					splayNode->parent = splayParent->parent;
					int parentChildFlag = 0; // 0: left, 1: right
					if(splayParent->data > splayParent->parent->data) parentChildFlag = 1;
					if(parentChildFlag == 0) splayParent->parent->leftChild = splayNode;
					else splayParent->parent->rightChild = splayNode; // no change
					if(splayNode->rightChild != NULL) splayNode->rightChild->parent = splayParent;
					splayParent->leftChild = splayNode->rightChild;
					splayNode->rightChild = splayParent;
					splayParent->parent = splayNode;
				}
			}
			
			void L(node* splayNode){
				if(splayNode->parent == root){
					if(splayNode->leftChild != NULL) splayNode->leftChild->parent = splayNode->parent;
					splayNode->parent->rightChild = splayNode->leftChild;
					splayNode->leftChild = splayNode->parent;
					splayNode->parent = NULL;
					splayNode->leftChild->parent = splayNode;
					root = splayNode;
				}
				else{
					node* splayParent = new node;
					splayParent = splayNode->parent;
					splayNode->parent = splayParent->parent;
					int parentChildFlag = 0; // 0: left, 1: right
					if(splayParent->data > splayParent->parent->data) parentChildFlag = 1;
					if(parentChildFlag == 0) splayParent->parent->leftChild = splayNode;
					else splayParent->parent->rightChild = splayNode; // no change
					if(splayNode->leftChild != NULL) splayNode->leftChild->parent = splayParent;
					splayParent->rightChild = splayNode->leftChild;
					splayNode->leftChild = splayParent;
					splayParent->parent = splayNode;
				}
			}
			
			void splay(node* splayNode){
				int rotationCase;
				while(splayNode != root){
					rotationCase = caseFinder(splayNode);
					switch(rotationCase){
						case 1: R(splayNode);
								break;
						case 2: L(splayNode);
								break;
						case 3: RR(splayNode->parent->parent);
								break;
						case 4: RL(splayNode->parent->parent);
								break;
						case 5: LR(splayNode->parent->parent);
								break;
						case 6: LL(splayNode->parent->parent);
								break;
					}
				}
			}
			
			void printPreOrder(node* base){
				if(base == NULL) return;
				cout<<base->data<<", ";
				printPreOrder(base->leftChild);
				printPreOrder(base->rightChild);
			}
		public:
			SplayTree(){
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
				}
				else root = temp;
				splay(temp);
			}
			
			void print(){
				printPreOrder(root);
			}
	};
}

#endif
