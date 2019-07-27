#include <iostream>
#include <stdlib.h>
#include <vector>

std::vector<int> intToBinary(int convertionInt){
	std::vector<int> resultBinary;
	while(convertionInt > 0){
		resultBinary.push_back(convertionInt % 2);
		convertionInt /= 2;
	}

	return resultBinary;
}

int main(int argc, char** argv){
	if(argc <= 1){
		std::cout << "Invalid input" << std::endl;
	}

	std::vector<int> binaryNumber = intToBinary(atoi(argv[1]));

	std::cout << "Binary Number: ";
	for(int iterator = binaryNumber.size() - 1; iterator >= 0; iterator--){
		std::cout << binaryNumber[iterator] << "->";
	}
	std::cout << std::endl;

	return 0;
}