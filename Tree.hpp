#pragma once

#include <iostream>


class Node {
    private: 
        int data;
        Node* right; //pointer?
        Node* left; //pointer?
        
        
    public:
       // Node() : Node(NULL, nullptr) {} not nessecary?
        Node(int data) : Node(data, nullptr, nullptr) {}
        Node(int data, Node* right, Node* left) : data(data), right(right), left(left) {}
         
        int& data(); //setter
        const int data() const; //getter
        Node*& right();  //setter ->> how to write Node*&?
        const Node* right const; //getter
        Node*& left(); //setter
        const Node* left() const; //getter
        string toString() const;
};

class Tree {
    private:
        Node* root;
        
        /*Private Methods*/
        void destroyTree(Node* node);
        
    public:
        //constructor & deconstructor
        Tree();
        ~Tree();
    
        /*Public Methods*/
        void destroyTree();
        //insert the number i to the correct node in the binary tree
        void insert(int i); //throw exception when already axist
        //remove the number i from the tree
        void remove(int i); //throw exception when not exist
        //returns the size of the tree
        int size() const;
        //returns "true" if the number i exists in the tree
        bool contains(int i);
        //returns the data in the root
        int root();
        //returns the parent's data of the input
        int parent(int child);
        //returns the left child's data of the input
        int left(int parent);
        //returns the right child's data of the input
        int right(int parent);
        //print the tree
        void print();
        
        
};

