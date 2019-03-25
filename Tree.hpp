#pragma once

#include <iostream>


class Node {
    private: 
        int data;
        Node* right; //pointer?
        Node* left; //pointer?
        Node* parent;        
        
    public:
        Node(){
          parent=NULL;
          left=NULL;
          right=NULL;
          data=NULL;
        }
        Node(int data) : Node(data, nullptr, nullptr, nullptr) {}
        Node(int data, Node* right, Node* left, Node* parent) :
        data(data), right(right), left(left), parent(parent) {}
        friend Node search(int i, Node *leaf);
         
        // int& data(); //setter
        // const int data() const; //getter
        // Node*& right();  //setter ->> how to write Node*&?
        // const Node* right const; //getter
        // Node*& left(); //setter
        // const Node* left() const; //getter
        // string toString() const;
};

class Tree {
    private:
        Node* rootOf;
        int sizeOf;
        /*Private Methods*/
        
        
    public:
        //constructor & deconstructor
        Tree();
        ~Tree(){}
    
        /*Public Methods*/
        Node insert(int i);
        void insertNode(int i, Node *leaf);
        //remove the number i from the tree
        void remove(int i); //throw exception when not exist
        //returns the size of the tree
        int size();
        //returns "true" if the number i exists in the tree
        bool contains(int i);
        +//returns the data in the root
        int root();
        +//returns the parent's data of the input
        int parent(int i);
        friend Node search(int i, Node *leaf);
        void destroyTreeHelp(Node *leaf);
        +//returns the left child's data of the input
        int left(int i);
        +//returns the right child's data of the input
        int right(int i);
        +//print the tree
        void print();
	
        
};

