// DailyProgrammer1.cpp : Defines the entry point for the console application.
//
/*In this challenge, we are going to take a sentence and mangle it up by sorting the letters in each word. 
So, for instance, if you take the word "hello" and sort the letters in it, you get "ehllo". If you take the 
two words "hello world", and sort the letters in each word, you get "ehllo dlorw".*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

std::string something;
char holder;

std::string DoIt(std::string lineOfText)
{
	//need to break up line into words
	std::vector<std::string> words;
	int whiteSpacePos = lineOfText.find(' ');
	std::string result = "";
	while (whiteSpacePos != std::string::npos)
	{
		std::string word = lineOfText.substr(0, whiteSpacePos);
		words.push_back(word);
		//remove from lines
		lineOfText.erase(0, whiteSpacePos + 1);
		whiteSpacePos = lineOfText.find(' ');
	}
	//check if last word is there
	if (lineOfText.length() > 0)
	{
		words.push_back(lineOfText);
	}

	//loop through words
	for (int i = 0; i < words.size(); i++)
	{
		std::string word = words[i];
		while (word.length() > 0)
		{
			//set to highest char
			char least = 'z';
			//loop through the string
			for (int i = 0; i < word.length(); i++)
			{
				//is this char less than the least found so far?
				if (word[i] < least)
				{
					least = word[i];
				}
			}
			//least is the smallest in the string
			//add it to result
			result += least;
			//remove it from search string
			word.erase(word.find(least), 1);
		}
		//if another word add a space in result
		if (i < words.size() - 1)
		{
			result += ' ';
		}
	}
	return result;
}


int _tmain(int argc, _TCHAR* argv[])
{
	std::cout << "Enter something to sort.\n";
	//only works for single word
	//std::cin >> something;

	std::getline(std::cin, something);

	std::string result = DoIt(something);
	std::cout << result << std::endl;
	


	system("pause");
}

