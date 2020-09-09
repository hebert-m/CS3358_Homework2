// CS3358_Homework2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "search.h"
#include "dictionary.h"
#include "nth_root_finder.h"
#include <iostream>

void TestDictionary();

int main() {
	int list[] = { 1,2,4,5,6,7,8,9 };
	int array_length = 8;
	int number = 6;

	std::cout << "Linear Search: " << LinearSearch(list, array_length, number) << std::endl;

	std::cout << "Binar Search: " << BinarySearch(list, array_length, number) << std::endl;

	printf("\nTesting dictionary.h:\n");
	TestDictionary();

	printf("\nTesting nth_root_finder.h:\n");
	std::cout << FindNthRoot(62, 4, 5);

	return 0;
}

// Written by Matthew Hebert
// Description:
// Calls all of the funcitions in dictionary.h
// Parameters:
// none
// Returns: 
// none
/****
* PSEUDOCODE:
*
* create array of words
*
* call MinWordLength
* call MaxWordLength
* call WordLengthRange
* call AverageWordLength
* call MostCommonWordLength
* call MostCommonWord
*
*/
void TestDictionary()  {
	std::string words[] = { "test", "word", "bank", "using", "the", 
							"dictionary", "header", "file", "test" };
	int length = 9;
	
	std::cout << "The minimum word length is: " << MinWordLength(words, length) << std::endl;
	
	std::cout << "The maximum word length is: " << MaxWordLength(words, length) << std::endl;

	std::cout << "The range of word length is: " << WordLengthRange(words, length) << std::endl;

	std::cout << "The average word length is: " << AverageWordLength(words, length) << std::endl;

	std::cout << "The most common word length is: " << MostCommonWordLength(words, length) << std::endl;

	std::cout << "The most common word is: " << MostCommonWord(words, length) << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
