#include "pch.h"
#include "nth_root_finder.h"

// Written by Matthew Hebert
// Description:
// Finds the nth root of a positive number by BRUTE FORCE
// Parameters:
// number the number to be rooted (ASSUMED TO BE POSITIVE)
// n the nth root
// precision the precision of the floating point output
// Returns: 
// the root of the number with input precision
// Notes:
// It would be easy to allow this function to be used for negative numbers.
// This was not specified so it was not done.
// For negative numbers, we would find the nth root of the it's absolute value.
// If n is odd, put a negative sign in front of the root in the string that is returned. 
// Else, multiply the root by i (imaginary number) in the string that is returned.
/****
* PSEUDOCODE:
* 
* increment = 1^(-1*precision) 
*
* while root^n < number
*   root = root + increment
*   multiplier = 1.0
*
*   for n times (to get root^n)
*     root^n = multiplier * root
*     multiplier = root^n
*   
* return root (with precision defining # of zeros after decimal) as a string
*/
std::string FindNthRoot(int number, int n, int precision)  {
	double root_to_n = 0.0;
	double increment = 1.0;
	
	// find minimum increment for the root
	for (int i = 0; i < precision; i++)  {
		increment *= 0.1;
	}
	
	// Find the root by incrementing it by the minimum increment and 
	// putting it to the power n. Escape loop on last iteration before root^n = number.
	double root = 1.0;
	while (root_to_n < number)  {
		root += increment;
		root_to_n = 1.0;

		for (int j = 0; j < n; j++)  {
			root_to_n *= root;
		}
	}

	// print parameters
	printf("\nRoot %d of %d with precision %d is: ", n, number, precision);
	
	// format output based off of precision parameter
	std::string output = std::to_string(root);
	output = output.substr(0, output.find('.')+precision+1);
	
	// return the root as a string
	return output;
}

