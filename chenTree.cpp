#include "Tree.hpp"
using namespace ariel;
using namespace std;
//Implementation of Node class: 


//Print Node

string ariel::Node::toString() const{
    // string node = "[ " + this->data + " ]"; //like that?
    // return node;
    return "";
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
	destroyTree(treeRoot);
}

//SHOULD THROW AN EXCEPTION IF TREE IS NOT CHANGE
void ariel::Tree::setSize(int i){
	treeSize = i;
}

//Private Methods:

//This following function helps the destructor of the Tree
Node* ariel::Tree::destroyTree(Node* node){
	    if(node == nullptr) return nullptr;
        destroyTree(node->getLeft());
        destroyTree(node->getRight());
        delete node;
        setSize(0);
        return nullptr;
    }

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
    // Node* current = search(this->root, i);
    // return current->parent->data;
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
