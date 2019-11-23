#include <iostream>
#include <stdlib.h>
#include <string>

std::string reverseWords(std::string inString){
	std::string result = "";
	char whiteSpace = ' ';

	int last = inString.length();
	int start = last;

	while(last >= 0){
		while((start >= 0) && (inString[start] == whiteSpace))
			start--;
		
		last = start;

		while((start >= 0) && (inString[start] != whiteSpace))
			start--;
		
		for(int i = start + 1; i <= last; i++)
			result += inString[i];
		
		if(start > 0)
			result += whiteSpace;
		
		last = start - 1;
		start = last;
	}

	if(result[result.length() - 1] == whiteSpace)
		result = result.substr(0, result.length() - 1);

	return result;
}

int main(int argc, char** argv){
	std::string ourString = "I want to reverse this string sentence";

	std::cout << reverseWords(ourString) << std::endl;

	return 0;
}