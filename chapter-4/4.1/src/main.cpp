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

int main(int argc, char** argv){
	if(argc <= 1){
		std::cout << "Invalid input" << std::endl;
	}

	std::vector<int> heapTreeArray;
	for(int iterator = 1; iterator < argc; iterator++){
		heapTreeArray.push_back(atoi(argv[iterator]));
		heapTreeArray = minHeapify(heapTreeArray);
	}

	for(int iterator = 0; iterator < heapTreeArray.size(); iterator++){
		std::cout << heapTreeArray[iterator] << "->";
	}
	std::cout << std::endl;

	return 0;
}