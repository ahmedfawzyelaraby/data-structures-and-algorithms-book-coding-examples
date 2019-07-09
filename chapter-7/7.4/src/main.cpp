#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>

struct avlTreeNode{
	int nodeValue;
	avlTreeNode* leftNode;
	avlTreeNode* rightNode;
};

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

int getHeight(avlTreeNode* currentNode){
	if((currentNode->leftNode == NULL) && (currentNode->rightNode == NULL)){
		return -1;
	}else if(currentNode->leftNode == NULL){
		return (getHeight(currentNode->rightNode) + 1);
	}else if(currentNode->rightNode == NULL){
		return (getHeight(currentNode->leftNode) + 1);
	}else{
		return (std::max(getHeight(currentNode->leftNode), getHeight(currentNode->rightNode)) + 1);
	}
}

void breadthFirstTraversal(avlTreeNode* currentNode){
	std::vector<avlTreeNode*> bstQueue;
	int queueCounter = 0;
	while(currentNode != NULL){
		std::cout << currentNode->nodeValue << "->";
		if(currentNode->leftNode != NULL){
			bstQueue.push_back(currentNode->leftNode);
		}
		if(currentNode->rightNode != NULL){
			bstQueue.push_back(currentNode->rightNode);
		}
		if(queueCounter < bstQueue.size()){
			currentNode = bstQueue[queueCounter];
			queueCounter++;

		}else{
			currentNode = NULL;
		}
	}
}

avlTreeNode* checkBalance(avlTreeNode* startNode){
	if(getHeight(startNode) == -1){
		return startNode;
	}else{
		if(startNode->leftNode == NULL){
			if((-2 - getHeight(startNode->rightNode)) < -1){
				if(startNode->rightNode->leftNode == NULL){
					return rotateLeft(startNode);
				}else if(startNode->rightNode->rightNode == NULL){
					return rotateLeft(rotateRight(startNode));
				}else if((getHeight(startNode->rightNode->leftNode) - getHeight(startNode->rightNode->rightNode)) < 0){
					return rotateLeft(startNode);
				}else{
					return rotateLeft(rotateRight(startNode));
				}
			}else{
				return startNode;
			}
		}else if(startNode->rightNode == NULL){
			if((getHeight(startNode->leftNode) - -2) > 1){
				if(startNode->leftNode->leftNode == NULL){
					return rotateRight(rotateLeft(startNode));
				}else if(startNode->leftNode->rightNode == NULL){
					return rotateRight(startNode);
				}else if((getHeight(startNode->leftNode->leftNode) - getHeight(startNode->leftNode->rightNode)) > 0){
					return rotateRight(startNode);
				}else{
					return rotateRight(rotateLeft(startNode));
				}
			}else{
				return startNode;
			}
		}else if((getHeight(startNode->leftNode) - getHeight(startNode->rightNode)) > 1){
			if(startNode->leftNode->leftNode == NULL){
				return rotateRight(rotateLeft(startNode));
			}else if(startNode->leftNode->rightNode == NULL){
				return rotateRight(startNode);
			}else if((getHeight(startNode->leftNode->leftNode) - getHeight(startNode->leftNode->rightNode)) > 0){
				return rotateRight(startNode);
			}else{
				return rotateRight(rotateLeft(startNode));
			}
		}else if((getHeight(startNode->leftNode) - getHeight(startNode->rightNode)) < -1){
			if(startNode->rightNode->leftNode == NULL){
				return rotateLeft(startNode);
			}else if(startNode->rightNode->rightNode == NULL){
				return rotateLeft(rotateRight(startNode));
			}else if((getHeight(startNode->rightNode->leftNode) - getHeight(startNode->rightNode->rightNode)) < 0){
				return rotateLeft(startNode);
			}else{
				return rotateLeft(rotateRight(startNode));
			}
		}else{
			return startNode;
		}
	}
}

avlTreeNode* insertNode(avlTreeNode* currentNode, avlTreeNode* nodeToAdd){
	if(nodeToAdd->nodeValue < currentNode->nodeValue){
		if(currentNode->leftNode == NULL){
			currentNode->leftNode = nodeToAdd;
		}else{
			currentNode->leftNode = insertNode(currentNode->leftNode, nodeToAdd);
		}
	}else{
		if(currentNode->rightNode == NULL){
			currentNode->rightNode = nodeToAdd;
		}else{
			currentNode->rightNode = insertNode(currentNode->rightNode, nodeToAdd);
		}
	}

	return checkBalance(currentNode);
}

avlTreeNode* findParent(avlTreeNode* currentNode, int searchValue){
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

std::vector<avlTreeNode*> findNode(avlTreeNode* currentNode, int searchValue){
	std::vector<avlTreeNode*> backtrace;
	if(currentNode == NULL){
		return backtrace;
	}

	avlTreeNode* nodeToRemove = currentNode;
	while((nodeToRemove != NULL) && (nodeToRemove->nodeValue != searchValue)){
		backtrace.push_back(nodeToRemove);
		if(searchValue < nodeToRemove->nodeValue)
			nodeToRemove = nodeToRemove->leftNode;
		else
			nodeToRemove = nodeToRemove->rightNode;
	}
	if(nodeToRemove == NULL)
		backtrace.clear();
	else
		backtrace.push_back(nodeToRemove);

	return backtrace;
}

bool removeNode(avlTreeNode* root, int removeValue){
	std::vector<avlTreeNode*> removeNodePath = findNode(root, removeValue);
	if(removeNodePath.size() == 0)
		return false;
	avlTreeNode* removeNode = removeNodePath.back();
	removeNodePath.pop_back();

	avlTreeNode* removeNodeParent = findParent(root, removeValue);
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
		avlTreeNode* largestValueNodeAfterRemoval = removeNode->leftNode;
		while(largestValueNodeAfterRemoval->rightNode != NULL)
			largestValueNodeAfterRemoval = largestValueNodeAfterRemoval->rightNode;
		avlTreeNode* largestValueNodeAfterRemovalParent = findParent(root, largestValueNodeAfterRemoval->nodeValue);

		if(largestValueNodeAfterRemovalParent == removeNode){
			largestValueNodeAfterRemovalParent->leftNode = NULL;
		}else
			largestValueNodeAfterRemovalParent->rightNode = NULL;
		removeNode->nodeValue = largestValueNodeAfterRemoval->nodeValue;
		largestValueNodeAfterRemoval = NULL;
	}

	while(removeNodePath.size() > 0){
		avlTreeNode* currentNode = removeNodePath.back();
		removeNodePath.pop_back();
		currentNode = checkBalance(currentNode);
	}
	return true;
}

int main(int argc, char** argv){
	if(argc <= 1){
		std::cout << "Invalid input" << std::endl;
	}

	avlTreeNode* root = NULL;
	for(int iterator = 1; iterator < (argc - 1); iterator++){
		if(root == NULL){
			root = new avlTreeNode();
			root->nodeValue = atoi(argv[iterator]);
			root->leftNode = NULL;
			root->rightNode = NULL;
		}else{
			avlTreeNode* nodeToAdd = new avlTreeNode();
			nodeToAdd->nodeValue = atoi(argv[iterator]);
			root = insertNode(root, nodeToAdd);
		}
	}

	breadthFirstTraversal(root);
	std::cout << std::endl;
	std::cout << "Delete element status: " << removeNode(root, atoi(argv[argc - 1])) << std::endl;
	breadthFirstTraversal(root);
	std::cout << std::endl;

	return 0;
}