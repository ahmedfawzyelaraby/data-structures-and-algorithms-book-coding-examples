#include <iostream>
#include <stdlib.h>
#include <vector>

std::vector<int> mergeOrderedList(std::vector<int> leftArrayToMerge, std::vector<int> rightArrayToMerge){
	int leftCounter = 0;
	int rightCounter = 0;
	std::vector<int> mergedSortedArray;
	while((leftCounter < leftArrayToMerge.size()) && (rightCounter < rightArrayToMerge.size())){
		if(leftArrayToMerge[leftCounter] < rightArrayToMerge[rightCounter]){
			mergedSortedArray.push_back(leftArrayToMerge[leftCounter]);
			leftCounter++;
		}else{
			mergedSortedArray.push_back(rightArrayToMerge[rightCounter]);
			rightCounter++;
		}
	}

	while(leftCounter < leftArrayToMerge.size()){
		mergedSortedArray.push_back(leftArrayToMerge[leftCounter]);
		leftCounter++;
	}

	while(rightCounter < rightArrayToMerge.size()){
		mergedSortedArray.push_back(rightArrayToMerge[rightCounter]);
		rightCounter++;
	}

	return mergedSortedArray;
}

std::vector<int> mergeSort(std::vector<int> inputArrayToSort){
	if(inputArrayToSort.size() <= 1)
		return inputArrayToSort;

	std::vector<int> leftArray(inputArrayToSort.begin(), inputArrayToSort.begin() + (inputArrayToSort.size()/2));
	std::vector<int> rightArray(inputArrayToSort.begin() + (inputArrayToSort.size()/2), inputArrayToSort.end());
	leftArray = mergeSort(leftArray);
	rightArray = mergeSort(rightArray);

	return mergeOrderedList(leftArray, rightArray);
}

int main(int argc, char** argv){
	if(argc <= 1){
		std::cout << "Invalid input" << std::endl;
	}

	std::vector<int> arrayToSort;
	for(int iterator = 1; iterator < argc; iterator++){
		arrayToSort.push_back(atoi(argv[iterator]));
	}

	arrayToSort = mergeSort(arrayToSort);

	for(int iterator = 0; iterator < arrayToSort.size(); iterator++){
		std::cout << arrayToSort[iterator] << "->";
	}
	std::cout << std::endl;

	return 0;
}