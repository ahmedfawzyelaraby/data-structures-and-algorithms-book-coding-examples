#include <iostream>
#include <string>

int charMatchPosition(std::string word1, std::string word2){
    char whiteSpace = ' ';

    for(int i = 0; i < word1.length(); i++){
        if(word1[i] != whiteSpace){
            for(int j = 0; j < word2.length(); j++){
                if(word1[i] == word2[j])
                    return j;
            }
        }
    }

    return -1;
}

int main(int argc, char** argv){
    if(argc <= 2){
		std::cout << "Invalid input" << std::endl;
	}

    std::string input1(argv[1]);
    std::string input2(argv[2]);

    std::cout << charMatchPosition(input1, input2) << std::endl;
}