#include <iostream>
#include <stdlib.h>

int greatestCommonDenominator(int input1, int input2){
	if (input2 == 0)
		return input1;

	return greatestCommonDenominator(input2, input1 % input2);
}

int main(int argc, char** argv){
	if(argc <= 1){
		std::cout << "Invalid input" << std::endl;
	}

	std::cout << "Greatest Common Denominator of " <<
		atoi(argv[1]) << " and " << atoi(argv[2]) << " is: " <<
		greatestCommonDenominator(atoi(argv[1]), atoi(argv[2])) << std::endl;

	return 0;
}