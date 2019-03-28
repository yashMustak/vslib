#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include<iostream>
using namespace std;
//#include<stdlib.h>

namespace vip {
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

template<class T>
vip::SinglyLinkedList<T>::SinglyLinkedList() {
	head = NULL;
}

template<class T>
bool vip::SinglyLinkedList<T>::isEmpty() {
	return head == NULL;
}

template<class T>
T * vip::SinglyLinkedList<T>::lastReference(){
	Node * traversal = head;
	while(traversal->next)traversal = traversal->next;
	return &traversal->data;
}

/*
template<class T>
vip::SinglyLinkedList<T>::Node* vip::SinglyLinkedList<T>::newNode() {
	Node* node = (Node*)malloc(sizeof(Node));
	return node;
}
*/

template<class T>
void vip::SinglyLinkedList<T>::insert(T data) {
	//Node* new_node = newNode();
	Node* new_node = new Node;
	new_node->data = data;
	new_node->next = NULL;
	if (head == NULL) {
		head = new_node;
	}
	else {
		Node* node = head;
		Node* temp = head;
		while (node) {
			temp = node;
			node = node->next;
		}
		temp->next = new_node;
	}
}

template<class T>
void vip::SinglyLinkedList<T>::print() {
	Node* node = head;
	while (node) {
		if (node == head) cout << node->data;
		else cout << " -> " << node->data;
		node = node->next;
	}
}

template<class T>
void vip::SinglyLinkedList<T>::deleteNodeByValue(T data, int occurence) {
    Node* node = head;
    Node* temp = head;
    while(node){
        if(node->data == data){
        	occurence--;
        	if(occurence == 0)break;
		}
		temp = node;
        node = node->next;
    }
    if(node == head){
        head = head->next;
        delete node;
    }else{
    	if(node){
    		temp->next = node->next;
        	delete node;
		}
    }
}

template<class T>
bool vip::SinglyLinkedList<T>::valueExist(T data) {
	Node* node = head;
	while (node) {
		if (node->data == data) return true;
	}
	return false;
}
#endif
