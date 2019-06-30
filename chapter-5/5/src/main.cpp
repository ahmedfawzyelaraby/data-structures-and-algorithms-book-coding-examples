#include <iostream>
#include <stdlib.h>
#include <map>

int main(int argc, char** argv){
	if(argc <= 1){
		std::cout << "Invalid input" << std::endl;
	}

	std::map<int, bool> setHashMap1;
	for(int iterator = 1; iterator < (argc/2); iterator++){
		setHashMap1.insert(std::pair<int, bool>(atoi(argv[iterator]), true));
	}

	std::map<int, bool> setHashMap2;
	for(int iterator = (argc/2); iterator < argc; iterator++){
		setHashMap2.insert(std::pair<int, bool>(atoi(argv[iterator]), true));
	}

	// Union
	std::map<int, bool> unionSet;
	for(std::map<int, bool>::iterator setIterator = setHashMap1.begin(); setIterator != setHashMap1.end(); setIterator++)
		unionSet.insert(std::pair<int, bool>(setIterator->first, true));
	for(std::map<int, bool>::iterator setIterator = setHashMap2.begin(); setIterator != setHashMap2.end(); setIterator++)
		unionSet.insert(std::pair<int, bool>(setIterator->first, true));
	for(std::map<int, bool>::iterator setIterator = unionSet.begin(); setIterator != unionSet.end(); setIterator++)
		std::cout << setIterator->first << "->";
	std::cout << std::endl;

	// Intersection
	std::map<int, bool> intersectionSet;
	std::map<int, bool> smallerSet;
	if(setHashMap1.size() < setHashMap2.size())
		smallerSet = setHashMap1;
	else
		smallerSet = setHashMap2;
	for(std::map<int, bool>::iterator setIterator = smallerSet.begin(); setIterator != smallerSet.end(); setIterator++){
		std::map<int, bool>::iterator searchIterator1 = setHashMap1.find(setIterator->first);
		std::map<int, bool>::iterator searchIterator2 = setHashMap2.find(setIterator->first);
		if((searchIterator1 != setHashMap1.end()) && (searchIterator2 != setHashMap2.end()))
			intersectionSet.insert(std::pair<int, bool>(setIterator->first, true));
	}
	for(std::map<int, bool>::iterator setIterator = intersectionSet.begin(); setIterator != intersectionSet.end(); setIterator++)
		std::cout << setIterator->first << "->";
	std::cout << std::endl;

	return 0;
}