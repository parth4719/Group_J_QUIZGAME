/** 
 * @file swap.c
 * @author Pavan Patel
 * @date 22 June 2020
 * @brief Executes a Swap function
 */

#include "..\include\swap.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/**
* @brief The Swap function will be used to exchange data.
* @author Pavan Patel
* The function is a part of randomize() function.
* Function will switch each other data and store the result value at each other address  
* @param[in] pointer to one of the array element
* @param[in] pointer to second array element
*
*/

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

