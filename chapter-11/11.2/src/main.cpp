#include <iostream>
#include <string>

bool checkPalindrome(std::string input){
    int left = 0;
    int right = input.length() - 1;
    while((input[left] == input[right]) && (left < right)){
        left++;
        right--;
    }
    return (input[left] == input[right]);
}

int main(int argc, char** argv){
    if(argc <= 1){
		std::cout << "Invalid input" << std::endl;
	}

    std::string input(argv[1]);
    std::cout << checkPalindrome(input) << std::endl;
}