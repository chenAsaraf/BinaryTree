#include <iostream>
#include "Tree.hpp"


using ariel::Tree, ariel::Node;

//Implementation of Node class: 

//Constructors & Destructor:

ariel::Node::Node() : Node(0, nullptr, nullptr, nullptr) {} 
ariel::Node::Node(int data) : Node(data, nullptr, nullptr, nullptr) {}
ariel::Node::Node(int data, Node* right, Node* left, Node* parent) :
        data(data), right(right), left(left), parent(parent) {}
         
ariel::Node::~Node(){
	if(left!=nullptr)
		delete left;
	if(right!=nullptr)
		delete right;
}

//Getters & Setters:
void ariel::Node::setData(int data){
            this->data = data;
        }
void ariel::Node::setRight(Node* newRight){
             this->right = newRight;
        }
void ariel::Node::setLeft(Node* newLeft){
            this->left = newLeft;
        }
void ariel::Node::setParent(Node* newParent){
	this->parent = newParent;
}
int ariel::Node::getData() const{
        return this->data;
}
Node* ariel::Node::getRight() const{
        return this->right;
}
Node* ariel::Node::getLeft() const{
        return this->left;
}
Node* ariel::Node::getParent() const{
	return this->parent;
}


//Implemantation of Binary Search Tree class:

//CONSTRUCTORS
//Empty Constructor:
ariel::Tree::Tree(){
	treeRoot = nullptr;
	treeSize = 0;
}

//Copy Constructor:
// ariel::Tree(Tree other){
// 	///NEED TO IMPLEMENT!
// }

//Destructor:
ariel::Tree::~Tree(){
	delete treeRoot;
}

//SHOULD THROW AN EXCEPTION IF TREE IS NOT CHANGE
void ariel::Tree::setSize(int i){
	treeSize = i;
}

Node* ariel::Tree::getRoot(){
	return treeRoot;
}

//Private Methods:

//This following function helps the insert function
Node* ariel::Tree::insert(Node *leaf, int i){
	if( leaf==nullptr ){
		leaf = new Node(i);
	}
	else if(i < (leaf->getData())){
		leaf->setLeft(insert(leaf->getLeft(), i));
	}
	else if(i > (leaf->getData())){
		leaf->setRight(insert(leaf->getRight(), i));
	}
	return nullptr;
}

//this following function helps the contains function-
//looks for the i value in the tree and return the node contains that
Node* ariel::Tree::search(Node* leaf, int i){
	if(leaf == nullptr)
		return nullptr;	
	else if(i < (leaf->getData()))
		return search(leaf->getLeft(), i);
	else if(i > (leaf->getData()))
		return search(leaf->getRight(), i);
	else
		return leaf;
}


//Public Methods:

//Insert function: input- number i, insert the number to it location in the Tree
void ariel::Tree::insert(int i){
	insert(this->getRoot(), i);
	treeSize++;
}

//Remove function: input- number i, remove the node holds this number in the tree
//Throw exceptions if this number does not exist
void ariel::Tree::remove(int i){
	
}

//Return the size of the Tree:
uint ariel::Tree::size(){
    return treeSize;
}

//Search function: if the tree contains the value of i- returns true.
bool ariel::Tree::contains(int i){
    // if (search(this->treeRoot, i) == nullprt)
    // 	return false;
    // else
     	return true;
}

//Returns the data in the root
int ariel::Tree::root(){
    return treeRoot->getData();
}

//Parent function: input- value i, returns the data allocate above this value in the Tree
int ariel::Tree::parent(int i){
     Node* current = search(this->getRoot(), i);
     return current->getParent()->getData();
}

//Left function: input- value i, returns the left child's data of the input
int ariel::Tree::left(int i){
    Node* current = search(this->getRoot(), i);
    return current->getLeft()->getData();
}

//Right function: input- value i, returns the right child's data of the input
int ariel::Tree::right(int i){
	Node* current = search(this->getRoot(), i);
    return current->getRight()->getData();
}

//Print the Tree
void ariel::Tree::print(){
    
}

