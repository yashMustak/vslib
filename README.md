# ~~vslib~~ DsLib

### General purpose Data Structures Library
--------------------------------------------------------------------------------------------------------------------------------------

### Components
1.  **```Multiway Trees```**: This component is helpful in creating multiway trees for various data types in c++. Supported data types given are below.

    * Object
    * Structure
    * Union
    * Enum
    * Character
    * String
    * Double
    * Float
    * Integer
    * Long
    * Short
    * Boolean
    * Pointer
    * Funcion
  
   It provides 2 ways to create a tree:
   
      1. Direct: Directly provide the value.
      2. Indirect: Insert Pointer to the value.
   
   To create tree first include the Tree.hpp file in the program then create one using Tree< < Data Type > > < name of Tree > eg. ```Tree<int> myTree```. After this use following to play with your tree:
   * insert(< value or pointer >) : Insert the value to tree at the current node.
   * deleteByValue(< value >) : Delete first appearing value in DFS of tree.
   * search(< value >) : This will return path to that child.
   * toParent() : Makes parent of current node as new current node.
   * toChild(< value of child >) : Makes child of current node as new current node appearing first from left to right.
   * toSibling() : Makes right sibling of current node as new current node.
   * toRoot() : Makes root of tree as new current node.
   * print() : Prints the tree in preorder.
   
   Example:
   ```
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
	mytree.toSibling();
	mytree.insert(12);
	mytree.print();
	mytree.deleteByValue(3, 2);
	cout<<endl;
	mytree.print();
   ```

2.  **AVL Trees**: This component helps to create an AVL tree same as previous, it also supports described data types. Presently only insert and print are implemented.

3.  **Splay Tree**: This component helps to create an Splay tree same as previous, it also supports described data types. Presently only insert and print are implemented.

4.  **Singly Linked List**: This component helps to create Singly linked list. Presently it only support direct insertion (Pointer insertion is unavailable, which reduces data type list to Char, String, Int, Bouble, Float, Boolean). It provides various functions to play with it as listed below.
   * insert(< value >)
   * deleteNodeByValue(< value >)
   * valueExist(< value >)
   * isEmpty()
   * print()
   
   Example:
   ```
   SinglyLinkedList<int> list;
	list.insert(10);
	list.insert(11);
	list.insert(12);
	list.print();
	cout<<endl;
	list.deleteNodeByValue(11);
	list.print();
	cout<<endl;
	cout.setf(ios::boolalpha);
	cout<<"Q. 10 Exists?: "<<list.valueExist(10)<<endl;
	cout<<"Q. 11 Exists?: "<<list.valueExist(11)<<endl;
   ```
 
5.  **Doubly Linked List**: This component helps to create Doubly linked list. Presently it only support direct insertion (Pointer insertion is unavailable, which reduces data type list to Char, String, Int, Bouble, Float, Boolean). It provides various functions to play with it as listed below.
   * insert(< value >)
   * deleteNodeByValue(< value >)
   * valueExist(< value >)
   * deleteLast()
   * print()
   * [< index >] : Operator to access element using index.
   
   Example:
   ```
   DoublyLinkedList<int> list;
	list.insert(10);
	list.insert(11);
	list.insert(12);
	list.print();
	cout<<endl;
	list.deleteNodeByValue(11);
	list.print();
	cout<<endl;
	cout.setf(ios::boolalpha);
	cout<<"Q. 10 Exists?: "<<list.valueExist(10)<<endl;
	cout<<"Q. 11 Exists?: "<<list.valueExist(11)<<endl;
   ```

6.  **Stack**: This component helps to create stacks. Both direct and inderect mode of stacks are available for this. following are the available functions regarding stacks:
   * push(< value or pointer >)
   * pop()
   * isEmpty()
   
   Example:
   ```
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
	mystack.push(9);
	int val = 10;
	mystack.push(&val);
	cout<<"pushed 10 with reference"<<endl;
	cout<<mystack.pop()<<endl;
	cout<<mystack.pop()<<endl;
   ```
