#include <iostream>
#include <stdlib.h>
#include <vector>

int getMax(std::vector<int> inputArrayToGetMax){
	int maxValue = inputArrayToGetMax[0];
	for(int iterator = 1; iterator < inputArrayToGetMax.size(); iterator++){
		if(inputArrayToGetMax[iterator] > maxValue)
			maxValue = inputArrayToGetMax[iterator];
	}

	return maxValue;
}

std::vector<int> countSort(std::vector<int> inputArrayToSort, int inputRadix){
	int sortedArray[inputArrayToSort.size()];
	int occuranceArray[10] = {0};

	for(int iterator = 0; iterator < inputArrayToSort.size(); iterator++)
		occuranceArray[(inputArrayToSort[iterator]/inputRadix)%10]++;

	for(int iterator = 1; iterator < 10; iterator++)
		occuranceArray[iterator] += occuranceArray[iterator - 1];

	for(int iterator = inputArrayToSort.size() - 1; iterator >= 0; iterator--){
		sortedArray[occuranceArray[(inputArrayToSort[iterator] / inputRadix) % 10] - 1] = inputArrayToSort[iterator];
		occuranceArray[(inputArrayToSort[iterator] / inputRadix) % 10]--;
	}

	for(int iterator = 0; iterator < inputArrayToSort.size(); iterator++)
		inputArrayToSort[iterator] = sortedArray[iterator];

	return inputArrayToSort;
}

std::vector<int> radixSort(std::vector<int> inputArrayToSort){
	int maxArrayValue = getMax(inputArrayToSort);

	for(int radix = 1; (maxArrayValue/radix) > 0; radix *= 10){
		inputArrayToSort = countSort(inputArrayToSort, radix);
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

	arrayToSort = radixSort(arrayToSort);

	for(int iterator = 0; iterator < arrayToSort.size(); iterator++){
		std::cout << arrayToSort[iterator] << "->";
	}
	std::cout << std::endl;

	return 0;
}