#include <iostream>
#include <string>

int countWords(std::string input){
    bool inWord = true;
    int wordCount = 0;
    int index = 0;
    char whiteSpace = ' ';

    while((input[index] == whiteSpace) && (index < input.length()))
        index++;
    
    if(index == input.length())
        return wordCount;
    
    while(index < input.length()){
        if(input[index] == whiteSpace){
            while((input[index] == whiteSpace) && (index < input.length()))
                index++;
            
            inWord = true;
            wordCount++;
        }else{
            inWord = true;
        }
        index++;
    }

    if(inWord)
        wordCount++;

    return wordCount;
}

int main(int argc, char** argv){
    if(argc <= 1){
		std::cout << "Invalid input" << std::endl;
	}

    std::string input(argv[1]);
    std::cout << input << std::endl;
    std::cout << countWords(input) << std::endl;
}