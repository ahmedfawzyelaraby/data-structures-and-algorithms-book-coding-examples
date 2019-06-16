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

int main(int argc, char** argv){
	if(argc <= 1){
		std::cout << "Invalid input" << std::endl;
	}

	binarySearchTreeNode* root = NULL;
	for(int iterator = 1; iterator < argc; iterator++){
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

	return 0;
}