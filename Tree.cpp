#include "Tree.hpp"


//Implemantation of Binary Tree:

	
Tree::Tree(){
	sizeOf=0;
	rootOf=NULL;
}
	
	
//Pribvate methods
//the distructor:
~Tree{
    destroyTreeHelp(root->left);
	destroyTreeHelp(root->right);
	delete root;
	sizeOf=0;
}

//the following function is supposed to delete the leafs that come after the leaf we recieve, including the one we recieve itself
void Tree::destroyTreeHelp(Node *leaf){
	if(leaf != NULL){
		destroyTreeHelp(leaf->left);
		destroyTreeHelp(leaf->right);
		delete leaf;
	}
}

//the following function helps the insert function:
void Tree::insertNode(int i, Node *leaf){

	if(i < leaf->data){
		if(leaf->left != NULL){
			insertNode(i, leaf->left);
		}else{
			leaf->left = new Node;
			leaf->left->data = i;
			leaf->left->left = NULL;
			leaf->left->right = NULL;
		}
	}else if(i >= leaf->data){
		if(leaf->right != NULL){
			insertNode(i, leaf->right);
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
		insertNode(i, rootOf);
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
    return search(i, rootOf);
}
//the following function looks for the i in the tree
bool Tree::search(int i, Node *leaf){
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
    Node *prev=rootOf;
    Node *current=rootOf;
    
}


//the following function is supposed to help the left and the right functions
Node Tree::search(int i, Node *leaf){
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
	
//returns the left child's data of the input
int Tree::left(int i){
    return ((search(i, rootOf))-> left->data);
}
//returns the right child's data of the input
int Tree::right(int i){
    return ((search(i, rootOf))-> right->data);
}
//prints the tree- we need to write it
void Tree::print(){
    
}
