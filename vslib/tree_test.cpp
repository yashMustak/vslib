#include<iostream>
#include"Tree.hpp"
#include "stack.hpp"
using namespace std;
using namespace vip;

int main(){
//	Tree<int> mytree;
//	mytree.insert(1);
//	mytree.toRoot();
//	mytree.insert(2);
//	mytree.insert(3);
//	mytree.insert(4);
//	mytree.insert(3);
//	mytree.insert(5);
//	mytree.toChild(4);
//	mytree.insert(9);
//	mytree.insert(10);
//	//mytree.toParent();
//	mytree.toSibling();
//	mytree.insert(12);
//	mytree.print();
//	mytree.deleteByValue(3, 2);
//	cout<<endl;
//	mytree.print();

	vip::stack<int> mystack;
	mystack.push(1);
	cout<<"pushed 1"<<endl;
	mystack.push(3);
	cout<<"pushed 3"<<endl;
	mystack.push(5);
	cout<<"pushed 5"<<endl;
	cout<<mystack.pop()<<endl;
	cout<<mystack.pop()<<endl;
	cout<<mystack.pop()<<endl;
	//cout<<mystack.pop()<<endl;
	mystack.push(9);
	int yash = 10;
	mystack.push(&yash);
	cout<<"pushed 10 with reference"<<endl;
	cout<<mystack.pop()<<endl;
	cout<<mystack.pop()<<endl; //this will give random value (problem is highlited in stack file)
	return 0;
}
