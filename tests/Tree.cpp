#include<iostream>
#include"Tree.hpp"
#include "stack.hpp"
using namespace std;
using namespace vip;

int main(){
	Tree<int> mytree;
	mytree.insert(1);
	mytree.toRoot();
	mytree.insert(2);
	mytree.insert(3);
	mytree.insert(4);
	mytree.insert(3);
	mytree.insert(5);
	mytree.toChild(4);
	mytree.insert(9);
	mytree.insert(10);
	//mytree.toParent();
	mytree.toSibling();
	mytree.insert(12);
	mytree.print();
	mytree.deleteByValue(3, 2);
	cout<<endl;
	mytree.print();
return 0;
}
