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

binarySearchTreeNode* findMinimum(binarySearchTreeNode* currentNode){
	if(currentNode == NULL)
		return NULL;
	else if(currentNode->leftNode == NULL)
		return currentNode;

	return findMinimum(currentNode->leftNode);
}

binarySearchTreeNode* findMaximum(binarySearchTreeNode* currentNode){
	if(currentNode == NULL)
		return NULL;
	else if(currentNode->rightNode == NULL)
		return currentNode;

	return findMaximum(currentNode->rightNode);
}

int main(int argc, char** argv){
	if(argc <= 1){
		std::cout << "Invalid input" << std::endl;
	}

	binarySearchTreeNode* root = NULL;
	for(int iterator = 1; iterator < (argc); iterator++){
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

	std::cout << "Minimum Node Value: " << findMinimum(root)->nodeValue << std::endl;
	std::cout << "Maximum Node Value: " << findMaximum(root)->nodeValue << std::endl;

	return 0;
}