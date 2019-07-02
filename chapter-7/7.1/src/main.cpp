#include <iostream>
#include <stdlib.h>
#include <vector>

struct avlTreeNode{
	int nodeValue;
	avlTreeNode* leftNode;
	avlTreeNode* rightNode;
};

void insertNode(avlTreeNode* currentNode, avlTreeNode* nodeToAdd){
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

void breadthFirstTraversal(avlTreeNode* currentNode){
	std::vector<avlTreeNode*> bstQueue;
	int queueCounter = 0;
	while(currentNode != NULL){
		std::cout << currentNode->nodeValue << "->";
		if(currentNode->leftNode != NULL)
			bstQueue.push_back(currentNode->leftNode);
		if(currentNode->rightNode != NULL)
			bstQueue.push_back(currentNode->rightNode);

		if(bstQueue.size() > 0){
			currentNode = bstQueue[queueCounter];
			queueCounter++;
		}else{
			currentNode = NULL;
		}
	}
}

avlTreeNode* rotateLeft(avlTreeNode* startNode){
	avlTreeNode* rightNode = startNode->rightNode;
	startNode->rightNode = rightNode->leftNode;
	rightNode->leftNode = startNode;
	return rightNode;
}

avlTreeNode* rotateRight(avlTreeNode* startNode){
	avlTreeNode* leftNode = startNode->leftNode;
	startNode->leftNode = leftNode->rightNode;
	leftNode->rightNode = startNode;
	return leftNode;
}

int main(int argc, char** argv){
	if(argc <= 1){
		std::cout << "Invalid input" << std::endl;
	}

	avlTreeNode* root = NULL;
	for(int iterator = 1; iterator < argc; iterator++){
		if(root == NULL){
			root = new avlTreeNode();
			root->nodeValue = atoi(argv[iterator]);
			root->leftNode = NULL;
			root->rightNode = NULL;
		}else{
			avlTreeNode* nodeToAdd = new avlTreeNode();
			nodeToAdd->nodeValue = atoi(argv[iterator]);
			insertNode(root, nodeToAdd);
		}
	}

	breadthFirstTraversal(root);
	std::cout << std::endl;
	root = rotateRight(root);
	breadthFirstTraversal(root);
	std::cout << std::endl;
	root = rotateLeft(root);
	breadthFirstTraversal(root);
	std::cout << std::endl;

	return 0;
}