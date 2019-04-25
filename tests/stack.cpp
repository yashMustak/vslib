#include<iostream>
#include"../vslib/Tree.hpp"
#include "../vslib/stack.hpp"
using namespace std;
using namespace vip;

int main(){

	vip::Stack<int> mystack;
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
	int val = 10;
	mystack.push(&val);
	cout<<"pushed 10 with reference"<<endl;
	cout<<mystack.pop()<<endl;
	cout<<mystack.pop()<<endl; //this will give random value (problem is highlited in stack file)
	return 0;
}
