#include <iostream>
#include <stdlib.h>

struct binarySearchTreeNode{
	int nodeValue;
	binarySearchTreeNode* leftNode;
	binarySearchTreeNode* rightNode;
};

void insertNode(binarySearchTreeNode* currentNode, binarySearchTreeNode* nodeToAdd){
	if(nodeToAdd->nodeValue < currentNode->nodeValue){
		if(currentNode->leftNode == NULL){
			currentNode->leftNode = nodeToAdd;
		}else{
			insertNode(currentNode->leftNode, nodeToAdd);
		}
	}else{
		if(currentNode->rightNode == NULL){
			currentNode->rightNode = nodeToAdd;
		}else{
			insertNode(currentNode->rightNode, nodeToAdd);
		}
	}
}

binarySearchTreeNode* findParent(binarySearchTreeNode* currentNode, int searchValue){
	if(searchValue == currentNode->nodeValue){
		return NULL;
	}

	if(searchValue < currentNode->nodeValue){
		if(currentNode->leftNode == NULL){
			return NULL;
		}else if(searchValue == currentNode->leftNode->nodeValue){
			return currentNode;
		}else{
			return findParent(currentNode->leftNode, searchValue);
		}
	}else{
		if(currentNode->rightNode == NULL){
			return NULL;
		}else if(searchValue == currentNode->rightNode->nodeValue){
			return currentNode;
		}else{
			return findParent(currentNode->rightNode, searchValue);
		}
	}
}

int main(int argc, char** argv){
	if(argc <= 1){
		std::cout << "Invalid input" << std::endl;
	}

	binarySearchTreeNode* root = NULL;
	for(int iterator = 1; iterator < (argc - 1); iterator++){
		if(root == NULL){
			root = new binarySearchTreeNode();
			root->nodeValue = atoi(argv[iterator]);
			root->leftNode = NULL;
			root->rightNode = NULL;
		}else{
			binarySearchTreeNode* nodeToAdd = new binarySearchTreeNode();
			nodeToAdd->nodeValue = atoi(argv[iterator]);
			insertNode(root, nodeToAdd);
		}
	}

	binarySearchTreeNode* parent = findParent(root, atoi(argv[argc - 1]));
	std::cout << "The value of parent is: ";
	if(parent == NULL)
		std::cout << "NULL" << std::endl;
	else
		std::cout << parent->nodeValue << std::endl;

	return 0;
}