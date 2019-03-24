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
Tree void::destroyTree(Node* node){
    
}
