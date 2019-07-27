#include <iostream>
#include <stdlib.h>

bool isPrimary(int checkNumber){
	for(int i = 2; i < checkNumber; i++){
		for(int j = 1; j < checkNumber; j++){
			if((i * j) == checkNumber)
				return false;
		}
	}

	return true;
}

int main(int argc, char** argv){
	if(argc <= 1){
		std::cout << "Invalid input" << std::endl;
	}

	std::cout << "Number is primary status: " << isPrimary(atoi(argv[1])) << std::endl;

	return 0;
}