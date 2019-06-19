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

binarySearchTreeNode* findNode(binarySearchTreeNode* currentNode, int searchValue){
	if(currentNode == NULL){
		return NULL;
	}

	if(currentNode->nodeValue == searchValue){
		return currentNode;
	}else if(currentNode->nodeValue > searchValue){
		return findNode(currentNode->leftNode, searchValue);
	}else{
		return findNode(currentNode->rightNode, searchValue);
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

	binarySearchTreeNode* node = findNode(root, atoi(argv[argc - 1]));
	std::cout << "The value of node is: ";
	if(node == NULL)
		std::cout << "NULL" << std::endl;
	else
		std::cout << node->nodeValue << std::endl;

	return 0;
}