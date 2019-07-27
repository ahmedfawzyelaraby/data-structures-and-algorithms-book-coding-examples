#include <iostream>
#include <stdlib.h>

unsigned long long factorial(int inputNumber){
	if (inputNumber < 2)
		return 1;

	long factorial = 1;
	for(int iterator = 2; iterator <= inputNumber; iterator++){
		factorial *= iterator;
	}

	return factorial;
}

int main(int argc, char** argv){
	if(argc <= 1){
		std::cout << "Invalid input" << std::endl;
	}

	std::cout << "Factorial of " << atoi(argv[1]) << " is: " <<
		factorial(atoi(argv[1])) << std::endl;

	return 0;
}