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
			root = insertNode(root, nodeToAdd);
			std::cout << "Height of first element: " << getHeight(root) << std::endl;
			breadthFirstTraversal(root);
			std::cout << std::endl;
		}
	}

	return 0;
}