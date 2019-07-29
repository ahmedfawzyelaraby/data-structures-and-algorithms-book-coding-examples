#include <iostream>
#include <stdlib.h>
#include <vector>

int sequentialSearch(std::vector<int> list, int numberToSearch){
	for(int iterator = 0; iterator < list.size(); iterator++){
		if(numberToSearch == list[iterator])
			return iterator;
	}

	return -1;
}

int main(int argc, char** argv){
	if(argc <= 1){
		std::cout << "Invalid input" << std::endl;
	}

	std::vector<int> vectorToSearchIn;
	for(int iterator = 1; iterator < (argc - 1); iterator++){
		vectorToSearchIn.push_back(atoi(argv[iterator]));
	}
	std::cout << "The element " << atoi(argv[argc - 1]) << " is found at position: "
		<< sequentialSearch(vectorToSearchIn, atoi(argv[argc - 1])) << std::endl;

	return 0;
}