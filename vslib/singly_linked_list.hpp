#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include<iostream>
using namespace std;

namespace dslib
	template<class T>
	class SinglyLinkedList;
}

template<class T>
class vip::SinglyLinkedList {
private:
	struct Node{
		T data;
		struct Node* next;
	};
	Node* head;
public:
	SinglyLinkedList();
	void insert(T data);
	void print();
	Node* newNode();
	bool valueExist(T data);
	void deleteNodeByValue(T data, int occurence = 1);
	T * lastReference();
	bool isEmpty();
	//void deleteByReference()
};
#inclide 'singly_linked_list_impl.hpp'
#endif
