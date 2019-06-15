#include <iostream>
#include <stdlib.h>

struct doublyLinkesListNode{
	int nodeValue;
	doublyLinkesListNode* nextNode;
	doublyLinkesListNode* previousNode;
};

int main(int argc, char** argv){
	if(argc <= 1){
		std::cout << "Invalid input" << std::endl;
	}

	doublyLinkesListNode* head = NULL;
	doublyLinkesListNode* tail = NULL;

	for(int iterator = 1; iterator < argc; iterator++){
		if(head == NULL){
			head = new doublyLinkesListNode();
			head->nodeValue = atoi(argv[iterator]);
			head->nextNode = NULL;
			head->previousNode = NULL;
			tail = head;
		}else{
			tail->nextNode = new doublyLinkesListNode();
			tail->nextNode->previousNode = tail;
			tail = tail->nextNode;
			tail->nodeValue = atoi(argv[iterator]);
			tail->nextNode = NULL;
		}
	}

	std::cout << "Head Value: " << head->nodeValue << std::endl;
	std::cout << "Tail Value: " << tail->nodeValue << std::endl;

	return 0;
}