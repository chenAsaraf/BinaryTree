#include <iostream>
#include <stdexcept>
#include "Tree.hpp"


using namespace std;
using ariel::Tree, ariel::Node;

//Implementation of Node class: 

//Constructors & Destructor:

ariel::Node::Node() : Node(0, nullptr, nullptr, nullptr) {} 
ariel::Node::Node(int data) : Node(data, nullptr, nullptr, nullptr) {}
ariel::Node::Node(int data, Node* right, Node* left, Node* parent) :
        data(data), right(right), left(left), parent(parent) {}
         
ariel::Node::~Node(){
	if(left!=nullptr){
		delete left;
		left = nullptr;
}
	if(right!=nullptr){
		delete right;
		right = nullptr;
}

}


//Getters & Setters:
void ariel::Node::setData(int data){
	this->data= data;
}
void ariel::Node::setRight(Node* newRight){
	this->right= newRight;
}
void ariel::Node::setLeft(Node* newLeft){
	this->left= newLeft;
}
void ariel::Node::setParent(Node* newParent){
	this->parent= newParent;
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

//Empty Constructor:
ariel::Tree::Tree(){
treeRoot= nullptr;
treeSize= 0;
}

//Destructor:
ariel::Tree::~Tree(){
	if(treeRoot!=nullptr)
	delete treeRoot;
	treeSize = 0;
}

//SHOULD THROW AN EXCEPTION IF TREE IS NOT CHANGE


//Private Methods:




//this following function helps the contains function-
//looks for the i value in the tree and return the node contains that
Node* ariel::Tree::search(Node* leaf, int i){
	if(leaf==nullptr){
		cout << "search result: didn't find number: " << i << endl;
		return nullptr;	
	}
	else if(i<(leaf->getData()))
		return search(leaf->getLeft(), i);
	else if(i>(leaf->getData()))
		return search(leaf->getRight(), i);
	else
		return leaf;
}

Node* ariel::Tree::minValue(Node* subtree){
	if(subtree->getLeft()==nullptr){
		return subtree;
	}
	else return minValue(subtree->getLeft());
}

//Public Methods:

Node* ariel::Tree::insert(Node* node, int i){
	if(node != nullptr){
		if(i < node->getData()) {
			if(node->getLeft() == nullptr){
				Node* newLeft = new Node(i, nullptr, nullptr, node);
				node->setLeft(newLeft);
				treeSize++;
				return newLeft;
			}
			else insert(node->getLeft(), i);
		}
		else{
			if(node->getRight() == nullptr){
				Node* newRight = new Node(i, nullptr, nullptr, node);
				node->setRight(newRight);
				treeSize++;
				return newRight;
			}
			else insert(node->getRight(), i);
		}
	} 
	else return nullptr;
}
//Insert function: input- number i, insert the number to it location in the Tree
void ariel::Tree::insert(int i){
		if(treeRoot == nullptr){
			treeRoot = new Node(i);
			treeSize++;
		}
		else if (contains(i)){
			throw std::invalid_argument("This number aleady exist");
		}
		else{
			insert(treeRoot, i);
		}
}



//Remove function: input- number i, remove the node holds this number in the tree
//Throw exceptions if this number does not exist
void ariel::Tree::remove(int i){
	Node* toBeRemoved = search(treeRoot, i);
	
	//case 1: node to be deleted is leaf:
	if((toBeRemoved->getLeft()==nullptr) && (toBeRemoved->getRight()==nullptr)){
		//if this is the root
		if(toBeRemoved->getParent()==nullptr){
			delete toBeRemoved;
			treeSize--;
			return;
		}
		//if it is the left child
		else if(toBeRemoved->getData() < toBeRemoved->getParent()->getData()){
			toBeRemoved->getParent()->setLeft(nullptr);
			delete toBeRemoved;
			treeSize--;
			return;
		}
		//if it is the right child
		else{
			toBeRemoved->getParent()->setRight(nullptr);
			delete toBeRemoved;
			treeSize--;
			return;
		}
	}	//end case 1
	
	//case 2: node to be deleted has only right child:
	else if((toBeRemoved->getLeft()==nullptr) && (toBeRemoved->getRight()!=nullptr)){
		//if this is the root
		if(toBeRemoved->getParent()==nullptr){
			treeRoot = toBeRemoved->getRight();
			delete toBeRemoved;
			treeSize--;
			return;
		}
		//if it is the left child
		else if(toBeRemoved->getData() < toBeRemoved->getParent()->getData()){
			toBeRemoved->getParent()->setLeft(toBeRemoved->getRight());
			delete toBeRemoved;
			treeSize--;
			return;
		}
		//if it is the right child
		else if(toBeRemoved->getData() > toBeRemoved->getParent()->getData()){
			toBeRemoved->getParent()->setRight(toBeRemoved->getRight());
			delete toBeRemoved;
			treeSize--;
			return;
		}
	}//end case 2
	
	//case 3: node to be deleted has only left child:
	else if((toBeRemoved->getLeft()!=nullptr) && (toBeRemoved->getRight()==nullptr)){
		//if this is the root
		if(toBeRemoved->getParent()==nullptr){
			treeRoot = toBeRemoved->getLeft();
			delete toBeRemoved;
			treeSize--;
			return;
		}	
		//if it is the left child
		else if(toBeRemoved->getData() < toBeRemoved->getParent()->getData()){
			toBeRemoved->getParent()->setLeft(toBeRemoved->getLeft());
			delete toBeRemoved;
			treeSize--;
			return;
		}
		//if it is the right child
		else if(toBeRemoved->getData() > toBeRemoved->getParent()->getData()){
			toBeRemoved->getParent()->setRight(toBeRemoved->getLeft());
			delete toBeRemoved;
			treeSize--;
			return;
		}
	}//end case 3
	
	//case 4: node to be deleted has two children:
	//get the inorder successor (smallest in the right subtree) 
	else{
		Node* temp = minValue(toBeRemoved->getRight());
		int valueToRemove = toBeRemoved->getData();
		toBeRemoved->setData(temp->getData());
		remove(valueToRemove);
	}//end 4 case
	
}//end remove

//Return the size of the Tree:
uint ariel::Tree::size(){
    return treeSize;
}

//Search function: if the tree contains the value of i- returns true.
bool ariel::Tree::contains(int i){
	if (search(treeRoot, i)== nullptr) return false;
	else return true;
}

//Returns the data in the root
int ariel::Tree::root(){
    return treeRoot->getData();
}

//Parent function: input- value i, returns the data allocate above this value in the Tree
int ariel::Tree::parent(int i){
// Node* current= search(this->root, i);
    // return current->parent->data;
return 0;
}

//Left function: input- value i, returns the left child's data of the input
int ariel::Tree::left(int i){
	Node* current= search(treeRoot, i);
    return current->getLeft()->getData();
}

//Right function: input- value i, returns the right child's data of the input
int ariel::Tree::right(int i){
	Node* current= search(treeRoot, i);
    return current->getRight()->getData();
}

void ariel::Tree::print(Node* node){
	if(node==nullptr) return;
	else {
		print(node->getLeft());
		cout << " [ " << node->getData() << " ]";
		print(node->getRight());
	}
}

//Print the Tree
void ariel::Tree::print(){
	if(treeRoot ==nullptr) cout << "the tree is empty darling" << endl;
	else{
		print(treeRoot);   
		cout << "" <<endl;
	}
}



