#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include<iostream>
#include<stdlib.h>

using namespace std;

namespace dslib {
	template<class T>
	class DoublyLinkedList;
}

template<class T>
class vip::DoublyLinkedList{
private:
	struct Node{
		T data;
		Node* prev;
		Node* next;
	};
	Node* head;
	Node* tail;

public:
	DoublyLinkedList();
	void insert(T data);
	void print();
	bool valueExist(T data);
	void deleteNodeByValue(T data);
	T operator [](int i);
	T * lastDataReference();
	void deleteLast(); //temporary replacement for delete by reference
	//size
	//isEmpty
	//firstReference
	//iterators
};
#include 'doubly_linked_list_impl.hpp'
#endif
