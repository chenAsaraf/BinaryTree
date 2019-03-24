#include "Tree.hpp"


//implementation of Node class: 
Node void::setData(int data){
    this->data = data;
}

Node void::setRight(Node* newRight){
    this->right = right;
}

Node void::setLeft(Node* newLeft){
    this->left = left;
}

Node int::getData() const{
    return this->data;
}

Node Node*::getRight() const{
    return this->right;
}

Node Node*::getLeft() const{
    return this->left;
}

Node string::toString() const{
    string node = "[ " + this->data + " ]"; //like that?
    return node;
}

////////////////////////////////////

//Implemantation of Binary Tree:

//Pribvate methods
Tree void::destroyTree(Node* node){
    
}

Tree Node::insert(Node* node, int key){
    // if the Binary Search Tree doesn't exist yet, create new tree with this as a root
    if(node==nullptr){
        node = new Node;
        node->data= key;
        node->left= nullptr;
        node->right= nullptr;
        node->parnt= nullptr;
    }
    
    //if the given key is bigger then current node data- go to right sub-tree
    else if(key > node->data){
        node->right = insert(node->right, key);
    }
    else{
        node->left = insert(node->left, key);
    }
    
}

Tree void::destroyTre(){
    
}
