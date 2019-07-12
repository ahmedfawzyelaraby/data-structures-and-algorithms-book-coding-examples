#include <iostream>
#include <stdlib.h>
#include <vector>

std::vector<int> insertionSort(std::vector<int> inputArrayToSort){
	for(int iterator = 1; iterator < inputArrayToSort.size(); iterator++){
		int holdingValue = inputArrayToSort[iterator];
		int counter = iterator - 1;
		while((counter >= 0) && (inputArrayToSort[counter] > holdingValue)){
			inputArrayToSort[counter + 1] = inputArrayToSort[counter];
			counter--;
		}
		inputArrayToSort[counter + 1] = holdingValue;
	}

	return inputArrayToSort;
}

int main(int argc, char** argv){
	if(argc <= 1){
		std::cout << "Invalid input" << std::endl;
	}

	std::vector<int> arrayToSort;
	for(int iterator = 1; iterator < argc; iterator++){
		arrayToSort.push_back(atoi(argv[iterator]));
	}

	arrayToSort = insertionSort(arrayToSort);

	for(int iterator = 1; iterator < arrayToSort.size(); iterator++){
		std::cout << arrayToSort[iterator] << "->";
	}
	std::cout << std::endl;

	return 0;
}