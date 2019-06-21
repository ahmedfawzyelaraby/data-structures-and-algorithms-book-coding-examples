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

bool removeNode(binarySearchTreeNode* root, int removeValue){
	binarySearchTreeNode* removeNode = findNode(root, removeValue);
	if(removeNode == NULL)
		return false;

	binarySearchTreeNode* removeNodeParent = findParent(root, removeValue);
	if((removeNode->leftNode == NULL) && (removeNode->rightNode == NULL)){
		if(removeNodeParent == NULL){
			root = NULL;
			removeNode = NULL;
		}else if(removeNode->nodeValue < removeNodeParent->nodeValue){
			removeNodeParent->leftNode = NULL;
			removeNode = NULL;
		}else{
			removeNodeParent->rightNode = NULL;
			removeNode = NULL;
		}
	}else if((removeNode->leftNode != NULL) && (removeNode->rightNode == NULL)){
		if(removeNodeParent == NULL){
			root = removeNode->leftNode;
			removeNode = NULL;
		}else if(removeNode->nodeValue < removeNodeParent->nodeValue){
			removeNodeParent->leftNode = removeNode->leftNode;
			removeNode = NULL;
		}else{
			removeNodeParent->rightNode = removeNode->leftNode;
			removeNode = NULL;
		}
	}else if((removeNode->leftNode == NULL) && (removeNode->rightNode != NULL)){
		if(removeNodeParent == NULL){
			root = removeNode->rightNode;
			removeNode = NULL;
		}else if(removeNode->nodeValue < removeNodeParent->nodeValue){
			removeNodeParent->leftNode = removeNode->rightNode;
			removeNode = NULL;
		}else{
			removeNodeParent->rightNode = removeNode->rightNode;
			removeNode = NULL;
		}
	}else{
		binarySearchTreeNode* largestValueNodeAfterRemoval = removeNode->leftNode;
		while(largestValueNodeAfterRemoval->rightNode != NULL)
			largestValueNodeAfterRemoval = largestValueNodeAfterRemoval->rightNode;
		findParent(root, largestValueNodeAfterRemoval->nodeValue)->rightNode = NULL;
		removeNode->nodeValue = largestValueNodeAfterRemoval->nodeValue;
		largestValueNodeAfterRemoval = NULL;
	}
	return true;
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

	std::cout << "Element is found and removed status: " << removeNode(root, atoi(argv[argc - 1])) << std::endl;

	return 0;
}