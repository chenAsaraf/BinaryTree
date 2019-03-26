#include "Tree.hpp"
using namespace ariel;
using namespace std;
//Implementation of Node class: 


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
	return leaf;
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
    	if(search(this->getRoot(),i) == nullptr) { return false;}
	else return true;
}

//Returns the data in the root
int ariel::Tree::root(){
    return treeRoot->getData();
}

//Parent function: input- value i, returns the data allocate above this value in the Tree
int ariel::Tree::parent(int i){
//root = null
//parent of root
//if there is a parent
	if(search(this->getRoot(), i) == nullptr)
		return NULL;
	else if(i=0)
		return NULL;
	else {
		Node* n = search(this->getRoot(), i);
		return n->getParent()->getData();
	}

     return 0;//we need to implement this function.
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

//Prints the Tree
void ariel::Tree::print(){
    print(this->getRoot());
    cout << "\n";
}

void ariel::Tree::print(Node *leaf){
	if(leaf != NULL){
		print(leaf->getLeft());
		cout << leaf->getData() << " ";
		print(leaf->getRight());
	}
}
