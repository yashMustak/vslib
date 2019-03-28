#ifndef vslib_Stacks
#define vslib_Stacks

#include <iostream>
#include "doubly_linked_list.h"
using namespace std;

namespace vip {
	template<class T>
	class stack {
		private:
			DoublyLinkedList<T *> mainStack;
			DoublyLinkedList<T> dataHolder;
			int top;
		public:
			stack();
			void push(T value);
			void push(T * value);
			T pop();
			bool isEmpty();
	};
}

template<class T>
 bool vip::stack<T>::isEmpty(){
	if(top == -1)return true;
	else return false;
}

template<class T>
vip::stack<T>::stack() {
	top = -1;
}

template<class T>
void vip::stack<T>::push(T value) {
	dataHolder.insert(value);
	mainStack.insert(dataHolder.lastDataReference());
	top++;
}

template<class T>
void vip::stack<T>::push(T * value) {
	mainStack.insert(value);
	top++;
}


/*The pop function removes the last member of dataHolder list
* this is a problem since if the data is directly addressed by the user
* and not in the dataHolder list, then we will lose the data from dataHolder
* instead of this just try to check weather if the data, which is refferenced
* in main stack is from dataHolder or directly addressed by the user.
* To check, we must add some functionality in linkedlist file 
* which could give access of looping in list or just tell me
* weather this refference(the refference which is poped) is of any member in it. */

template<class T>
T vip::stack<T>::pop() {
	if(top>=0){
		T * poped = mainStack[top];
		T popedData = *poped;
		top--;
		mainStack.deleteLast();
		dataHolder.deleteLast();
		return popedData;
	}
	//else ecxeption
}

#endif
