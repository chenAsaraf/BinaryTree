#include "Tree.hpp"


//implementation of Node class: 
class Node{
    private: 
        int data;
        Node* right; //pointer?
        Node* left; //pointer?
        Node* parent;
public:
Node::Node(){
	parent=NULL;
	left=NULL;
	right=NULL;
	data=NULL;
}
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
};

////////////////////////////////////

//Implemantation of Binary Tree:
class Tree{
	
ariel::Tree::Tree(){
	sizeOf=0;
	rootOf=NULL;
}
//Pribvate methods
//the distructor:
Tree void::destroyTree(){
    destroyTreeHelp(root->left);
	destroyTreeHelp(root->right);
	delete root;
	sizeOf=0;
}

//the following function is supposed to delete the leafs that come after the leaf we recieve, including the one we recieve itself
void btree::destroyTreeHelp(Node *leaf){
	if(leaf != NULL){
		destroyTreeHelp(leaf->left);
		destroyTreeHelp(leaf->right);
		delete leaf;
	}
}

//the following function helps the insert function:
void Tree::insert(int i, Node *leaf){

	if(i < leaf->data){
		if(leaf->left != NULL){
			insert(i, leaf->left);
		}else{
			leaf->left = new Node;
			leaf->left->data = i;
			leaf->left->left = NULL;
			leaf->left->right = NULL;
		}
	}else if(i >= leaf->data){
		if(leaf->right != NULL){
			insert(i, leaf->right);
		}else{
			leaf->right = new Node;
			leaf->right->data = key;
			leaf->right->right = NULL;
			leaf->right->left = NULL;
		}
	}

}
//the insert function:
void Tree::insert(int i){
	if(rootOf != NULL){
		insert(i, rootOf);
	}else{
		rootOf = new Node;
		rootOf->data = i;
		rootOf->left = NULL;
		rootOf->right = NULL;
	}
	sizeOf=sizeOf+1;
}
//we need to complete that function:
void Tree::remove(int i){
    
}
//return the size of the tree:
int Tree::size(){
    return sizeOf;
}
//if the tree contains the value of i- returns true, else-false
bool Tree::contains(int i){
    return search(i, rootOf)
}
//the following function looks for the i in the tree
bool Tree::search(int i, node *leaf){
	if(leaf != NULL){
		if(i == leaf->data){
			return true;
		}
		if(i < leaf->data){
			return search(i, leaf->left);
		}else{
			return search(i, leaf->right);
		}
	}else{
		return false;
	}
}

//returns the data in the root
int Tree::root(){
    return rootOf->data;
}

//returns the parent's data of the input
//we need to complete it
int Tree::parent(int i){
    node *prev=rootOf;
    node *current=rootOf;
    
}

//returns the left child's data of the input
int Tree::left(int i){
    return ((search(i, rootOf))-> left->data);
}
//the following function is supposed to help the left and the right functions
node *btree::search(int i, node *leaf){
	if(leaf != NULL){
		if(i == leaf->data){
			return leaf;
		}
		if(i < leaf->data){
			return search(i, leaf->left);
		}else{
			return search(i, leaf->right);
		}
	}else{
		return NULL;
	}
}
//returns the right child's data of the input
int Tree::right(int i){
    return ((search(i, rootOf))-> right->data);
}
//prints the tree- we need to write it
void Tree::print(){
    
}
