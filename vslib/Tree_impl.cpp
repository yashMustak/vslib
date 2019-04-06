#include "Tree.hpp"

template<class T>
dslib::Tree<T>::Tree(){
	head = NULL;
	current = head;
}

//search
//delete

template<class T>
bool dslib::Tree<T>::search(T searchValue){
	queue<node *> bfsQueue;
	int flag = 0;
	if(head != NULL) {
		node * traversal = head;
		bfsQueue.push(traversal);
		while(!bfsQueue.empty()) {
			traversal = bfsQueue.front();
			bfsQueue.pop();
			if(*traversal->data == searchValue) {
				flag = 1;
				break;
			}
			if(traversal->firstChild != NULL) {
				node * childTraversal = traversal->firstChild;
				while (childTraversal) {
					bfsQueue.push (childTraversal);
					childTraversal = childTraversal->sibling;
				}
			}
		}
	}
	if(flag == 1)return true;
	else return false;
}

template<class T>
bool dslib::Tree<T>::search(T * searchValue){
	queue<node *> bfsQueue;
	int flag = 0;
	if(head != NULL) {
		node * traversal = head;
		bfsQueue.push(traversal);
		while(!bfsQueue.empty()) {
			traversal = bfsQueue.front();
			bfsQueue.pop();
			if(traversal->data == searchValue) {
				flag = 1;
				break;
			}
			if(traversal->firstChild != NULL) {
				node * childTraversal = traversal->firstChild;
				while (childTraversal) {
					bfsQueue.push (childTraversal);
					childTraversal = childTraversal->sibling;
				}
			}
		}
	}
	if(flag == 1)return true;
	else return false;
}

template<class T>
void dslib::Tree<T>::freemem(node * deletedNode) {
	stack<node *> stk;
	stk.push(deletedNode);
	node * del = new node;
	del = deletedNode;
	while (!stk.empty()) {
		del = stk.top();
		stk.pop();
		if (del->firstChild != NULL) {
			node* q = new node;
			q = deletedNode->firstChild;
			while (q->sibling != NULL) {
				stk.push(q);
				q = q->sibling;
			}
		}
		free(del);
	}
}

template<class T>
void dslib::Tree<T>::deleteByValue (T value, int occurance) {
	queue<node *> bfsQueue;
	int flag = 0;
	if(head != NULL) {
		int tempoccur = occurance;
		node * traversal = head;
		bfsQueue.push(traversal);
		while(!bfsQueue.empty()) {
			traversal = bfsQueue.front();
			bfsQueue.pop();
			if(*traversal->data == value) {
				tempoccur--;
				if(tempoccur == 0) {
					flag = 1;
					break;
				}
			}
			if(traversal->firstChild != NULL) {
				node * childTraversal = traversal->firstChild;
				while (childTraversal) {
					bfsQueue.push (childTraversal);
					childTraversal = childTraversal->sibling;
				}
			}
		}
		if(flag == 1) {
			node * tempParent;
			node * tempSibling;
			tempParent = traversal->parent;
			tempSibling = tempParent->firstChild;
			while(tempSibling->sibling != traversal) tempSibling = tempSibling->sibling;
			tempSibling->sibling = traversal->sibling;
			referenceDataList.deleteNodeByValue(*traversal->data, occurance);
			freemem(traversal);
		}
		//else through message
	}//else through message
}

template<class T>
void dslib::Tree<T>::deleteByValue (T * value, int occurance) {
	queue<node *> bfsQueue;
	int flag = 0;
	if(head != NULL) {
		int tempoccur = occurance;
		node * traversal = head;
		bfsQueue.push(traversal);
		while(!bfsQueue.empty()) {
			traversal = bfsQueue.front();
			bfsQueue.pop();
			if(traversal->data == value) {
				tempoccur--;
				if(tempoccur == 0) {
					flag = 1;
					break;
				}
			}
			if(traversal->firstChild != NULL) {
				node * childTraversal = traversal->firstChild;
				while (childTraversal) {
					bfsQueue.push (childTraversal);
					childTraversal = childTraversal->sibling;
				}
			}
		}
		if(flag == 1) {
			node * tempParent;
			node * tempSibling;
			tempParent = traversal->parent;
			tempSibling = tempParent->firstChild;
			while(tempSibling->sibling != traversal) tempSibling = tempSibling->sibling;
			tempSibling->sibling = traversal->sibling;
			freemem(traversal);
		}
		//else through message
	}//else through message
}

template<class T>
void dslib::Tree<T>::toParent (){
	if(current->parent != NULL) current = current->parent;
}

template<class T>
void dslib::Tree<T>::toRoot(){
	current = head;
}

template<class T>
void dslib::Tree<T>::toChild(T *childData){
	node * traversal = current;
	if(current->firstChild != NULL){
		traversal = current->firstChild;
		while(traversal){
			if(traversal->data == childData) break;
			traversal = traversal->sibling;
		}
		if(traversal != NULL) current = traversal;
	}
}

template<class T>
void dslib::Tree<T>::toChild(T childData){
	node * traversal = current;
	if(current->firstChild != NULL){
		traversal = current->firstChild;
		while(traversal){
			if(*traversal->data == childData) break;
			traversal = traversal->sibling;
		}
		if(traversal != NULL) current = traversal;
	}
}

template<class T>
void dslib::Tree<T>::toSibling(){
	if(current->sibling != NULL) current = current->sibling;
}

template<class T>
void dslib::Tree<T>::insert (T * value) {
	node * temp = new node;
	temp->data = value;
	temp->firstChild = NULL;
	temp->sibling = NULL;
	temp->parent = NULL;
	if (current == NULL) head = temp;
	else {
		if (current->firstChild == NULL) {
			current->firstChild = temp;
		}
		else {
			node * q = new node;
			node * p = new node;
			q = current->firstChild;
			p = current->firstChild;
			while (q->sibling != NULL) {
				q = q->sibling;
			}
			q->sibling = temp;
		}
	}
}

template<class T>
void dslib::Tree<T>::insert (T value) {
	referenceDataList.insert(value);
	node * temp = new node;
	temp->data = referenceDataList.lastReference();
	temp->firstChild = NULL;
	temp->sibling = NULL;
	temp->parent = current;
	if (current == NULL) head = temp;
	else{
		if (current->firstChild == NULL) {
			current->firstChild = temp;
		}
		else {
			node * q = new node;
			node * p = new node;
			q = current->firstChild;
			p = current->firstChild;
			while (q->sibling != NULL) {
				q = q->sibling;
			}
			q->sibling = temp;
		}
	}
}

template<class T>
void dslib::Tree<T>::print (void (&nodePrint)(T* nodeData)) {
	node * traversal;
	queue<node*> bfsQueue;
	bfsQueue.push(head);
	while (!bfsQueue.empty()) {
		traversal = bfsQueue.front();
		bfsQueue.pop();
		nodePrint(traversal->data);
		if(traversal->firstChild != NULL) {
			node* childTraversal = traversal->firstChild;
			while(childTraversal != NULL) {
				bfsQueue.push(childTraversal);
				childTraversal = childTraversal->sibling;
			}
		}
	}
}
