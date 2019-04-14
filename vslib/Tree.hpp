#ifndef General_Tree
#define General_Tree

#include <iostream>
#include <queue>//update with self library
#include <vector>
#include <stack>//update with self library
#include <stdlib.h>
#include "singly_linked_list.h"
using namespace std;

namespace dslib {
	template<class T>
	void defaultNodePrint (T * nodeData) {
		cout << *nodeData << ", ";
	}
	
	template<class T>
	class Tree {
		private:
			struct node {
				T * data;
				node * firstChild;
				node * parent;
				node * sibling;
			};
			node * head;
			node * current;
			SinglyLinkedList<T> referenceDataList;
			void freemem(node * deletedNode);
		
		public:
			Tree();
			void insert (T * value);
			void insert (T value);
			void deleteByValue (T value, int occurance = 1);
			void deleteByValue (T * value, int occurance = 1);
			bool search(T searchValue);
			bool search(T * searchValue);
			void print (void (&nodePrint)(T* nodeData) = defaultNodePrint);
			//typename node* search(T searchNode, node* current = head);
			void toParent();
			void toChild(T *childData);
			void toChild(T childData);
			void toRoot();
			void toSibling();
	};	

} 
#include 'Tree_impl.hpp'
#endif
