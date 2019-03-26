#pragma once
#include <string>
#include <iostream>

namespace ariel {

 
   
class Node {

        int data;
        Node* right; //pointer?
        Node* left; //pointer?
        Node* parent;        
        
    public:
        Node() : Node(NULL, nullptr, nullptr, nullptr) {} 
        Node(int data) : Node(data, nullptr, nullptr, nullptr) {}
        Node(int data, Node* right, Node* left, Node* parent) :
        data(data), right(right), left(left), parent(parent) {}
         
        //  int& data(); //setter
        //  const int data() const; //getter
        //  Node*& right();  //setter ->> how to write Node*&?
        //  const Node* right const; //getter
        //  Node*& left(); //setter
        //  const Node* left() const; //getter
        
        std::string toString() const;
        
        //Getters and Setters of Node 
        void setData(int data){
            this->data = data;
        }
        void setRight(Node* newRight){
             this->right = newRight;
        }
        void setLeft(Node* newLeft){
            this->left = newLeft;
        }
        int getData() const{
                return this->data;
        }
        Node* getRight() const{
                return this->right;
        }
        Node* getLeft() const{
                return this->left;
        }
};

class Tree {

        Node* treeRoot;
        uint treeSize;
     /*Private Methods*/
        Node* destroyTree(Node* node);
        Node* insert(Node* leaf, int i);
        Node* search(Node* leaf, int i);
        void setSize(int i);
        Node* getRoot();

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
        
        
};
};
