# ~~vslib~~ DsLib

### General purpose Data Structures Library
--------------------------------------------------------------------------------------------------------------------------------------

### Components
1.  **Multiway Trees**: This component is helpful in creating multiway trees for various data types in c++. Supported data types given are below.

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
    * Pointer
    * Funcion
  
   It provides 2 ways to create a tree:
   
      1. Direct: Directly provide the value.
      2. Inderect: Insert Pointer to the value.
   
   To create tree first include the Tree.hpp file in the program then create one using Tree<<Data Type>> <name of Tree> eg. ```Tree<int> myTree```. After this use following to play with your tree:
   * insert(<value or pointer>) : Insert the value to tree at the current node.
   * deleteByValue(<value>) : Delete first appearing value in DFS of tree.
   * search(<value>) : This will return path to that child.
   * toParent() : Makes parent of current node as new current node.
   * toChild(<value of child>) : Makes child of current node as new current node appearing first from left to right.
   * toSibling() : Makes right sibling of current node as new current node.
   * toRoot() : Makes root of tree as new current node.
   * print() : Prints the tree in preorder.

2.  **AVL Trees**:
