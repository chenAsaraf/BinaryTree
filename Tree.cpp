#include <iostream>
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
	destroyTree(treeRoot);

}

//SHOULD THROW AN EXCEPTION IF TREE IS NOT CHANGE
void ariel::Tree::setSize(int i){
	treeSize = i;
}

Node* ariel::Tree::root1(){
	return treeRoot;
}

//Private Methods:

//This following function helps the destructor of the Tree
void ariel::Tree::destroyTree(Node* node){
	  /*  if(node == nullptr) return nullptr;
	    if(node->getLeft() != nullptr) 
			destroyTree(node->getLeft());
		if(node->getRight() != nullptr) 
			destroyTree(node->getRight());
        delete node;
        setSize(0);
        return nullptr;
		*/
	// cout <<"oops" << endl;
		if(node != NULL){
			destroyTree(node->getLeft());
			destroyTree(node->getRight());
			delete node;
		}
		//return NULL;
}

//This following function helps the insert function
Node* ariel::Tree::insert(Node* leaf, int i){
	
	if( leaf==nullptr ){
		// cout <<" root1" << endl;
		leaf = new Node(i);
		// cout << " root1.5" << endl;
		return leaf;
	}
	else if(i < (leaf->getData())){
		// cout <<" root2" << endl;
		if(leaf->getLeft()==nullptr){
			Node* n=new Node(i);
			leaf->setLeft(n);
			n->setParent(leaf);
			
		}
		else insert(leaf->getLeft(), i);
		// leaf->setLeft(insert(leaf->getLeft(), i));
		// leaf->getLeft()->setParent(leaf);
		// cout <<" root2.5" << endl;
	}
	else if(i > (leaf->getData())){
		// cout << " root3" << endl;
		if(leaf->getRight()==nullptr){
			Node* n=new Node(i);
			leaf->setRight(n);
			n->setParent(leaf);
			
		}
		else insert(leaf->getRight(), i);
		// leaf->setRight(insert(leaf->getRight(), i));
		// leaf->getRight()->setParent(leaf);
		// cout << " root3.5" << endl;
	}
	return nullptr;
}

//this following function helps the contains function-
//looks for the i value in the tree and return the node contains that
Node* ariel::Tree::search(Node* leaf, int i){
	// cout << i<<" search" << endl;
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
	// cout << i << endl;
	if (treeRoot != nullptr) insert(treeRoot, i);
	else
	{
		treeRoot= new Node(i);
	}
	
	treeSize++;
	// cout << i<<" rootend" << endl;
}

//Remove function: input- number i, remove the node holds this number in the tree
//Throw exceptions if this number does not exist
void ariel::Tree::remove(int i){
	Node* node = search(this->treeRoot, i);
	if(node != NULL){
		remove(node);
		setSize(size()+1);
	} else {
		throw "err";
	}
}

void ariel::Tree::remove(Node* node){
//easiest case is that the node is a leaf with no children.
	if(node->getRight() == NULL && node->getLeft() == NULL){
		Node* parent = node->getParent();
		if(parent == NULL) { treeRoot = NULL; }
		else if(node->getData() >= parent->getData()) { parent->setRight(NULL); }
		else parent->setLeft(NULL);
		delete node;
	}
	else if(node->getLeft() == NULL) {
		Node* parent = node->getParent();
		if(parent == NULL) {
			treeRoot = node->getRight();
			root1()->setParent(NULL);
		}
		else if(node->getData() >= parent->getData()) {
			parent->setRight(node->getRight());
			node->getRight()->setParent(parent);
		}
		else {
			parent->setLeft(node->getRight());
			node->getRight()->setParent(parent);
		}
		delete node;
	}	
	else if(node->getRight() == NULL) {
		Node* parent = node->getParent();
		if(parent == NULL) {
			treeRoot = node->getLeft();
			root1()->setParent(NULL);
		}
		else if(node->getData() >= parent->getData()) {
			parent->setRight(node->getLeft());
			node->getLeft()->setParent(parent);
		}
		else {
			parent->setLeft(node->getLeft());
			node->getLeft()->setParent(parent);
		}
		delete node;
	}	
	else {
		Node* att = node->getRight();
		while(att != NULL && att->getLeft() != NULL) {
			att = att->getLeft();
		}
		int num = att->getData();
		remove(num);
		node->setData(num);
	}
}
//Return the size of the Tree:
uint ariel::Tree::size(){
    return treeSize;
}

//Search function: if the tree contains the value of i- returns true.
bool ariel::Tree::contains(int i){
     if (search(this->treeRoot, i) == nullptr)
     	return false;
     else
     	return true;
}

//Returns the data in the root
int ariel::Tree::root(){
    return treeRoot->getData();
}

//Parent function: input- value i, returns the data allocate above this value in the Tree
int ariel::Tree::parent(int i){
     Node* current = search(treeRoot, i);
     return current->getParent()->getData();
}

//Left function: input- value i, returns the left child's data of the input
int ariel::Tree::left(int i){
    Node* current = search(this->root1(), i);
    return current->getLeft()->getData();
}

//Right function: input- value i, returns the right child's data of the input
int ariel::Tree::right(int i){
	Node* current = search(this->root1(), i);
    return current->getRight()->getData();
}

//Print the Tree
void ariel::Tree::print(){
	print(root1());
	cout << "\n";    
}

void ariel::Tree::print(Node *leaf){
	if(leaf != NULL){
		print(leaf->getLeft());
		cout << leaf->getData() << " ";
		print(leaf->getRight());
	}
}


