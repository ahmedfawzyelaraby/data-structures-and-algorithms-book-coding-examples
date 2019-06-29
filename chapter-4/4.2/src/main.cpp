#include <iostream>
#include <stdlib.h>
#include <vector>

std::vector<int> minHeapify(std::vector<int> inputHeap){
	int heapIterator = inputHeap.size() - 1;
	while((heapIterator >= 0) && (((heapIterator - 1) / 2) >= 0) && (inputHeap[heapIterator] < inputHeap[(heapIterator - 1) / 2])){
		int tmpValue = inputHeap[heapIterator];
		inputHeap[heapIterator] = inputHeap[(heapIterator - 1) / 2];
		inputHeap[(heapIterator - 1) / 2] = tmpValue;
		heapIterator = (heapIterator - 1) / 2;
	}
	return inputHeap;
}

int findIndex(std::vector<int> inputHeap, int startIndex, int searchValue){
	if(searchValue == inputHeap[startIndex])
		return startIndex;
	else if(searchValue < inputHeap[startIndex])
		return -1;
	else{
		int leftChildIndex = (2 * startIndex) + 1;
		int rightChildIndex = (2 * startIndex) + 2;
		if(leftChildIndex < inputHeap.size()){
			int leftChildResult = findIndex(inputHeap, leftChildIndex, searchValue);
			if(leftChildResult >= 0)
				return leftChildResult;
		}
		if(rightChildIndex < inputHeap.size()){
			return findIndex(inputHeap, rightChildIndex, searchValue);
		}
		return -1;
	}
}

std::vector<int> removeElement(std::vector<int> inputHeap, int removeValue){
	// Step #1
	int removeIndex = findIndex(inputHeap, 0, removeValue);
	if(removeValue < 0)
		return inputHeap;

	// Step #2
	inputHeap[removeIndex] = inputHeap.back();
	inputHeap.pop_back();

	// Step #3
	int heapIterator = removeIndex;
	int leftChildIndex = (2 * removeIndex) + 1;
	int rightChildIndex = (2 * removeIndex) + 2;
	while(((leftChildIndex < inputHeap.size()) && (inputHeap[removeIndex] > inputHeap[leftChildIndex])) || ((rightChildIndex < inputHeap.size()) && (inputHeap[removeIndex] > inputHeap[rightChildIndex]))){
		if(rightChildIndex > inputHeap.size()){
			int tmpValue = inputHeap[removeIndex];
			inputHeap[removeIndex] = inputHeap[leftChildIndex];
			inputHeap[leftChildIndex] = tmpValue;
			removeIndex = leftChildIndex;
		}else{
			if(inputHeap[leftChildIndex] < inputHeap[rightChildIndex]){
				int tmpValue = inputHeap[removeIndex];
				inputHeap[removeIndex] = inputHeap[leftChildIndex];
				inputHeap[leftChildIndex] = tmpValue;
				removeIndex = leftChildIndex;
			}else{
				int tmpValue = inputHeap[removeIndex];
				inputHeap[removeIndex] = inputHeap[rightChildIndex];
				inputHeap[rightChildIndex] = tmpValue;
				removeIndex = rightChildIndex;
			}
		}
		leftChildIndex = (2 * removeIndex) + 1;
		rightChildIndex = (2 * removeIndex) + 2;
	}

	while((heapIterator >= 0) && (((heapIterator - 1) / 2) >= 0) && (inputHeap[heapIterator] < inputHeap[(heapIterator - 1) / 2])){
		int tmpValue = inputHeap[heapIterator];
		inputHeap[heapIterator] = inputHeap[(heapIterator - 1) / 2];
		inputHeap[(heapIterator - 1) / 2] = tmpValue;
		heapIterator = (heapIterator - 1) / 2;
	}

	return inputHeap;
}

int main(int argc, char** argv){
	if(argc <= 1){
		std::cout << "Invalid input" << std::endl;
	}

	std::vector<int> heapTreeArray;
	for(int iterator = 1; iterator < (argc - 1); iterator++){
		heapTreeArray.push_back(atoi(argv[iterator]));
		heapTreeArray = minHeapify(heapTreeArray);
	}

	for(int iterator = 0; iterator < heapTreeArray.size(); iterator++){
		std::cout << heapTreeArray[iterator] << "->";
	}
	std::cout << std::endl;

	heapTreeArray = removeElement(heapTreeArray, atoi(argv[argc - 1]));
	for(int iterator = 0; iterator < heapTreeArray.size(); iterator++){
		std::cout << heapTreeArray[iterator] << "->";
	}
	std::cout << std::endl;

	return 0;
}