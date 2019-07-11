#include <iostream>
#include <stdlib.h>
#include <vector>

std::vector<int> quickSort(std::vector<int> inputArrayToSort){
	if(inputArrayToSort.size() <= 1)
		return inputArrayToSort;

	int pivot = inputArrayToSort[inputArrayToSort.size() - 1];
	std::vector<int> lessThanPivot;
	std::vector<int> moreThanPivot;
	std::vector<int> equalToPivot;
	for(int iterator = 0; iterator < inputArrayToSort.size(); iterator++){
		if(inputArrayToSort[iterator] < pivot)
			lessThanPivot.push_back(inputArrayToSort[iterator]);
		else if(inputArrayToSort[iterator] > pivot)
			moreThanPivot.push_back(inputArrayToSort[iterator]);
		else
			equalToPivot.push_back(inputArrayToSort[iterator]);
	}

	lessThanPivot = quickSort(lessThanPivot);
	moreThanPivot = quickSort(moreThanPivot);
	
	std::vector<int> mergedArray(lessThanPivot.begin(), lessThanPivot.end());
	mergedArray.insert(mergedArray.end(), equalToPivot.begin(), equalToPivot.end());
	mergedArray.insert(mergedArray.end(), moreThanPivot.begin(), moreThanPivot.end());
	return mergedArray;
}

int main(int argc, char** argv){
	if(argc <= 1){
		std::cout << "Invalid input" << std::endl;
	}

	std::vector<int> arrayToSort;
	for(int iterator = 1; iterator < argc; iterator++){
		arrayToSort.push_back(atoi(argv[iterator]));
	}

	arrayToSort = quickSort(arrayToSort);

	for(int iterator = 0; iterator < arrayToSort.size(); iterator++){
		std::cout << arrayToSort[iterator] << "->";
	}
	std::cout << std::endl;

	return 0;
}