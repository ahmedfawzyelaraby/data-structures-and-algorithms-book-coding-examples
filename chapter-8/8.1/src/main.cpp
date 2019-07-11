#include <iostream>
#include <stdlib.h>
#include <vector>

int main(int argc, char** argv){
	if(argc <= 1){
		std::cout << "Invalid input" << std::endl;
	}

	std::vector<int> arrayToSort;
	for(int iterator = 1; iterator < argc; iterator++){
		arrayToSort.push_back(atoi(argv[iterator]));
	}

	for(int outerIterator = 0; outerIterator < arrayToSort.size(); outerIterator++){
		for(int innerIterator = 0; innerIterator < arrayToSort.size(); innerIterator++){
			if(arrayToSort[innerIterator] > arrayToSort[outerIterator]){
				int tempValue = arrayToSort[innerIterator];
				arrayToSort[innerIterator] = arrayToSort[outerIterator];
				arrayToSort[outerIterator] = tempValue;
			}
		}
	}

	for(int iterator = 0; iterator < arrayToSort.size(); iterator++){
		std::cout << arrayToSort[iterator] << "->";
	}
	std::cout << std::endl;

	return 0;
}