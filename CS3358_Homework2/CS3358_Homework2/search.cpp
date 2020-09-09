#include "pch.h"
#include "search.h"

// Written by Matthew Hebert
// Description:
// Performs a linear search for a number in a list
// Parameters:
// list the set of numbers
// length the number of elements in the set of numbers
// n the number to be found
// Returns: 
// the index of the number in the set on successful execution
// -1 when number not found
/****
* PSEUDOCODE:
* for i in list
*   if list at i equals the number
*     return i
* return -1
*/
int LinearSearch(int list[], int length, int n)  {
	
	// find the element with the value n in list and return it's index
	for (int i = 0; i < length; i++)  {
		if (list[i] == n)
			return i;
	}

	// if not found, return -1
	return -1;
}

// Written by Matthew Hebert
// Description:
// Performs a binary search for a number in a list
// Parameters:
// list the set of numbers
// length the number of elements in the set of numbers
// n the number to be found
// Returns: 
// the index of the number in the set on successful execution
// -1 when number not found
/****
* PSEUDOCODE:
*
* halfway = top/2 assuming the low is always 0
* 
* while number is not found
*	if number is the number at halfway
*	  return halfway
*
*   else if halfway is out of bounds
*	  return -1
*
*   else if number is higher than number at halfway
*	  bottom = halfway
*	  halfway = bottom + (top-bottom)/2
*
*   else if number is lower than number at halfway
*	  top = halfway
*	  halfway = top - (top-bottom)/2
*
*/
int BinarySearch(int list[], int length, int n)  {
	bool searching = true;
	
	// initialize boundary variables
	int half_way = length / 2,
		top = length - 1,
		bottom = 0;

	while(searching)  {
		if (list[half_way] == n)  {  // if n was found, return it's index
			return half_way;
		} else if (half_way <= 0 || half_way >= length - 1)  {  // if out of bounds, return -1
			searching = false;
		} else if (list[half_way] < n)  {  // if n > list[half_way], adjust boundary variables
			bottom = half_way;
			half_way += (top - bottom) / 2;
		} else if (list[half_way] > n)  {  // if n < list[half_way], adjust boundary variables
			top = half_way;
			half_way -= (top - bottom) / 2;
		}
	}

	return -1;
}

