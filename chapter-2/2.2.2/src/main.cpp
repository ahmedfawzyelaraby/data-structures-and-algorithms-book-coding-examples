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

	for(int iterator = 1; iterator < (argc - 1); iterator++){
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

	doublyLinkesListNode* currentNode = head;
	if(currentNode == NULL){
		// case #1
		std::cout << "The list is empty" << std::endl;
	}else{
		while(currentNode != NULL){
			if(currentNode->nodeValue == atoi(argv[argc - 1])){
				if(head == tail){
					// case #2
					head = NULL;
					tail = NULL;
					std::cout << "The only element in the list is removed" << std::endl;
					break;
				}else if(currentNode == head){
					// case #3
					head = head->nextNode;
					head->previousNode = NULL;
					std::cout << "The head element in the list is removed" << std::endl;
					break;
				}else if(currentNode == tail){
					// case #4
					tail = tail->previousNode;
					tail->nextNode = NULL;
					std::cout << "The tail element in the list is removed" << std::endl;
					break;
				}else{
					currentNode->previousNode->nextNode = currentNode->nextNode;
					currentNode->nextNode->previousNode = currentNode->previousNode;
					std::cout << "A middle element in the list is removed" << std::endl;
					break;
				}
			}
			currentNode = currentNode->nextNode;
		}

		if(currentNode == NULL){
			std::cout << "The element was not in the list" << std::endl;
		}
	}

	return 0;
}