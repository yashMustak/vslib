#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include<iostream>
using namespace std;
#include<stdlib.h>

namespace vip {
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
	//Node* newNode();
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

//might be some bug
template<class T>
void vip::DoublyLinkedList<T>::deleteLast(){
	Node * traversal = head;
	if(head != NULL){
		while(traversal->next)traversal = traversal->next;
		if(traversal == head) head = NULL;
		else traversal->prev->next = NULL;  //traversal->next;
		free(traversal);
	}
}
//bug end

template<class T>
T vip::DoublyLinkedList<T>::operator [](int i) {
	Node * traversal = head;
	if(head != NULL){
		while(i--)traversal=traversal->next;
		return traversal->data;
	}
}

template<class T>
T * vip::DoublyLinkedList<T>::lastDataReference(){
	Node * traversal = head;
	if(head != NULL){
		while(traversal->next)traversal = traversal->next;
		return &traversal->data;
	}
}

template<class T>
vip::DoublyLinkedList<T>::DoublyLinkedList() {
	head = NULL;
	tail = NULL;
}

template<class T>
void vip::DoublyLinkedList<T>::insert(T data) {
	Node* new_node = new Node;
	new_node->data = data;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (head == NULL) {
		head = new_node;
		tail = new_node;
	}
	else {
		Node* node = head;
		Node* temp = head;
		while (node) {
			temp = node;
			node = node->next;
		}
		temp->next = new_node;
		new_node->prev = temp;
		tail = new_node;
	}
}

template<class T>
void vip::DoublyLinkedList<T>::print() {
	Node* node = head;
	while (node) {
		if (node == head) cout << node->data;
		else cout << " -> " << node->data;
		node = node->next;
	}
}

template<class T>
void vip::DoublyLinkedList<T>::deleteNodeByValue(T data) {
	Node* node = head;
	Node* temp = head;
	while(node->data != data){
		temp = node;
		node = node->next;
	}
	if(node == head){
		head = head->next;
		head->prev = NULL;
		delete node;
	}else{
		temp->next = node->next;
		if(node->next) node->next->prev = temp;
		else tail = temp;
		delete node;
	}
}

template<class T>
bool vip::DoublyLinkedList<T>::valueExist(T data) {
	Node* node = head;
	while (node) {
		if (node->data == data) return true;
	}
	return false;
}
#endif
