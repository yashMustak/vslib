#include "doubly_linked_list.hpp"

template<class T>
dslib::DoublyLinkedList<T>::DoublyLinkedList() {
	head = NULL;
	tail = NULL;
}

//*
template<class T>
void dslib::DoublyLinkedList<T>::deleteLast(){
	Node * traversal = head;
	if(head != NULL){
		while(traversal->next)traversal = traversal->next;
		if(traversal == head) head = NULL;
		else traversal->prev->next = NULL;  //traversal->next;
		free(traversal);
	}
}
*//

template<class T>
T dslib::DoublyLinkedList<T>::operator [](int i) {
	Node * traversal = head;
	if(head != NULL){
		while(i--)traversal=traversal->next;
		return traversal->data;
	}
}

template<class T>
T * dslib::DoublyLinkedList<T>::lastDataReference(){
	Node * traversal = head;
	if(head != NULL){
		while(traversal->next)traversal = traversal->next;
		return &traversal->data;
	}
}

template<class T>
void dslib::DoublyLinkedList<T>::insert(T data) {
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
void dslib::DoublyLinkedList<T>::print() {
	Node* node = head;
	while (node) {
		if (node == head) cout << node->data;
		else cout << " -> " << node->data;
		node = node->next;
	}
}

template<class T>
void dslib::DoublyLinkedList<T>::deleteNodeByValue(T data) {
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
bool dslib::DoublyLinkedList<T>::valueExist(T data) {
	Node* node = head;
	while (node) {
		if (node->data == data) return true;
	}
	return false;
}
