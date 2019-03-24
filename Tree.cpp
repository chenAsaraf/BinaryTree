#include "Tree.hpp"


//implementation of Node class: 
class Node{
    private: 
        int data;
        Node* right; //pointer?
        Node* left; //pointer?
        Node* parent;
public:

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
//Pribvate methods
//the distructor:
Tree void::destroyTree(){
    destroyTreeHelp(root->left);
	destroyTreeHelp(root->right);
	delete root;
	size=0;
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
	if(root != NULL){
		insert(i, root);
	}else{
		root = new Node;
		root->data = i;
		root->left = NULL;
		root->right = NULL;
	}
	size=size+1;
}
//we need to complete that function:
void Tree::remove(int i){
    
}
//return the size of the tree:
int Tree::size(){
    return size;
}
//if the tree contains the value of i- returns true, else-false
bool Tree::contains(int i){
    return search(i, root)
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
    return root->data;
}

//returns the parent's data of the input
//we need to complete it
int Tree::parent(int i){
    node *prev=root;
    node *current=root;
    
}

//returns the left child's data of the input
int Tree::left(int i){
    return ((search(i, root))-> left->data);
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
    return ((search(i, root))-> right->data);
}
//prints the tree- we need to write it
void Tree::print(){
    
}

};
