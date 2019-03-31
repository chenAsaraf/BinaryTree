#include <iostream>
#include <stdexcept>
#include "Tree.hpp"


using namespace std;
using ariel::Tree, ariel::Node;

/**Implementation of Node class:**/

//Constructors & Destructor:

ariel::Node::Node() : Node(0, nullptr, nullptr, nullptr) {} 
ariel::Node::Node(int data) : Node(data, nullptr, nullptr, nullptr) {}
ariel::Node::Node(int data, Node* right, Node* left, Node* parent) :
        data(data), right(right), left(left), parent(parent) {}


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

/**Implemantation of Binary Search Tree class:**/

//Empty Constructor:
ariel::Tree::Tree(){
	treeRoot= nullptr;
	treeSize= 0;
}

//Destructor:
ariel::Tree::~Tree(){
	if(treeRoot!=nullptr)
		DestroyTree(treeRoot);
	treeSize = 0;
}

//Private Methods:

void ariel::Tree::DestroyTree(Node* node){
	if(node->getLeft()!=nullptr){
		DestroyTree(node->getLeft());
	}
	if(node->getRight()!=nullptr){
		DestroyTree(node->getRight());
	}
	delete node;
	node = nullptr;
}



//This following function helps the contains function-
//looks for the i value in the tree and return the node contains that
Node* ariel::Tree::search(Node* leaf, int i){
	if(leaf==nullptr){ //if the tree is empty or we got to a leaf - the number do not exist
		return nullptr;	
	}
	else if(i<(leaf->getData()))
		return search(leaf->getLeft(), i);
	else if(i>(leaf->getData()))
		return search(leaf->getRight(), i);
	else
		return leaf;
}

//This funcion helps to the Insert method-
//find the minimum value in the subtree starting from node
Node* ariel::Tree::minValue(Node* subtree){
	if(subtree==nullptr){
		return nullptr;
	}
	if(subtree->getLeft() == nullptr) {
		return subtree;
	}
	return minValue(subtree->getLeft());
}

//This function helps to the Insert methods.
Node* ariel::Tree::insert(Node* node, int i){
	if(node != nullptr){
		if(i < node->getData()) {
			if(node->getLeft() == nullptr){
				Node* newLeft = new Node(i, nullptr, nullptr, node);
				node->setLeft(newLeft);
				newLeft->setParent(node);
				treeSize++;
				return newLeft;
			}
			else return insert(node->getLeft(), i);
		}
		else{
			if(node->getRight() == nullptr){
				Node* newRight = new Node(i, nullptr, nullptr, node);
				node->setRight(newRight);
				newRight->setParent(node);
				treeSize++;
				return newRight;
			}
			else return insert(node->getRight(), i);
		}
	} 
	else return nullptr;
}

//Public Methods:

//Insert function: input- number i, insert the number to it location in the Tree
void ariel::Tree::insert(int i){
	if(treeRoot == nullptr){
		treeRoot = new Node(i);
		treeSize++;
		treeRoot->setParent(nullptr);
	}
	else if (contains(i)){
		throw std::invalid_argument("This number already exist, dude");
	}
	else{
		insert(treeRoot, i);
	}
}



//Remove function: input- number i, remove the node holds this number in the tree
//Throw exceptions if this number does not exist
void ariel::Tree::remove(int i){
	if(contains(i) == false) {
		throw std::invalid_argument("This value to remove doesn't exist in the tree, honey");
	}
	
	else {
		Node* toBeRemoved = search(treeRoot, i);
		Node* nodeParent = toBeRemoved->getParent();
		Node* leftChild = toBeRemoved->getLeft();
		Node* rightChild = toBeRemoved->getRight();
		
		//CASE 1: node to be deleted is leaf:
		if(leftChild==nullptr && rightChild==nullptr){
			 
			//if this is the root
			if(nodeParent==nullptr){
				treeRoot = nullptr;
			}
			//if it is the left child
			else if(toBeRemoved->getData() < nodeParent->getData()){
				nodeParent->setLeft(nullptr);
			}
			//if it is the right child
			else{
				nodeParent->setRight(nullptr);
			}
			
			delete toBeRemoved;
			treeSize--;
			return;
			
		}	//end case 1
	
		//CASE 2: node to be deleted has only right child:
		else if((leftChild==nullptr) && (rightChild!=nullptr)){
			
			//if this is the root
			if(nodeParent==nullptr){
				treeRoot = rightChild;
				treeRoot->setParent(nullptr);
			}
			//if it is the left child
			else if(toBeRemoved->getData() < nodeParent->getData()){
				nodeParent->setLeft(rightChild);
				rightChild->setParent(nodeParent);
			}
			//if it is the right child
			else if(toBeRemoved->getData() > nodeParent->getData()){
				nodeParent->setRight(rightChild);
				rightChild->setParent(nodeParent);
			}
			
			delete toBeRemoved;
			treeSize--;
			return;
			
		}//end case 2
	
		//CASE 3: node to be deleted has only left child:
		else if((leftChild!=nullptr) && (rightChild==nullptr)){
			
			//if this is the root
			if(nodeParent==nullptr){
				treeRoot = leftChild;
				treeRoot->setParent(nullptr);
			}	
			//if it is the left child
			else if(toBeRemoved->getData() < nodeParent->getData()){
				nodeParent->setLeft(leftChild);
				leftChild->setParent(nodeParent);
			}
			//if it is the right child
			else if(toBeRemoved->getData() >= nodeParent->getData()){
				nodeParent->setRight(leftChild);
				leftChild->setParent(nodeParent);
			}
			
			delete toBeRemoved;
			treeSize--;
			return; 
				
		}//end case 3
	
		//CASE 4: node to be deleted has two children:
		//get the inorder successor (smallest in the right subtree) 
		else{
			
			Node* temp = minValue(rightChild);
			int valueToRemove = temp->getData();
			remove(valueToRemove);
			toBeRemoved->setData(valueToRemove);
			
		}//end 4 case
	}//end else

}//end remove

//Return the size of the Tree:
int ariel::Tree::size(){
    return treeSize;
}

//Contains function: if the tree contains the value of i- returns true.
//including the case the root itself is NULL
bool ariel::Tree::contains(int i){
	if (search(treeRoot, i)== nullptr) return false; 
	else return true;
}

//Returns the data in the root
int ariel::Tree::root(){
	if(treeRoot == nullptr) throw std::invalid_argument("error, the root is empty darling");
	return treeRoot->getData();
}

//Parent function: input- value i, returns the data allocate above this value in the Tree
int ariel::Tree::parent(int i){
	if(search(treeRoot, i) == nullptr) throw std::invalid_argument("error, the value doesn't exist, honey");
	else if(search(treeRoot, i)->getParent() == nullptr) throw std::invalid_argument("error, this is the root");
	return search(treeRoot, i)->getParent()->getData();
}

//Left function: input- value i, returns the left child's data of the input
int ariel::Tree::left(int i){
	Node* current= search(treeRoot, i);
	if(current == nullptr) throw std::invalid_argument("error, no value like that in the tree");
	else if(current->getLeft() == nullptr) throw std::invalid_argument("error,no exist left child");
	return current->getLeft()->getData();
}

//Right function: input- value i, returns the right child's data of the input
int ariel::Tree::right(int i){
	Node* current= search(treeRoot, i);
	if(current == nullptr) throw std::invalid_argument("error, no value like that in the tree");
	else if(current->getRight() == nullptr) throw std::invalid_argument("error, no exist right child");
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
	}
}




