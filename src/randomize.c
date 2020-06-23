/** 
 * @file randomize.c
 * @author Pavan Patel
 * @date 22 June 2020
 * @brief Incorporates randomness in the quiz.
 */

#include "..\include\randomize.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/**
* @brief The randomize function which change the order of elements in array.
* @author Pavan Patel
* The funtion will take any element on random basis and pass to swap() function.
* Two of these element will swap each other place and loop continues untill all elements are swapped 
* and this data will be changed every time whenever user takes quiz.
* @param[in] arr[] integer array
* @param[in] n No of elements in array
*
*/
void randomize(int arr[], int n) {
    srand(time(NULL));
    int i;
    for(i = n-1; i > 0; i--) {
        int j = rand() % (i+1);
        swap(&arr[i], &arr[j]);
    }
}

