#include <iostream>
#include <stdlib.h>

struct singlyLinkesListNode{
	int nodeValue;
	singlyLinkesListNode* nextNode;
};

int main(int argc, char** argv){
	if(argc <= 1){
		std::cout << "Invalid input" << std::endl;
	}

	singlyLinkesListNode* head = NULL;
	singlyLinkesListNode* tail = NULL;

	for(int iterator = 1; iterator < (argc); iterator++){
		if(head == NULL){
			head = new singlyLinkesListNode();
			head->nodeValue = atoi(argv[iterator]);
			head->nextNode = NULL;
			tail = head;
		}else{
			tail->nextNode = new singlyLinkesListNode();
			tail = tail->nextNode;
			tail->nodeValue = atoi(argv[iterator]);
			tail->nextNode = NULL;
		}
	}

	std::cout << "Head Value: " << head->nodeValue << std::endl;
	std::cout << "Tail Value: " << tail->nodeValue << std::endl;

	if(tail != NULL){
		singlyLinkesListNode* currentNode = tail;
		singlyLinkesListNode* previousNode = NULL;
		while(currentNode != head){
			std::cout << currentNode->nodeValue << std::endl;
			previousNode = head;
			while(previousNode->nextNode != currentNode){
				previousNode = previousNode->nextNode;
			}
			currentNode = previousNode;
		}
		std::cout << currentNode->nodeValue << std::endl;
	}

	return 0;
}