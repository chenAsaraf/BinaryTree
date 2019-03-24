#pragma once

#include <iostream>


class Node {
    private: 
        int data;
        Node* right; //pointer?
        Node* left; //pointer?
        Node* parent;        
        
    public:
       // Node() : Node(NULL, nullptr) {} not nessecary?
        Node(int data) : Node(data, nullptr, nullptr, nullptr) {}
        Node(int data, Node* right, Node* left, Node* parent) :
        data(data), right(right), left(left), parent(parent) {}
         
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
        Node* root;
        int size;
        /*Private Methods*/
        void destroyTree();
        Node insert(int i);
        
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
        int size();
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
        
        
};

