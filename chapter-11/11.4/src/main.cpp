#include <iostream>
#include <string>
#include <map>

int countRepeatedWords(std::string input){
    bool inWord = true;
    int wordCount = 0;
    int index = 0;
    char whiteSpace = ' ';

    while((input[index] == whiteSpace) && (index < input.length()))
        index++;
    
    if(index == input.length())
        return wordCount;
    
    int start = index;
    int end = index;
    std::map <std::string, int> uniqueWords;

    while(index < input.length()){
        if(input[index] == whiteSpace){
            end = index;
            std::cout << input.substr(start, end - start) << std::endl;
            uniqueWords[input.substr(start, end - start)] = 1;

            while((input[index] == whiteSpace) && (index < input.length()))
                index++;
            
            start = index;
            inWord = false;
            wordCount++;
        }else{
            inWord = true;
        }
        index++;
    }

    if(inWord){
        end = input.length();
        std::cout << input.substr(start, end - start) << std::endl;
        uniqueWords[input.substr(start, end - start)] = 1;
        wordCount++;
    }

    return (wordCount - uniqueWords.size());
}

int main(int argc, char** argv){
    if(argc <= 1){
		std::cout << "Invalid input" << std::endl;
	}

    std::string input(argv[1]);
    std::cout << input << std::endl;
    std::cout << countRepeatedWords(input) << std::endl;
}