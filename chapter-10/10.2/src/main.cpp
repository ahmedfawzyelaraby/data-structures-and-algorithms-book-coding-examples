#include <iostream>
#include <stdlib.h>
#include <vector>

int probabilitySearch(std::vector<int>& list, int numberToSearch){
	int iterator = 0;
	while((iterator < list.size()) && (list[iterator] != numberToSearch))
		iterator++;
	
	if((iterator >= list.size()) || (list[iterator] != numberToSearch))
		return -1;

	if(iterator > 0){
		int tmp = list[iterator];
		list[iterator] = list[iterator - 1];
		list[iterator - 1] = tmp;
		iterator--;
	}

	return iterator;
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
		<< probabilitySearch(vectorToSearchIn, atoi(argv[argc - 1])) << std::endl;

	return 0;
}