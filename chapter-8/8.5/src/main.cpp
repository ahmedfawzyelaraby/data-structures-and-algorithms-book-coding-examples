#include <iostream>
#include <stdlib.h>
#include <vector>

std::vector<int> shellSort(std::vector<int> inputArrayToSort){
	int increment = inputArrayToSort.size() / 2;
	while(increment != 0){
		int current = increment;
		while(current < inputArrayToSort.size()){
			int holdingValue = inputArrayToSort[current];
			int counter = current - increment;
			while((counter >= 0) && (holdingValue < inputArrayToSort[counter])){
				inputArrayToSort[counter + increment] = inputArrayToSort[counter];
				counter -= increment;
			}
			inputArrayToSort[counter + increment] = holdingValue;
			current++;
		}
		increment /= 2;
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

	arrayToSort = shellSort(arrayToSort);

	for(int iterator = 0; iterator < arrayToSort.size(); iterator++){
		std::cout << arrayToSort[iterator] << "->";
	}
	std::cout << std::endl;

	return 0;
}