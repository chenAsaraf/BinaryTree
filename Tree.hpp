#pragma once

#include <string>
#include <iostream>

namespace ariel {

 
   
class Node {

        int data;
        Node* right; 
        Node* left; 
        Node* parent;        
        
    public:
        Node();
        Node(int data);
        Node(int data, Node* right, Node* left, Node* parent);

	       ~Node();

         //Getters and Setters of Node 
        void setData(int data);
        void setRight(Node* newRight);
        void setLeft(Node* newLeft);
	       void setParent(Node* newParent);
        int getData() const;
        Node* getRight() const;
        Node* getLeft() const;
	       Node* getParent() const;

         Node* operator = (Node* els){
            Node* temp=new Node();
            temp->setData(els->getData());
            temp->setRight(els->getRight()); 
             temp->setLeft(els->getLeft()); 
            temp->setParent(els->getParent());
            return temp;

        }
      
};

class Tree {

        Node* treeRoot;
        uint treeSize;
     /*Private Methods*/
        void destroyTree(Node* node);
        Node* insert(Node* leaf, int i);
        Node* search(Node* leaf, int i);
        void setSize(int i);
        Node* root1();

    public:

    
        //constructor & deconstructor
        Tree();
       // Tree(Tree other);
        ~Tree();
    
        /*Public Methods*/
        
        //insert the number i to the correct node in the binary tree
        void insert(int i); //throw exception when already axist
        //remove the number i from the tree
        void remove(int i); //throw exception when not exist
	void remove(Node* key_pointer);
        //returns the size of the tree
        uint size();
        //returns "true" if the number i exists in the tree
        bool contains(int i);
        //returns the data in the root
        int root();
        //returns the parent's data of the input
        int parent(int i);
        //returns the left child's data of the input
        int left(int i);
        //returns the right child's data of the input
        int right(int i);
        //print the tree
        void print();
        //operator:
	void print(Node *leaf);
       
        
};//end class Tree
} //end namespace ariel
