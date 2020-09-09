#include "pch.h"
#include <string>
#include <iostream>
#include <map>
using namespace std;

// Written by Matthew Hebert
// Description:
// Finds the minimum word length from a list of words
// Parameters:
// words the list of words
// length the number of elements in the list of words
// Returns: 
// the Minimum Word Length on successful execution
// -1 on unsuccessful execution
/****
* PSEUDOCODE:
* 
* set min_length as length of first word
*
* foreach word in words
*   if word.length < min_length
*     min_length = word.length
* 
* return min_length
*/
int MinWordLength(std::string words[], int length) {
	// TODO implement this function
	int min_length;
	try  {
		// initalize min_length
		min_length = words[0].length();

		// find min word length in words
		for (int i = 1; i < length; i++) {
			if (words[i].length() < min_length)
				min_length = words[i].length();
		}

		// return the min word length
		return min_length;

		throw "Unsupported Operation";
	} catch (const char* error)  {
		std::cout << error << " Exception thrown From MinWordLength" << std::endl;
		return -1;
	}
}

// Written by Matthew Hebert
// Description:
// Finds the maximum word length from a list of words
// Parameters:
// words the list of words
// length the number of elements in the list of words
// Returns: 
// the maximum word length on successful execution
// -1 on unsuccessful execution
/****
* PSEUDOCODE:
*
* set max_length as length of first word
*
* foreach word in words
*   if word.length > max_length
*     max_length = word.length
*
* return max_length
*/
int MaxWordLength(std::string words[], int length) {
	// TODO implement this function
	//throw "Unsupported Operation";
	int max_length;
	try  {

		// initialize max_length
		max_length = words[0].length();

		// find the max word length in words
		for (int i = 1; i < length; i++) {
			if (words[i].length() > max_length)
				max_length = words[i].length();
		}

		// return the max word length
		return max_length;

		throw "Unsupported Operation";
	} catch (const char* error)  {
		std::cout << error << " From MaxWordLength" << std::endl;
		return -1;
	}

}

// Written by Matthew Hebert
// Description:
// Finds the word length range from a list of words
// Parameters:
// words the list of words
// length the number of elements in the list of words
// Returns: 
// the word length range on successful execution
// -1 on unsuccessful execution
/****
* PSEUDOCODE:
*
* set min_length as first word
* set max_length as first word
*
* foreach word in words
*   if word.length < min_length
*     min_length = word.length
*   if word.length > max_length
*     max_length = word.length
*
* return max_length - min_length
*/
int WordLengthRange(std::string words[], int length) {
	// TODO implement this function
	int range;
	
	try  {
		// calculate the range
		range = MaxWordLength(words, length) - MinWordLength(words, length);

		// return the range
		return range;

		throw "Unsupported Operation";
	} catch (const char* error)  {
		std::cout << error << " From MinWordLength" << std::endl;
		return -1;
	}

}

// Written by Matthew Hebert
// Description:
// Finds the average word length from a list of words
// Parameters:
// words the list of words
// length the number of elements in the list of words
// Returns: 
// the average Word Length on successful execution
// -1 on unsuccessful execution
/****
* PSEUDOCODE:
*
* set sum to 0
*
* for each word in words
*   increment sum by word.length
*
* set avg_length to sum / length (where length is number of words)
* return avg_length
*/
int AverageWordLength(std::string words[], int length) {
	// TODO implement this function
	
	// initialize sum
	int sum = 0, avg_length;
	
	try  {
		// perform summation of word lengths
		for (int i = 0; i < length; i++)  {
			sum += words[i].length();
		}
		
		// find the average length
		avg_length = sum / length;

		// return the average length
		return avg_length;
		throw "Unsupported Operation";
	} catch (const char* error)  {
		std::cout << error << " From AverageWordLength" << std::endl;
		return -1;
	}

}

// Written by Matthew Hebert
// Description:
// Finds the most common (mode) word length from a list of words
// Parameters:
// words the list of words
// length the number of elements in the list of words
// Returns: 
// the most common (mode) Word Length on successful execution
// -1 on unsuccessful execution
/****
* PSEUDOCODE:
*
* create a map word_length_map with word length as the key and number times occured as the value
* create a pair word_length_mode with word length as the key and number times occured as the value
*
* foreach word in words
*   if word.length is in word_length_map
*	  increment the value at that word.length in the word_length_map
*   else
*     add the length to word_length_map
*
* set word_length_mode to the pair with key word[0].length in word_length_map 
*
* foreach pair in word_length_map
*   if the pair value > word_length_mode value
*	  word_length_mode = pair
*
* return word_length_mode key
*/
int MostCommonWordLength(std::string words[], int length) {

	std::map<int, int> word_length_map;
	std::pair<int, int> word_length_mode;

	try {
		// fill word_length_map with keys and values
		for (int i = 0; i < length; i++) {
			if (word_length_map.find(words[i].length()) != word_length_map.end()) {
				word_length_map.at(words[i].length())++;
			} else  {
				word_length_map.insert(std::pair<int, int>(words[i].length(), 1));
			}
		}
		
		// initialize word_length_mode
		word_length_mode = std::pair<int, int>(words[0].length(), word_length_map.at(words[0].length()));

		// find word length that occurs the most
		for (std::map<int, int>::iterator i = word_length_map.begin(); i != word_length_map.end(); i++) {
			if (i->second > word_length_mode.second) {
				word_length_mode = std::pair<int, int>(i->first, i->second);
			}
		}

		// return the length that occurs the most
		return word_length_mode.first;

		throw "Unsupported Operation";
	}
	catch (const char* error) {
		std::cout << error << " From MostCommonWordLength" << std::endl;
		return -1;
	}
}

// Written by Matthew Hebert
// Description:
// Finds the most common (mode) word from a list of words
// Parameters:
// words the list of words
// length the number of elements in the list of words
// Returns: 
// the most common word (mode) on successful execution
// -1 on unsuccessful execution
/****
* PSEUDOCODE:
*
* create a map word_map with word as the key and number times occured as the value
* create a pair word_mode with word as the key and number times occured as the value
*
* foreach word in words
*   if word is in word_length_map
*	  increment the value at that word in the word_map
*   else
*     add the word to word_length_map
*
* set word_mode to the pair with key word[0] in word_map
*
* foreach pair in word_map
*   if the pair value > word_mode value
*	  word_mode = pair
*
* return word_mode key
*/
std::string MostCommonWord(std::string words[], int length) {
	// TODO implement this function
	
	std::map<std::string, int> word_map;
	std::pair<std::string, int> word_mode;
	std::string output;// = "The most common word is: ";

	try  {
		// fill word_map with keys and values
		for(int i = 0; i < length; i++)  {
			if(word_map.find(words[i]) != word_map.end())  {
				word_map.at(words[i])++;
			} else  {
				word_map.insert(std::pair<std::string, int>(words[i], 1));
			}
		}
		
		// initialize word_mode
		word_mode = std::pair<std::string, int>(words[0], word_map.at(words[0]));

		// find word that occurs the most
		for (std::map<std::string, int>::iterator i = word_map.begin(); i != word_map.end(); i++)  {
			if (i->second > word_mode.second)  {
				word_mode = std::pair<std::string, int>(i->first, i->second);
			}
		}

		// return the word that occurs the most
		//output.append(word_mode.first);
		output = word_mode.first;
		return output;
		
		throw "Unsupported Operation";
	} catch (const char* error) {
		std::cout << error << " From MostCommonWordLength" << std::endl;
		return "-1";
	}
	
}